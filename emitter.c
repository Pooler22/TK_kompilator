#include <iomanip>
#include "global.h"
#include "inc.h"
#include "parser.h"

using namespace std;
using std::cout;
using std::setw;

extern ofstream stream;
stringstream ss;

int getResultType(int id1, int id2) {
	if (SymbolTable[id1].type == REAL || SymbolTable[id1].type == REAL) {
		return REAL;
	} else {
		return INTEGER;
	}
}

int getSymbolType(int index, bool isValue) {
	if (isValue) {
		return SymbolTable[index].type;
	}
	else { //address
		return INTEGER;
	}
}

int getToken(const char *strValIn) {
	string strVal = strValIn;
	if (strVal.compare("+") == 0) return _PLUS;
	if (strVal.compare("-") == 0) return _MINUS;
	if (strVal.compare("*") == 0) return _MUL;
	if (strVal.compare("div") == 0 || strVal.compare("/") == 0) return _DIV;
	if (strVal.compare("mod") == 0) return _MOD;
	if (strVal.compare("and") == 0) return _AND;
	if (strVal.compare("=") == 0) return _EQ;
	if (strVal.compare(">=") == 0) return _GE;
	if (strVal.compare("<=") == 0) return _LE;
	if (strVal.compare("<>") == 0) return _NE;
	if (strVal.compare(">") == 0) return _G;
	if (strVal.compare("<") == 0) return _L;
	return 0;
}

//konwertuje 2 zmienne na ten sam typ (wyższy) przekazuje dane przez referencję
void castToSameType(int &var1, bool isValueVar1, int &var2, bool isValueVar2 ) {
	int leftType = getSymbolType( var1, isValueVar1 );
	int rightType = getSymbolType( var2, isValueVar2 );

	if (leftType != rightType) {
		if (leftType == INTEGER && rightType == REAL) {
			int newLeftVar = addTempSymbol(REAL);
			writeToOutputByToken(_INTTOREAL, newLeftVar, isValueVar1, var1, isValueVar1, -1, true);
			var1 = newLeftVar;
		} else if (leftType == REAL && rightType == INTEGER) {
			int newRightVar = addTempSymbol(REAL);
			writeToOutputByToken(_INTTOREAL, newRightVar, isValueVar2, var2, isValueVar2, -1, true);
			var2 = newRightVar;
		} else {
			yyerror("Niezgodnosc typow");
		}
	}
}

//dla := ustawia identyczny typ
bool castToSameTypeForAssign(int resultVar, bool isValueResult, int rightVar, bool isValueRight) {
	int resultType = getSymbolType(resultVar, isValueResult);
	int rightType = getSymbolType(rightVar, isValueRight);

	if (resultType == rightType) {
		return false;
	} else {
		if (resultType == INTEGER && rightType == REAL) {
			writeToOutputByToken(_REALTOINT, resultVar, isValueResult, rightVar, isValueRight, -1, true);
			return true;
		}
		else if (resultType == REAL && rightType == INTEGER) {
			writeToOutputByToken(_INTTOREAL, resultVar, isValueResult, rightVar, isValueRight, -1, true);
			return true;
		}
		else {
			yyerror("Niezgodnosc typow przy :=");
			return false;
		}
	}
}

void writeVariableExt(int index){
	if (!SymbolTable[index].isGlobal) {
		ss << "BP";
		if (SymbolTable[index].address >= 0) {
			ss << "+";
		}
	} 
	ss << SymbolTable[index].address;
}

//wypisuje pojedyńczą zmienną dostosowywuje znak referencji, wartości, BP
void writeVariable(int index, bool isValue) {
	//jeżeli do wypisania jest liczba poprzedza ją znakiem # i wypisuje
	if (SymbolTable[index].token == NUM) {
		ss << "#" << SymbolTable[index].name;
	}
    //Jeżeli mamy do czynienia z referencją i trzeba wyłuskać adres
	else if (SymbolTable[index].isReference) {
		if (isValue) {
			ss << "*";
		}
		writeVariableExt(index);
	}
    //Jeżeli mamy do czynienia ze zeminna/tablicą
	else if (SymbolTable[index].token == VAR || SymbolTable[index].token == ARRAY) {
		if (!isValue) {
			ss << "#";
		}
		writeVariableExt(index);
	} else {
		yyerror("Nieprawidłowy typ");
	}
}

//generuje kod dla prawie wszystkiego
void writeToOutputByToken(int operand, int resultVar, bool isValueResult, int leftVar, bool isValueLeft, int rightVar, bool isValueRight) {
    string operationType;

	if (resultVar != -1) {
		if (SymbolTable[resultVar].type == REAL) {
			operationType = ".r ";
		}
		else{
            operationType = ".i ";
        }
	}

	if (operand == _RETURN) {
		ss << "\n        return                          ;return  ";
		string res;
		//zawartość srtingstreama do stringa
		res = ss.str();
		ss.str(string());//czyszczenie bo jest w res
		size_t pos = res.find("??");
		ss << "#" << -1 * getSymbolAddress(string(""));
		res.replace(pos, 2, ss.str());
		stream.write(res.c_str(), res.size());
		ss.str(string());
	} 
	else if (operand >= _EQ && operand <= _L) {
		castToSameType(leftVar, isValueLeft, rightVar, isValueRight);
		operationType = ".i ";
		if (SymbolTable[leftVar].type == REAL)
			operationType = ".r ";
		ss << "\n        ";
		if (operand == _EQ) ss << "je";
		else if (operand == _NE) ss << "jne";
		else if (operand == _LE) ss << "jle";
		else if (operand == _GE) ss << "jge";
		else if (operand == _G) ss << "jg";
		else if (operand == _L) ss << "jl";
		ss << operationType << "   ";

		writeVariable(leftVar, isValueLeft);
		ss << ",";
		writeVariable(rightVar, isValueRight);
		ss << "," << "#" << SymbolTable[resultVar].name;
	} 
	else if (operand == PROC || operand == FUN) {
		ss << "\n" << SymbolTable[resultVar].name << ":";
		ss << "\n        enter.i ??";
	} 
	else if (operand == _LABEL) {
		ss << "\n" << SymbolTable[resultVar].name << ":";
	} 
	else if (operand == _PUSH) {
		ss << "\n        push.i ";
		writeVariable(resultVar, isValueResult);
	} 
	else if (operand == _INCSP) {
		ss << "\n        incsp" << operationType;
		writeVariable(resultVar, isValueResult);
		ss << "                      ;incsp.i ";
	} 
	else if (operand == _JUMP) {
		ss << "\n        jump.i  #" << SymbolTable[resultVar].name;
		ss << "                   ;jump.i  " << SymbolTable[resultVar].name;
	} 
	else if (operand == _CALL) {
		ss << "\n        call.i  #" << SymbolTable[resultVar].name;
	} 
	else if (operand == _READ) {
		ss << "\n        read" << operationType;
		writeVariable(resultVar, isValueResult);
	} 
	else if (operand == _WRITE) {
		ss << "\n        write" << operationType;
		writeVariable(resultVar, isValueResult);
	} 
	else if (operand == _REALTOINT) {
		ss << "\n        realtoint.r ";
		writeVariable(leftVar, isValueLeft);
		ss << ",";
		writeVariable(resultVar, isValueResult);
	} 
	else if (operand == ASSIGN) {
		bool setSuccess = castToSameTypeForAssign(resultVar, isValueResult, rightVar, isValueRight);
		if (setSuccess) {
			return;
		} else {//jeżeli są tych samych typów jak były innych to funkcja castToSameTypeForAssign już przy konwersji je tam przepisała taka automatyzacja ;p
			ss << "\n        mov" << operationType << "  ";
			writeVariable(rightVar, isValueRight);
			ss << ",";
			writeVariable(resultVar, isValueResult);
		}
	}
	else if (operand == _PLUS || operand == _MINUS) {
		castToSameType(leftVar, isValueLeft, rightVar, isValueRight);
		ss << "\n        ";
		if (operand == _MINUS)
			ss << "sub" << operationType;
		else if (operand == _PLUS)
			ss << "add" << operationType;
		writeVariable(leftVar, isValueLeft);
		ss << ",";
		writeVariable(rightVar, isValueRight);
		ss << ",";
		writeVariable(resultVar, isValueResult);
	}
	else if (operand == _MUL || operand == _DIV || operand == _MOD || operand == _AND || operand == OR) {
		castToSameType(leftVar, isValueLeft, rightVar, isValueRight);
		ss << "\n        ";
		if (operand == _MUL){
            ss << "mul";
        }
		else if (operand == _DIV) 
        {
            ss << "div";
        }
		else if (operand == _MOD)
        {
            ss << "mod";
        }
		else if (operand == _AND)
        {
            ss << "and";
        }
		else if (operand == OR) 
        {
            ss << "or";
        }
		ss <<operationType << "   ";
		writeVariable(leftVar, isValueLeft);
		ss << ",";
		writeVariable(rightVar, isValueRight);
		ss << ",";
		writeVariable(resultVar, isValueResult);

	} 
	else if (operand == _INTTOREAL) {
		ss << "\n        inttoreal.i ";
		writeVariable(leftVar, isValueResult);
		ss << ",";
		writeVariable(resultVar, isValueResult);
	}
}

void writeToOutput(const char *str) {
	ss << "\n" << str;
}

void writeStrToOutput(string str) {
	ss << str;
}

void writeIntToOutput(int i) {
	ss << i;
}

void writeToFile() {
	stream.write(ss.str().c_str(), ss.str().size());
	ss.str(string()); //clear
}

void writeToOutputExt(const char *str0, const char *str1, const char *str2, const char *str3, const char *str4){
	ss	<< "\n"
		<< std::setw(8) << std::left<< str0 
		<< std::setw(8) << std::left << str1 
		<< std::setw(24) << std::left<< str2 
		<< std::setw(9)<< std::left<< str3 
		<<  str4;
}

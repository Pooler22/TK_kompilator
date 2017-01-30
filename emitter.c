#include <iomanip>
#include "global.h"
#include "symbol.h"
#include "parser.h"

using namespace std;
using std::cout;
using std::setw;

extern ofstream outputStream;
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

int getToken(string strValIn) {
	string strVal = strValIn;
	if (strVal.compare("+") == 0) return PLUS;
	if (strVal.compare("-") == 0) return MINUS;
	if (strVal.compare("*") == 0) return MUL;
	if (strVal.compare("div") == 0 || strVal.compare("/") == 0) return DIV;
	if (strVal.compare("mod") == 0) return MOD;
	if (strVal.compare("and") == 0) return AND;
	if (strVal.compare("=") == 0) return EQ;
	if (strVal.compare(">=") == 0) return GE;
	if (strVal.compare("<=") == 0) return LE;
	if (strVal.compare("<>") == 0) return NE;
	if (strVal.compare(">") == 0) return G;
	if (strVal.compare("<") == 0) return L;
	return 0;
}

void castToSameType(int &var1, bool isValueVar1, int &var2, bool isValueVar2 ) {
	int leftType = getSymbolType( var1, isValueVar1 );
	int rightType = getSymbolType( var2, isValueVar2 );

	if (leftType != rightType) {
		if (leftType == INTEGER && rightType == REAL) {
			int newLeftVar = insertTempSymbol(REAL);
			writeToOutputByToken(INTTOREAL, newLeftVar, isValueVar1, var1, isValueVar1, -1, true);
			var1 = newLeftVar;
		} else if (leftType == REAL && rightType == INTEGER) {
			int newRightVar = insertTempSymbol(REAL);
			writeToOutputByToken(INTTOREAL, newRightVar, isValueVar2, var2, isValueVar2, -1, true);
			var2 = newRightVar;
		} else {
			yyerror("Niezgodnosc typow");
		}
	}
}

bool castToSameTypeForAssign(int resultVar, bool isValueResult, int rightVar, bool isValueRight) {
	int resultType = getSymbolType(resultVar, isValueResult);
	int rightType = getSymbolType(rightVar, isValueRight);

	if (resultType == rightType) {
		return false;
	} else {
		if (resultType == INTEGER && rightType == REAL) {
			writeToOutputByToken(REALTOINT, resultVar, isValueResult, rightVar, isValueRight, -1, true);
			return true;
		}
		else if (resultType == REAL && rightType == INTEGER) {
			writeToOutputByToken(INTTOREAL, resultVar, isValueResult, rightVar, isValueRight, -1, true);
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

string formatVariableExt(int index){
	string ss = "";
	if (!SymbolTable[index].isGlobal) {
		ss = "BP";
		if (SymbolTable[index].address >= 0) {
			ss += "+";
		}
	} 
	return ss + to_string(SymbolTable[index].address);
}

string formatVariable(int index, bool isValue) {
	string ss = "";
	//jeżeli do wypisania jest liczba poprzedza ją znakiem # i wypisuje
	if (SymbolTable[index].token == NUM) {
		ss = "#" + SymbolTable[index].name;
	}
    //Jeżeli mamy do czynienia z referencją i trzeba wyłuskać adres
	else if (SymbolTable[index].isReference) {
		if (isValue) {
			ss = "*";
		}
		ss += formatVariableExt(index);
	}
    //Jeżeli mamy do czynienia ze zeminna/tablicą
	else if (SymbolTable[index].token == VAR || SymbolTable[index].token == ARRAY) {
		if (!isValue) {
			ss = "#";
		}
		ss += formatVariableExt(index);
	} 
	return ss;
}

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

	if (operand == RETURN) {
		writeToOutputExt("","return","",";return","");
		string res;
		res = ss.str();
		ss.str(string());//clear
		size_t pos = res.find("??");
		ss << "#" << -1 * getSymbolAddress(string(""));
		res.replace(pos, 2, ss.str());
		outputStream.write(res.c_str(), res.size());
		ss.str(string());
	} 
	else if (operand >= EQ && operand <= L) {
		castToSameType(leftVar, isValueLeft, rightVar, isValueRight);
		if (SymbolTable[leftVar].type == REAL){
			operationType = ".r ";
		}
		else{
			operationType = ".i ";
		}
		ss << "\n        ";
		
		if (operand == EQ) ss << "je";
		else if (operand == NE) ss << "jne";
		else if (operand == LE) ss << "jle";
		else if (operand == GE) ss << "jge";
		else if (operand == G) ss << "jg";
		else if (operand == L) ss << "jl";
		ss << operationType << "   ";
		writeVariable(leftVar, isValueLeft);
		ss << ",";
		writeVariable(rightVar, isValueRight);
		ss << "," << "#" << SymbolTable[resultVar].name;
	} 
	else if (operand == PROC || operand == FUN) {
		writeToOutput(SymbolTable[resultVar].name+":");
		writeToOutputExt("","enter.i","??",";enter.i","");
	} 
	else if (operand == LABEL) {
		ss << "\n" << SymbolTable[resultVar].name << ":";
	} 
	else if (operand == PUSH) {
		ss << "\n        push.i " << formatVariable(resultVar, isValueResult);
	} 
	else if (operand == INCSP) {
		ss << "\n        incsp" << operationType << formatVariable(resultVar, isValueResult);
	} 
	else if (operand == JUMP) {
		ss << "\n        jump.i  #" << SymbolTable[resultVar].name;
	} 
	else if (operand == CALL) {
		ss << "\n        call.i  #" << SymbolTable[resultVar].name;
	} 
	else if (operand == READ) {
		ss << "\n        read" << operationType << formatVariable(resultVar, isValueResult);
	} 
	else if (operand == WRITE) {
		ss << "\n        write" << operationType << formatVariable(resultVar, isValueResult);
	} 
	else if (operand == REALTOINT) {
		ss << "\n        realtoint.r " << formatVariable(leftVar, isValueLeft) << "," << formatVariable(resultVar, isValueResult);
	} 
	else if (operand == ASSIGN) {
		bool setSuccess = castToSameTypeForAssign(resultVar, isValueResult, rightVar, isValueRight);
		if (setSuccess) {
			return;
		} else {//jeżeli są tych samych typów jak były innych to funkcja castToSameTypeForAssign już przy konwersji je tam przepisała taka automatyzacja ;p
			ss << "\n        mov" << operationType << "  " << formatVariable(rightVar, isValueRight)  << "," <<formatVariable(resultVar, isValueResult);
		}
	}
	else if (operand == PLUS || operand == MINUS) {
		castToSameType(leftVar, isValueLeft, rightVar, isValueRight);
		ss << "\n        ";
		if (operand == MINUS){
			ss << "sub" << operationType;
		}
		else if (operand == PLUS){
			ss << "add" << operationType;
		}
		ss << formatVariable(leftVar, isValueLeft) << "," << formatVariable(rightVar, isValueRight) << "," <<formatVariable(resultVar, isValueResult);
	}
	else if (operand == MUL || operand == DIV || operand == MOD || operand == AND || operand == OR) {
		castToSameType(leftVar, isValueLeft, rightVar, isValueRight);
		ss << "\n        ";
		if (operand == MUL){
            ss << "mul";
        }
		else if (operand == DIV) 
        {
            ss << "div";
        }
		else if (operand == MOD)
        {
            ss << "mod";
        }
		else if (operand == AND)
        {
            ss << "and";
        }
		else if (operand == OR) 
        {
            ss << "or";
        }
        
		ss << operationType << "   " << formatVariable(leftVar, isValueLeft) << "," << formatVariable(rightVar, isValueRight) << "," << formatVariable(resultVar, isValueResult);
	} 
	else if (operand == INTTOREAL) {
		writeToOutputExt("","inttoreal.i " + formatVariable(leftVar, isValueResult) + "," + formatVariable(resultVar, isValueResult) ,"", "", "");
	}
}

void writeToOutput(string str) {
	ss << "\n" << str;
}

void writeStrToOutput(string str) {
	ss << "\n" << str;
}

void writeIntToOutput(int i) {
	ss << i;
}

void writeToFile() {
	outputStream.write(ss.str().c_str(), ss.str().size());
	ss.str(string()); //clear
}

void writeToOutputExt(string str0, string str1, string str2, string str3, string str4){
	ss	<< "\n"
		<< std::setw(8) << std::left<< str0 
		<< std::setw(8) << std::left << str1 
		<< std::setw(24) << std::left<< str2 
		<< std::setw(9)<< std::left<< str3 
		<<  str4;
}

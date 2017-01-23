#include "global.h"
#include "inc.h"
#include "parser.h"

using namespace std;

extern ofstream stream;
stringstream ss;

//generuje typ wyniku operacji na 2 Symbolach
int getResultType(int id1, int id2) {
	if (SymbolTable[id1].type == REAL || SymbolTable[id1].type == REAL) {
		return REAL;
	} else {
		return INTEGER;
	}
}

//funkcja zwraca typ Symbolów, jak adres to integer
int getSymbolType(int index, bool isValue) {
	if (isValue) {
		return SymbolTable[index].type;
	}
	else {
		return INTEGER;
	}
}

//zwraca token czyli w rzeczywistości liczbę na podstawie ciągu znaków
int getToken(const char *strValIn) {
	string strVal = strValIn;
	if (strVal.compare("+") == 0)
		return _PLUS;
	else if (strVal.compare("-") == 0)
		return _MINUS;
	else if (strVal.compare("*") == 0)
		return _MUL;
	else if (strVal.compare("/") == 0 || strVal.compare("div") == 0)
		return _DIV;
	else if (strVal.compare("mod") == 0)
		return _MOD;
	else if (strVal.compare("and") == 0)
		return _AND;
	else if (strVal.compare("=") == 0)
		return _EQ;
	else if (strVal.compare(">=") == 0)
		return _GE;
	else if (strVal.compare("<=") == 0)
		return _LE;
	else if (strVal.compare("<>") == 0)
		return _NE;
	else if (strVal.compare(">") == 0)
		return _G;
	else if (strVal.compare("<") == 0)
		return _L;
	return 0;
}

//konwertuje 2 zmienne na ten sam typ (wyższy) przekazuje dane przez referencję
void castToSameType(int &leftVar, bool isValueLeft, int &rightVar, bool isValueRight) {
	int leftType = getSymbolType(leftVar, isValueLeft);
	int rightType = getSymbolType(rightVar, isValueRight);

	if (leftType != rightType) {
		if (leftType == INTEGER && rightType == REAL) {
			int newLeftVar = addTempSymbol(REAL);
			writeToOutputByToken(_INTTOREAL, newLeftVar, isValueLeft, leftVar, isValueLeft, -1, true);
			leftVar = newLeftVar;
		} else if (leftType == REAL && rightType == INTEGER) {
			int newRightVar = addTempSymbol(REAL);
			writeToOutputByToken(_INTTOREAL, newRightVar, isValueRight, rightVar, isValueRight, -1, true);
			rightVar = newRightVar;
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

// todo:
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
		if (!SymbolTable[index].isGlobal) {
			ss << "BP";
			if (SymbolTable[index].address >= 0) {
				ss << "+";
			}
			ss << SymbolTable[index].address;
		} else {
			ss << SymbolTable[index].address;
		}
	}
		//Jeżeli mamy do czynienia ze zeminna/tablicą
	else if (SymbolTable[index].token == VAR || SymbolTable[index].token == ARRAY) {
		if (!isValue) {
			ss << "#";
		}
		if (!SymbolTable[index].isGlobal) {
			ss << "BP";
			if (SymbolTable[index].address >= 0) {
				ss << "+";
			}
			ss << SymbolTable[index].address;
		} else {
			ss << SymbolTable[index].address;
		}
	} else {
		yyerror("Nieprawidłowy typ.\n");
	}
}

//generuje kod dla prawie wszystkiego
void writeToOutputByToken(int operand, int resultVar, bool isValueResult, int leftVar, bool isValueLeft, int rightVar,
                          bool isValueRight) {
	string operationType = ".i ";

	if (resultVar != -1) {
		if (SymbolTable[resultVar].type == REAL) {
			operationType = ".r ";
		}
	}

	if (operand == _RETURN) {
		ss << "\n\treturn";
		string res;
		//zawartość srtingstreama do stringa
		res = ss.str();
		ss.str(string());//czyszczenie bo jest w res
		size_t pos = res.find("??");

		ss << "#" << -1 * getSymbolPosition(string(""));
		res.replace(pos, 2, ss.str());
		stream.write(res.c_str(), res.size());
		ss.str(string());
	} else if (operand >= _EQ && operand <= _L) {
		castToSameType(leftVar, isValueLeft, rightVar, isValueRight);
		operationType = ".i ";
		if (SymbolTable[leftVar].type == REAL)
			operationType = ".r ";
		ss << "\n\t";
		if (operand == _EQ) ss << "je";
		else if (operand == _NE) ss << "jne";
		else if (operand == _LE) ss << "jle";
		else if (operand == _GE) ss << "jge";
		else if (operand == _G) ss << "jg";
		else if (operand == _L) ss << "jl";
		ss << operationType;

		writeVariable(leftVar, isValueLeft);
		ss << ",";
		writeVariable(rightVar, isValueRight);
		ss << "," << "#" << SymbolTable[resultVar].name;
	} else if (operand == PROC || operand == FUN) {
		ss << "\n" << SymbolTable[resultVar].name << ":";
		ss << "\n\tenter.i ??";
	} else if (operand == _LABEL) {
		ss << "\n" << SymbolTable[resultVar].name << ":";
	} else if (operand == _PUSH) {
		ss << "\n\tpush.i ";
		writeVariable(resultVar, isValueResult);
	} else if (operand == _INCSP) {
		ss << "\n\tincsp" << operationType;
		writeVariable(resultVar, isValueResult);
	} else if (operand == _JUMP) {
		ss << "\n\tjump.i #" << SymbolTable[resultVar].name;
	} else if (operand == _CALL) {
		ss << "\n\tcall.i #" << SymbolTable[resultVar].name;
	} else if (operand == _READ) {
		ss << "\n\tread" << operationType;
		writeVariable(resultVar, isValueResult);
	} else if (operand == _WRITE) {
		ss << "\n\twrite" << operationType;
		writeVariable(resultVar, isValueResult);
	} else if (operand == _REALTOINT) {
		ss << "\n\trealtoint.r ";
		writeVariable(leftVar, isValueLeft);
		ss << ",";
		writeVariable(resultVar, isValueResult);
	} else if (operand == ASSIGN) {
		bool setSuccess = castToSameTypeForAssign(resultVar, isValueResult, rightVar, isValueRight);
		if (setSuccess) {
			return;
		} else {//jeżeli są tych samych typów jak były innych to funkcja castToSameTypeForAssign już przy konwersji je tam przepisała taka automatyzacja ;p
			ss << "\n\tmov" << operationType;
			writeVariable(rightVar, isValueRight);
			ss << ",";
			writeVariable(resultVar, isValueResult);
		}
	} else if (operand == _PLUS || operand == _MINUS) {
		castToSameType(leftVar, isValueLeft, rightVar, isValueRight);
		ss << "\n";
		if (operand == _MINUS)
			ss << "\tsub" << operationType;
		else
			ss << "\tadd" << operationType;
		writeVariable(leftVar, isValueLeft);
		ss << ",";
		writeVariable(rightVar, isValueRight);
		ss << ",";
		writeVariable(resultVar, isValueResult);
	} else if (operand == _MUL || operand == _DIV || operand == _MOD || operand == _AND || operand == OR) {
		castToSameType(leftVar, isValueLeft, rightVar, isValueRight);
		ss << "\n";
		if (operand == _MUL) ss << "\tmul";
		else if (operand == _DIV) ss << "\tdiv";
		else if (operand == _MOD) ss << "\tmod";
		else if (operand == _AND) ss << "\tand";
		else if (operand == OR) ss << "\tor";
		ss << operationType;
		writeVariable(leftVar, isValueLeft);
		ss << ",";
		writeVariable(rightVar, isValueRight);
		ss << ",";
		writeVariable(resultVar, isValueResult);

	} else if (operand == _INTTOREAL) {
		ss << "\n\tinttoreal.i ";
		writeVariable(leftVar, isValueResult);
		ss << ",";
		writeVariable(resultVar, isValueResult);
	}
	//stream.write(ss.str().c_str(), ss.str().size());
	//ss.str(string());//czyści
}

//funkcja szybkiego zapisu bezpośrednio przez parser dla prostych i niezmiennych operacji
void writeToOutput(const char *str) {
	ss << str;
}

void writeIntToOutput(int i) {
	ss << i;
}

void writeToFile() {
	stream.write(ss.str().c_str(), ss.str().size());
	ss.str(string());//czyści
}

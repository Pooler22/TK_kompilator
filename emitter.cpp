#include <iomanip>
#include "global.hpp"
#include "parser.hpp"

//#include "symbol.hpp"
//#include "parser.cpp"


using namespace std;
using std::cout;
using std::setw;

extern ofstream outputStream;
stringstream ss;

int getResultType(int id1, int id2) {
	if (SymbolTable[id1].type == REAL || SymbolTable[id2].type == REAL) {
		return REAL;
	} else {
		return INTEGER;
	}
}

int getToken(string value) {
	string strVal = value;
	if (strVal.compare("+") == 0) {
		return PLUS;
	}
	if (strVal.compare("-") == 0) {
		return MINUS;
	}
	if (strVal.compare("*") == 0) {
		return MUL;
	}
	if (strVal.compare("div") == 0 || strVal.compare("/") == 0) {
		return DIV;
	}
	if (strVal.compare("mod") == 0) {
		return MOD;
	}
	if (strVal.compare("and") == 0) {
		return AND;
	}
	if (strVal.compare("=") == 0) {
		return EQ;
	}
	if (strVal.compare(">=") == 0) {
		return GE;
	}
	if (strVal.compare("<=") == 0) {
		return LE;
	}
	if (strVal.compare("<>") == 0) {
		return NE;
	}
	if (strVal.compare(">") == 0) {
		return G;
	}
	if (strVal.compare("<") == 0) {
		return L;
	}
	return 0;
}

int getSymbolType(int index, bool isValue) {
	if (isValue) {
		return SymbolTable[index].type;
	} else { //address
		return INTEGER;
	}
}

void castToSameType(int &var1, bool isValue1, int &var2, bool isValue2) {
	int type1 = getSymbolType(var1, isValue1);
	int type2 = getSymbolType(var2, isValue2);

	if (type1 != type2) {
		if (type1 == INTEGER && type2 == REAL) {
			int newVar = insertTempSymbol(REAL);
			writeToOutputByToken(INTTOREAL, newVar, isValue1, var1, isValue1, -1, true);
			var1 = newVar;
		} else if (type1 == REAL && type2 == INTEGER) {
			int newVar = insertTempSymbol(REAL);
			writeToOutputByToken(INTTOREAL, newVar, isValue2, var2, isValue2, -1, true);
			var2 = newVar;
		} else {
			yyerror("Nieodpowiednie typy");
		}
	}
}

bool castToSameTypeForAssign(int var1, bool isValue1, int var2, bool isValue2) {
	int type1 = getSymbolType(var1, isValue1);
	int type2 = getSymbolType(var2, isValue2);

	if (type1 == type2) {
		return false;
	} else {
		if (type1 == INTEGER && type2 == REAL) {
			writeToOutputByToken(REALTOINT, var1, isValue1, var2, isValue2, -1, true);
			return true;
		} else if (type1 == REAL && type2 == INTEGER) {
			writeToOutputByToken(INTTOREAL, var1, isValue1, var2, isValue2, -1, true);
			return true;
		} else {
			yyerror("Nieodpowiednie typy dla przypisania");
			return false;
		}
	}
}

void writeVariableExt(int index) {
	auto symbol = SymbolTable[index];
	if (!symbol.isGlobal) {
		ss << "BP";
		if (symbol.address >= 0) {
			ss << "+";
		}
	}
	ss << symbol.address;
}

void writeVariable(int index, bool isValue) {
	auto symbol = SymbolTable[index];
	if (symbol.token == NUM) {
		ss << "#" << symbol.name;
	} else if (symbol.isReference) {
		if (isValue) {
			ss << "*";
		}
		writeVariableExt(index);
	} else if (symbol.token == VAR || symbol.token == ARRAY) {
		if (!isValue) {
			ss << "#";
		}
		writeVariableExt(index);
	} else {
		yyerror("Nieprawidłowy typ");
	}
}

string formatVariableExt(int index) {
	auto symbol = SymbolTable[index];
	string result = "";
	if (!symbol.isGlobal) {
		result = "BP";
		if (symbol.address >= 0) {
			result += "+";
		}
	}
	return result + to_string(symbol.address);
}

string formatVariable(int index, bool isValue) {
	string result = "";
	auto symbol = SymbolTable[index];
	if (symbol.token == NUM) {
		result = "#" + symbol.name;
	} else if (symbol.isReference) {
		if (isValue) {
			result = "*";
		}
		result += formatVariableExt(index);
	} else if (symbol.token == VAR || symbol.token == ARRAY) {
		if (!isValue) {
			result = "#";
		}
		result += formatVariableExt(index);
	}
	return result;
}

void writeToOutput(string str) {
	ss << "\n" << str;
}

void writeIntToOutput(int i) {
	ss << i;
}

void writeToOutputExt(string str0, string str1, string str2, string str3, string str4) {
	ss << "\n"
	   << std::setw(8) << std::left << str0
	   << std::setw(8) << std::left << str1
	   << std::setw(24) << std::left << str2
	   << std::setw(9) << std::left << str3
	   << str4;
}

void writeToFile() {
	outputStream.write(ss.str().c_str(), ss.str().size());
	ss.str(string()); //clear
}

void writeToOutputByToken(int token, int var1, bool isValue1, int var2, bool isValue2, int var3, bool isValue3) {
	string type;

	if (var1 != -1) {
		if (SymbolTable[var1].type == REAL) {
			type = ".r ";
		} else {
			type = ".i ";
		}
	}

	if (token == RETURN) {
		writeToOutputExt("", "return", "", ";return", "");
		string res;
		res = ss.str();
		ss.str(string());    //clear

		size_t pos = res.find("??");
		ss << "#" << -1 * getSymbolAddress(string(""));
		res.replace(pos, 2, ss.str());
		outputStream.write(res.c_str(), res.size());
		ss.str(string());    //clear
	} else if (token >= EQ && token <= L) {
		castToSameType(var2, isValue2, var3, isValue3);
		if (SymbolTable[var2].type == REAL) {
			type = ".r ";
		} else {
			type = ".i ";
		}
		ss << "\n        ";

		if (token == EQ) {
			ss << "je";
		} else if (token == NE) {
			ss << "jne";
		} else if (token == LE) {
			ss << "jle";
		} else if (token == GE) {
			ss << "jge";
		} else if (token == G) {
			ss << "jg";
		} else if (token == L) {
			ss << "jl";
		}
		ss << type << "   ";
		writeVariable(var2, isValue2);
		ss << ",";
		writeVariable(var3, isValue3);
		ss << "," << "#" << SymbolTable[var1].name;
	} else if (token == PROC || token == FUN) {
		writeToOutput(SymbolTable[var1].name + ":");
		writeToOutputExt("", "enter.i", "??", ";enter.i", "");
	} else if (token == LABEL) {
		ss << "\n" << SymbolTable[var1].name << ":";
	} else if (token == PUSH) {
		ss << "\n        push.i " << formatVariable(var1, isValue1);
	} else if (token == INCSP) {
		ss << "\n        incsp" << type << formatVariable(var1, isValue1);
	} else if (token == JUMP) {
		ss << "\n        jump.i  #" << SymbolTable[var1].name;
	} else if (token == CALL) {
		ss << "\n        call.i  #" << SymbolTable[var1].name;
	} else if (token == READ) {
		ss << "\n        read" << type << formatVariable(var1, isValue1);
	} else if (token == WRITE) {
		ss << "\n        write" << type << formatVariable(var1, isValue1);
	} else if (token == REALTOINT) {
		ss << "\n        realtoint.r " << formatVariable(var2, isValue2) << "," << formatVariable(var1, isValue1);
	} else if (token == ASSIGN) {
		bool setSuccess = castToSameTypeForAssign(var1, isValue1, var3, isValue3);
		if (setSuccess) {
			return;
		} else {//jeżeli są tych samych typów jak były innych to funkcja castToSameTypeForAssign już przy konwersji je tam przepisała taka automatyzacja ;p
			ss << "\n        mov" << type << "  " << formatVariable(var3, isValue3) << ","
			   << formatVariable(var1, isValue1);
		}
	} else if (token == PLUS || token == MINUS) {
		castToSameType(var2, isValue2, var3, isValue3);
		ss << "\n        ";
		if (token == MINUS) {
			ss << "sub" << type;
		} else if (token == PLUS) {
			ss << "add" << type;
		}
		ss << formatVariable(var2, isValue2) << "," << formatVariable(var3, isValue3) << ","
		   << formatVariable(var1, isValue1);
	} else if (token == MUL || token == DIV || token == MOD || token == AND || token == OR) {
		castToSameType(var2, isValue2, var3, isValue3);
		ss << "\n        ";
		if (token == MUL) {
			ss << "mul";
		} else if (token == DIV) {
			ss << "div";
		} else if (token == MOD) {
			ss << "mod";
		} else if (token == AND) {
			ss << "and";
		} else if (token == OR) {
			ss << "or";
		}

		ss << type << "   " << formatVariable(var2, isValue2) << "," << formatVariable(var3, isValue2)
		   << "," << formatVariable(var1, isValue1);
	} else if (token == INTTOREAL) {
		writeToOutputExt("", "inttoreal.i " + formatVariable(var2, isValue1) + "," + formatVariable(var1, isValue1),
						 "", "", "");
	}
}


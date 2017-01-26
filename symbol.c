#include "global.h"
#include "parser.h"

using namespace std;

vector <Symbol> SymbolTable;
int variablesCount = 0;
int labelsCount = 1;


void checkSymbolExist(int id){
    if(id == -1) {
		yyerror("Niezadeklarowana zmienna.");
    }
}

// alokuje nową zmienną tymczasową typu type
int addTempSymbol(int type) {
	string ss = "$t" + to_string(variablesCount++);
	int id = insert(ss.c_str(), VAR, type);
	//wygeneruj pozycję gdzie bedzie ta nowa zmienna
	SymbolTable[id].address = getSymbolPosition(ss.c_str());
	return id;
}

int addLabel() {
	string ss = "lab" + to_string(labelsCount++);
	int id = insert(ss.c_str(), _LABEL, NONE);
	return id;
}

void addVariable(int index, int type){
    SymbolTable[index].token = VAR;
	SymbolTable[index].type = type;
	SymbolTable[index].address = getSymbolPosition(SymbolTable[index].name);
}

void addArray(int index, int type,int helpVarArray,ArrayInfo array_range){
    SymbolTable[index].type = helpVarArray;
	SymbolTable[index].token = type;
	SymbolTable[index].array = array_range; // struktura zawierająca indeks początkowy i końcowy array
	SymbolTable[index].address = getSymbolPosition(SymbolTable[index].name);
}

//generuje pozycję dla nowej zmiennej (rozmiar zaalokowanych zmiennych)
//w danej części local/global
//w zakresie globalnym pomijamy symbolName bo indeksy rosną w górę
//w lokalnym odwrotnie
int getSymbolPosition(string symbolName) {
	int varPosition = 0;

	if (isGlobal) {
		for (auto &symbol : SymbolTable) {
			if (!symbol.isGlobal) {
				break;
			}
			if (symbol.name != symbolName) {
				varPosition += getSymbolSize(symbol);
			}
		}
	} else {
		for (auto &symbol : SymbolTable) {
			if (!symbol.isGlobal && symbol.address <= 0) {
				varPosition -= getSymbolSize(symbol);
				//na minusie tak jak na laboratoriach
			}
		}
	}
	return varPosition;
}

// zwraca rozmiar danego wpisu w tablicy symboli
int getSymbolSize(Symbol e) {
	const int intSizeElement = 4;
	const int realSizeElement = 8;
	const int intArraySizeElement = 4; // rozmiar Symbolu tablicy
	const int realArraySizeElement = 8;
	const int referenceSizeElement = 4;
	const int nothingSizeElement = 0;

	if (e.token == VAR) {
		if (e.type == INTEGER) {
			return intSizeElement;
		} else if (e.type == REAL) {
			return realSizeElement;
		}
	} 
	else if (e.token == ARRAY) {
		if (e.type == REAL) {
			return (e.array.stopVal - e.array.startVal + 1) * realArraySizeElement;
		}
		else{
			return (e.array.stopVal - e.array.startVal + 1) * intArraySizeElement;
		}
	} 
	else if (e.isReference){
		return referenceSizeElement;
	}
	return nothingSizeElement;
}

string getDescription(int tokenId) {
	switch (tokenId) {
		case PROC:
			return "procedure";
		case FUN:
			return "function";
		case _LABEL:
			return "label";
		case ID:
			return "id";
		case VAR:
			return "variable";
		case ARRAY:
			return "array";
		case NUM:
			return "number";
		case INTEGER:
			return "integer";
		case REAL:
			return "real";
		default:
			return "null";
	}
}

void clearLocalSymbols() {
	int localVarsStart = 0;

	for (auto &element : SymbolTable) {
		if (!element.isGlobal) {
			break;
		}
		localVarsStart++;
	}
	SymbolTable.erase(SymbolTable.begin() + localVarsStart, SymbolTable.end());
}

//wstawia wpis do ST
int insert(const char *s, int token, int type) {
	string name = s;
	Symbol e;
	e.token = token;        // typ tokenu (VAR, NUM, ARRAY, FUN, PROC)
	e.name = name;            //nazwa
	e.type = type;
	e.isGlobal = isGlobal; // zakres
	e.isReference = false;
	e.address = 0;

	SymbolTable.push_back(e);
	return SymbolTable.size() - 1;
}

int insertNum(const char *numVal, int numType) {
	int num = lookup(numVal);

	if (num == -1) {
		num = insert(numVal, NUM, numType);
	}
	return num;
}

int lookup(const char *s) {
	int p = SymbolTable.size() - 1;
	for (p; p >= 0; p--) {
		if (SymbolTable[p].name == s) {
			return p;
		}
	}
	return -1;
}

int lookupIfExistAndInsert(const char *s, int token, int type) {
	int value = lookupIfExist(s);
	if (value == -1)
	{
		value = insert(s, token, type);
	}
	return value;
}

int lookupIfExist(const char *s) {
	int p = SymbolTable.size() - 1;

	//szukamy od końca w zakresie lokalnym
	if (!isGlobal) {
		for (p; p >= 0; p--) {
			if (SymbolTable[p].isGlobal) {//brak w części lokalnej
				return -1;
			}
			if (SymbolTable[p].name == s) {//znaleziono w części lokalnej
				return p;
			}
		}
	}
	else{
		for (p; p >= 0; p--) {//czy jest w części globalnej
			if (SymbolTable[p].name == s) {//znaleziono
				return p;
			}
		}
	}
	return -1;
}

int lookupForFunction(const char *s) {
	int p = SymbolTable.size() - 1;
	for (p; p >= 0; p--) {
		if (SymbolTable[p].name == s && (SymbolTable[p].token == FUN || SymbolTable[p].token == PROC)) {
			return p;
		}
	}
	return -1;
}
//sprawdza czy istnieje zwraca -1 lub id Symbolu w tablicy symboli


void printSymbolTable() {
	cout << "; Symbol table dump" << endl;
	int i = 0;

	for (auto &e : SymbolTable) {
		if(e.token != ID){
			cout << "; " << i++;

			if (e.isGlobal) {
				cout << " Global ";
			} 
			else {
				cout << " Local ";
			}

			if (e.isReference) {
				cout << "reference variable " << e.name << " ";
				if(e.token == ARRAY){
					cout << getDescription(e.token) << " [" << e.array.startVal << ".." << e.array.stopVal << "]" << " of ";
				}
				cout  << getDescription(e.type) << " offset=" << e.address
				     << endl;
			}
			else if (e.token == PROC || e.token == FUN || e.token == _LABEL) {
				cout << getDescription(e.token) << " " << e.name << endl;
			}
			else if (e.token == VAR) {
				cout << getDescription(e.token) << " " << e.name << " " << getDescription(e.type) << " offset=" << e.address
				     << endl;
			}
			else if (e.token == ARRAY) {
				cout << "variable" << " " << e.name << " array [" << e.array.startVal << ".." << e.array.stopVal << "] of "
				     << getDescription(e.type) << " offset=" << e.address << endl;
			}
			else if (e.token == NUM) {
				cout << getDescription(e.token) << " " << e.name << " " << getDescription(e.type) << endl;
			}
			// else if (e.token == ID) {
			// 	cout << getDescription(e.token) << " " << e.name << endl;
			// }
			// else {
			// 	cout << "OTHER" << e.name << " " << e.token << " " << e.type << " " << e.address << endl;
			// }
		}
	}
}

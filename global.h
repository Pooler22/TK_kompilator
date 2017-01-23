#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <utility>
#include <list>
using namespace std;
// dane tablic
struct arrayRange{
	int start;//id w tablicy symboli
	int stop;
	int startVal;//wartość
	int stopVal;
	int argType;
};
// wpis w tablicy symboli
struct Symbol{
	string name;	 //nazwa lub numer (dla liczb)
	int token;		 //typ tokenu mojego
	int type;		 //rodzaj wartości int/real
	int address;	 //adres (offset który został przydzielony)
	arrayRange array;	 // dane tablicy// dla tablic
	bool isReference;// czy jest referencją	domyślnie nie jest
	bool isGlobal;		// zakres (true-globalny, false - lokalny)
	list<pair<int,arrayRange> > parameters; // typy kolejnych parametrów (funkcja/procedura)
	int returnType;		// typ zwracany (funkcja)// funkcja
};
int lookupForFunction(const char* );
void writeToOutputByToken(int operand, int resultVar, bool isValueResult, int leftVar, bool isValueLeft, int rightVar, bool isValueRight);
extern bool isGlobal;//zmienna na aktualny zakres
int getToken(const char*);//pobiera przydzielony token na podstawie tekstu operacji np >= otrzyma token GE
void writeToOutput(const char* s);//zapisuje bezpośrednio do pliku
extern int lineno;//nr linii
int yylex();//odpala lekser
int yyparse();//odpala parser
int lookupIfExist(const char* s);//sprawdza czy dane id jest już w tablicy w zakresie likalnym lub globalnym
int addTempSymbol(int type);//tworzy dodatkową zmienną dla obliczeń to "t" z zajęć
int insert (const char* s, int token, int type);//wrzuca do TS
void yyerror(char const* s);//funkcja błędu parsera
extern vector<Symbol> SymbolTable;//TS
extern ofstream stream;//stream do zapisu
int yylex_destroy();//zabija parser
int generateResultType(int a, int b);//generuje typ wyniku dla 2 operandów
int getSymbolPosition(string symbolName="");//oblicza index w którym bedzie nowa zmienna np 12 dla global, -24 dla local
int getSymbolSize(Symbol e);//podaje rozmiar Symbolu
int addLabel();//tworzy kolejny label do skoku
void printSymbolTable(); //drukuje tablicę symboli
string getTokenString(int tokenID);//dla printSymTable
extern FILE* yyin;//plik wejściowy dla leksera
int lookup(const char* s);
int insertNum(const char*, int);//wstawia num do ST jak nie istnieje
void clearLocalSymbols();
void writeAllToFile();
void writeIntToOutput(int);
int lookupForFunction(const char *);
//tokeny któe mogą wystąpić

#define _LABEL 1257
#define _WRITE 1259
#define _READ 1260
#define _PUSH 1261
#define _INCSP 1262
#define _PLUS 1264
#define _MINUS 1265
#define _MUL 1266
#define _DIV 1267
#define _MOD 1268
#define _AND 1269
#define _INTTOREAL 1270
#define _REALTOINT 1271
#define _CALL 1272
#define _RETURN 1274
#define _EQ 1275
#define _NE 1276
#define _GE 1277
#define _LE 1278
#define _G 1279
#define _L 1280
#define _JUMP 1281

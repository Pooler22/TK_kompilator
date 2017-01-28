#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <utility>
#include <list>
#include "inc.h"
#include "SymbolTableHelper.h"

using namespace std;

extern bool isGlobal;//zmienna na aktualny zakres
extern int lineno;//nr linii
extern SymbolTableHelper test;
extern vector<Symbol> SymbolTable;//TS
extern ofstream stream;//stream do zapisu
extern FILE* yyin;//plik wejściowy dla leksera

void writeStrToOutput(string str);
void addVariable(int index, int type);
void addArray(int index, int type,int helpVarArray,ArrayInfo array_range);
void checkSymbolExist(int id);

void writeToOutputByToken(int operand, int resultVar, bool isValueResult, int leftVar, bool isValueLeft, int rightVar, bool isValueRight);
void writeToOutputExt(const char *str0, const char *str1, const char *str2, const char *str3, const char *str4);
void writeToOutput(const char* s);//zapisuje bezpośrednio do pliku
void yyerror(char const* s);//funkcja błędu parsera
void printSymbolTable(); //drukuje tablicę symboli
void clearLocalSymbols();
void writeToFile();
void writeIntToOutput(int);
int lookupForFunction(const char* );
int getToken(const char*);//pobiera przydzielony token na podstawie tekstu operacji np >= otrzyma token GE
int yylex();//odpala lekser
int yyparse();//odpala parser
int lookupIfExist(const char* s);//sprawdza czy dane id jest już w tablicy w zakresie likalnym lub globalnym
int lookupIfExistAndInsert(const char *s, int token, int type);
int addTempSymbol(int type);//tworzy dodatkową zmienną dla obliczeń to "t" z zajęć
int insert (const char* s, int token, int type);//wrzuca do TS
int yylex_destroy();//zabija parser
int getResultType(int a, int b);//generuje typ wyniku dla 2 operandów
int getSymbolAddress(string symbolName="");//oblicza index w którym bedzie nowa zmienna np 12 dla global, -24 dla local
int getSymbolSize(Symbol e);//podaje rozmiar Symbolu
int addLabel();//tworzy kolejny label do skoku
int lookup(const char* s);
int insertNum(const char*, int);//wstawia num do ST jak nie istnieje
int lookupForFunction(const char *);
string getTokenString(int tokenID);//dla printSymTable

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

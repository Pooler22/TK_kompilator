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
#include "symbol.h"

#define _LABEL 		301
#define _WRITE 		302
#define _READ 		303
#define _PUSH 		304
#define _INCSP 		305
#define _PLUS 		306
#define _MINUS 		307
#define _MUL 		308
#define _DIV 		309
#define _MOD 		310
#define _AND 		311
#define _INTTOREAL 	312
#define _REALTOINT 	313
#define _CALL 		214
#define _RETURN 	215
#define _EQ 		216
#define _NE 		217
#define _GE 		218
#define _LE 		219
#define _G 			220
#define _L 			221
#define _JUMP 		222

using namespace std;

extern bool isGlobal;
extern int lineno;
extern ofstream outputStream;
extern FILE* yyin;
extern vector<Symbol> SymbolTable;

//error.c
void checkSymbolExist(int);

//symbol.c
int insertTempSymbol(int);
int insertLabel();
void addVariable(int, int);
void addArray(int, int, int, ArrayInfo);
int getSymbolAddress(string);
int getSymbolSize(Symbol);
string tokenToString(int);
void clearLocalSymbols();
void initSymbolTable();
int insert (string, int, int);
int insertNum(string, int);
int lookup(string);
int lookupIfExistAndInsert(string, int, int);
int lookupIfExist(string);
int lookupForFunction(string);
void printSymbolTable();

//emitter.c
int getResultType(int, int);
int getToken(string);
void writeToOutputByToken(int, int, bool, int, bool, int, bool);
void writeToOutput(string);
void writeStrToOutput(string);
void writeIntToOutput(int);
void writeToFile();
void writeToOutputExt(string, string, string, string, string);

//lexer
int yylex();
int yylex_destroy();

//parser
int yyparse();
void yyerror(char const* s);

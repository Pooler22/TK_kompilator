#ifndef INCLUDE_H

#define INCLUDE_H

#include <string>
#include <iostream>
#include <list>

using namespace std;

class ArrayInfo{
public:
	int startId;
	int stopId;
	int startVal;
	int stopVal;
	int argType;
};

class Symbol{
public:
	bool isReference;
	bool isGlobal;
	int token;							 	// typ tokenu: FUN, PROC ...
	int type;							 	// rodzaj wartości INTEGER/REAL
	int address;						 	// adres - offset który został przydzielony
	string name;						 	// nazwa lub numer dla liczb: lab0
	ArrayInfo arrayInfo;					// dane tablicy
	list<pair<int, ArrayInfo>> parameters;	// typy kolejnych parametrów - funkcja/procedura
};

#endif


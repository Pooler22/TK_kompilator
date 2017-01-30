#ifndef INCLUDE_H

#define INCLUDE_H

#include <string>
#include <iostream>
#include <list>

using namespace std;

class ArrayInfo{
public:
	int start;//id w tablicy symboli
	int stop;
	int startVal;//wartość
	int stopVal;
	int argType;
};

class Symbol{
public:
	bool isReference;	// czy jest referencją	domyślnie nie jest
	bool isGlobal;		// zakres true-globalny, false - lokalny
	int token;		 	//typ tokenu
	int type;		 	//rodzaj wartości int/real
	int address;	 	//adres - offset który został przydzielony
	int returnType;		// typ zwracany - funkcja
	string name;	 	//nazwa lub numer - dla liczb
	ArrayInfo array;	// dane tablicy// dla tablic
	list<pair<int,ArrayInfo> > parameters; // typy kolejnych parametrów - funkcja/procedura
};

#endif


#include "global.h"
#include "parser.h"

using namespace std;

ofstream stream;
bool isGlobal = true;

int main(int argc, char *argv[]) {
	string outputFileName;
	stringstream streamString;
	FILE *inputFile;

	if(argc < 2) {
		printf("Error: Parameters not found\n");
		return -1;
	}
	else if(argc == 2) {
		outputFileName = argv[1];
	}
	else if(argc > 2) {
		outputFileName = argv[2];
	}

	inputFile = fopen(argv[1], "r");

	if (!inputFile) {
		printf("Error: File not found\n");
		return -1;
	}

	//plik dla leksera
	yyin = inputFile;

	// ustaw zakres na globalny
	isGlobal = true;

	// otwórz plik wynikowy
	stream.open(string(outputFileName)+".asm", ofstream::trunc);
	if (!stream.is_open()) {
		printf("Error: Cannot open output file");
		return -1;
	}

	//wstaw do tablicy symboli read write i lab0
	Symbol r;
	r.name = string("read");
	r.isGlobal = true;
	r.isReference = false;
	r.token = PROC;
	SymbolTable.push_back(r);

	Symbol w;
	w.name = string("write");
	w.isGlobal = true;
	w.isReference = false;
	w.token = PROC;
	SymbolTable.push_back(w);

	Symbol l;
	l.name = string("lab0");
	l.isGlobal = true;
	l.isReference = false;
	l.token = _LABEL;
	SymbolTable.push_back(l);

	//jump.i #lab0
	streamString << "\t\t\tjump.i  #" << l.name;
	stream.write(streamString.str().c_str(), streamString.str().size());

	yyparse();
	printSymbolTable();
	stream.close();
	fclose(inputFile);
	yylex_destroy();

	return 0;
}

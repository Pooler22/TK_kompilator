#include "global.h"
#include "parser.h"

using namespace std;

ofstream outputStream;
bool isGlobal = true;

string getFileOutputName(int argc, char *argv[]){
	if(argc == 2) {
		return string(argv[1]);
	}
	else if(argc > 2) {
		return string(argv[2]);
	}
	else {
		return "no_name";
	}
}

int main(int argc, char *argv[]) {
	stringstream streamString;
	FILE *inputFile;

	if(argc < 2) {
		printf("Error: Bledna ilosc paramterow\n");
		return -1;
	}

	inputFile = fopen(argv[1], "r");

	if (!inputFile) {
		printf("Error: File not found\n");
		return -1;
	}

	yyin = inputFile;

	outputStream.open(getFileOutputName(argc,argv)+ ".asm", ofstream::trunc);
	if (!outputStream.is_open()) {
		printf("Error: Cannot open output file");
		return -1;
	}
	
	Symbol read;
	read.name = ("read");
	read.isGlobal = true;
	read.isReference = false;
	read.token = PROC;
	SymbolTable.push_back(read);

	Symbol write;
	write.name = ("write");
	write.isGlobal = true;
	write.isReference = false;
	write.token = PROC;
	SymbolTable.push_back(write);

	Symbol lab0;
	lab0.name = ("lab0");
	lab0.isGlobal = true;
	lab0.isReference = false;
	lab0.token = _LABEL;
	SymbolTable.push_back(lab0);

	streamString << "        " << "jump.i  #" << lab0.name << "                   ;jump.i  lab0";
	outputStream.write(streamString.str().c_str(), streamString.str().size());

	yyparse();
	printSymbolTable();

	outputStream.close();
	fclose(inputFile);
	yylex_destroy();

	return 0;
}

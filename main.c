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

	yyin = inputFile;

	stream.open(string(outputFileName)+".asm", ofstream::trunc);
	if (!stream.is_open()) {
		printf("Error: Cannot open output file");
		return -1;
	}

	Symbol read;
	read.name = string("read");
	read.isGlobal = true;
	read.isReference = false;
	read.token = PROC;
	SymbolTable.push_back(read);

	Symbol write;
	write.name = string("write");
	write.isGlobal = true;
	write.isReference = false;
	write.token = PROC;
	SymbolTable.push_back(write);

	Symbol lab0;
	lab0.name = string("lab0");
	lab0.isGlobal = true;
	lab0.isReference = false;
	lab0.token = _LABEL;
	SymbolTable.push_back(lab0);

	streamString << "\t\t\t" << "jump.i  #" << lab0.name;
	stream.write(streamString.str().c_str(), streamString.str().size());

	yyparse();
	printSymbolTable();

	stream.close();
	fclose(inputFile);
	yylex_destroy();

	return 0;
}

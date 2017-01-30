#include "global.h"

using namespace std;

void checkSymbolExist(int id){
    if(id == -1) {
		yyerror("Niezadeklarowana zmienna/nazwa");
    }
}

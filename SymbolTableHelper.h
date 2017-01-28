#ifndef SYMBOL_TABLE_HELPER_H

#define SYMBOL_TABLE_HELPER_H

#include <string>
#include <iostream>
#include <list>
#include <vector>
#include "inc.h"

using namespace std;

class SymbolTableHelper{
public:
    vector<Symbol> SymbolTable;
    SymbolTableHelper(void);
    void test();
};

#endif

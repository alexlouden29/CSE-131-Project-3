/**
 * File: symtable.h
 * ----------- 
 *  Header file for Symbol table implementation.
 */

#ifndef _H_symtable
#define _H_symtable

#include <vector>
#include <map>
#include <string>
#include "ast_decl.h"

using namespace std;
typedef map<string, Decl*> scope;

class SymbolTable {
  protected:
    vector<scope> *scopes;

  public:
    SymbolTable(); //constructor

    bool ifFlag, elseFlag, elifFlag;
    bool whileFlag, forFlag;
    bool globalScope;
    bool funcFlag;
    bool doWhileFlag; 
    bool switchFlag;
    bool breakFlag;
    bool returnFlag;
    Type *returnType;

    void pushScope(scope *s);
    void popScope();
    void addSymbol(string key, Decl* decl);
    Decl* lookup(string key);
    scope* currScope();
    Decl* lookupInScope(string key, scope *s);
    int size();
    int sizeInt;
   
};


#endif



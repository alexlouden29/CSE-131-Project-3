/*
 * Symbol table implementation
 *
 */

#include "symtable.h"
#include "ast.h"
#include "ast_type.h"
#include "ast_decl.h"

SymbolTable::SymbolTable(){
  //vector<scope> scopes;
  ifFlag = false;
  elseFlag = false;
  elifFlag = false;
  whileFlag = false;
  forFlag = false;
  globalScope = false;
  funcFlag = false;
  doWhileFlag = false;
  switchFlag = false;
  
}

void SymbolTable::pushScope(scope s){
  vector<scope>::iterator it;
  it = scopes.begin();
  scopes.insert(it, s);
}

void SymbolTable::popScope(){
  vector<scope>::iterator it;
  it = scopes.begin();
  scopes.erase(it);
}

void SymbolTable::addSymbol(string key, Decl* decl){
  map<string, Decl*> m = scopes[0];
  m.insert(pair<string,Decl*>(key,decl));
}

Decl* SymbolTable::lookup(string key, scope *s){
  return s->at(key);
}

scope* SymbolTable::currScope(){
  return &scopes[0];
}

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
  breakFlag = false;
  returnFlag = false;
  Type *returnType = NULL;
}

void SymbolTable::pushScope(scope s){
  //vector<scope>::iterator it;
  //it = scopes.begin();
  scopes.push_back(s);
}

void SymbolTable::popScope(){
  //vector<scope>::iterator it;
  //it = scopes.begin();
  scopes.pop_back();
}

void SymbolTable::addSymbol(string key, Decl* decl){
  //cout << "PULLING TOP SCOPE" << endl;
  scope m = scopes.back();
  //cout << "INSERTING" << endl;
  m.insert(pair<string,Decl*>(key,decl));
  //cout << "INSERTED, DONE" << endl;
}

Decl* SymbolTable::lookup(string key){
  Decl* d = NULL;
  for(vector<scope>::reverse_iterator vectorIt = scopes.rbegin(); vectorIt != scopes.rend(); ++vectorIt){
    scope* s = &(*vectorIt);
    d = lookupInScope(key, s);
    if(d != NULL){
      break;
    }
  }
  return d;
}

Decl* SymbolTable::lookupInScope(string key, scope *s){
  //cout << "Making iterator" << endl;
  scope::iterator it;
  //cout << "finding key" << endl;
  it = s->find(key);
  //cout << "looping through something?" << endl;
  if (it != s->end()){
    cout << "Was not at end" << endl;
    return s->at(key);
  }
  return NULL;
}

scope* SymbolTable::currScope(){
  return &scopes.back();
}

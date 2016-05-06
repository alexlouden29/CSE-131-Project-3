/*
 * Symbol table implementation
 *
 */

#include "symtable.h"
#include "ast.h"
#include "ast_type.h"
#include "ast_decl.h"

SymbolTable::SymbolTable(){
  vector<scope> scopess;
  scopes = &scopess;
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

void SymbolTable::pushScope(scope *s){
  //vector<scope>::iterator it;
  //it = scopes.begin();
  cout << "adding a new scope" << endl;
  cout << &s << endl;
  cout << scopes->size() << endl;
  scopes->push_back(*s);
  cout << scopes->size() << endl;
}

void SymbolTable::popScope(){
  //vector<scope>::iterator it;
  //it = scopes.begin();
  cout << "removing scope" << endl;
  scopes->pop_back();
}

void SymbolTable::addSymbol(string key, Decl* decl){
  cout << "Adding symbol" << endl;
  scope* m = &scopes->back();
  //cout << "INSERTING" << endl;
  m->insert(pair<string,Decl*>(key,decl));
  cout << m->count(key) << endl;
  cout << &m << "  <- ADRESS DURING ADD" << endl;
  //cout << "INSERTED, DONE" << endl;
}

Decl* SymbolTable::lookup(string key){
  cout << "Looking up in all" << endl;
  Decl* d = NULL;
  for(vector<scope>::reverse_iterator vectorIt = scopes->rbegin(); vectorIt != scopes->rend(); ++vectorIt){
    scope* s = &(*vectorIt);
    d = lookupInScope(key, s);
    if(d != NULL){
      break;
    }
  }
  return d;
}

Decl* SymbolTable::lookupInScope(string key, scope *s){
  cout << "looking up in scope" << endl;
  /*scope::iterator it;
  it = s->find(key);
  if (it != s->end()){
    cout << "Was not at end" << endl;
    return s->at(key);
  }*/
  cout << scopes->size() << endl;
  int i = s->count(key);
  cout << "GOT COUNT SUCESSFULLY" << endl;
  if(i > 0)
    cout << "IN IF" << endl;
    return s->at(key);
  return NULL;
}

scope* SymbolTable::currScope(){
  cout << "getting current scope" << endl;
  cout << &scopes->back() << endl;
  if (&scopes->back() == NULL)
    cout << "FUCK" << endl;
  return &(scopes->back());
}

/* File: ast_decl.cc
 * -----------------
 * Implementation of Decl node classes.
 */
#include "ast_decl.h"
#include "ast_type.h"
#include "ast_stmt.h"
#include "symtable.h"        
#include "errors.h"
#include "ast.h"

//Check function for Variable Declarations
void VarDecl::CheckID(Identifier *id){
  //Check that types match if variable is set to something.
  if(assignTo != NULL){
    Type *rtype = assignTo->CheckWithType();
    if(!type->IsConvertibleTo(rtype)){
      ReportError::InvalidInitialization(id, type, rtype);
      type = Type::errorType;
    }
  }
  //cout << "PAST IF" << endl;
  string str = string( id->GetName() );
  //cout << "TRYING TO GET SCOPE" << endl;
  scope* sc = symtable->currScope();
  cout << sc << endl;
  //cout << "GOT SCOPE" << endl;
  //cout << "Trying to check symtable" << endl;
  Decl *d = symtable->lookupInScope(str, sc);
  //cout << "GOT SYMTABLE" << endl;
  //Check if variable is already present.
  if (d != NULL) {
    //cout << "REPORTING ERROR" << endl;
    ReportError::DeclConflict(this, d);
  }
  else{
    cout << "ADDING " << str <<  " TO SYMTABLE" << endl;
    symtable->addSymbol(str, this);
    sc = symtable->currScope();
    d = symtable->lookupInScope(str, sc);
    if(d!=NULL) {cout << "Good I guess" << endl;}
    //cout << "added to symtable" << endl;
  }
}
         
Decl::Decl(Identifier *n) : Node(*n->GetLocation()) {
    Assert(n != NULL);
    (id=n)->SetParent(this); 
}

VarDecl::VarDecl(Identifier *n, Type *t, Expr *e) : Decl(n) {
    Assert(n != NULL && t != NULL);
    (type=t)->SetParent(this);
    if (e) (assignTo=e)->SetParent(this);
    typeq = NULL;
}

VarDecl::VarDecl(Identifier *n, TypeQualifier *tq, Expr *e) : Decl(n) {
    Assert(n != NULL && tq != NULL);
    (typeq=tq)->SetParent(this);
    if (e) (assignTo=e)->SetParent(this);
    type = NULL;
}

VarDecl::VarDecl(Identifier *n, Type *t, TypeQualifier *tq, Expr *e) : Decl(n) {
    Assert(n != NULL && t != NULL && tq != NULL);
    (type=t)->SetParent(this);
    (typeq=tq)->SetParent(this);
    if (e) (assignTo=e)->SetParent(this);
}
  
void VarDecl::PrintChildren(int indentLevel) { 
   if (typeq) typeq->Print(indentLevel+1);
   if (type) type->Print(indentLevel+1);
   if (id) id->Print(indentLevel+1);
   if (assignTo) assignTo->Print(indentLevel+1, "(initializer) ");
}

FnDecl::FnDecl(Identifier *n, Type *r, List<VarDecl*> *d) : Decl(n) {
    Assert(n != NULL && r!= NULL && d != NULL);
    (returnType=r)->SetParent(this);
    (formals=d)->SetParentAll(this);
    body = NULL;
    returnTypeq = NULL;
}

FnDecl::FnDecl(Identifier *n, Type *r, TypeQualifier *rq, List<VarDecl*> *d) : Decl(n) {
    Assert(n != NULL && r != NULL && rq != NULL&& d != NULL);
    (returnType=r)->SetParent(this);
    (returnTypeq=rq)->SetParent(this);
    (formals=d)->SetParentAll(this);
    body = NULL;
}

void FnDecl::SetFunctionBody(Stmt *b) { 
    (body=b)->SetParent(this);
}

void FnDecl::PrintChildren(int indentLevel) {
    if (returnType) returnType->Print(indentLevel+1, "(return type) ");
    if (id) id->Print(indentLevel+1);
    if (formals) formals->PrintAll(indentLevel+1, "(formals) ");
    if (body) body->Print(indentLevel+1, "(body) ");
}

void FnDecl::CheckID( Identifier *id){
  //pushing new scope
  scope s;
  symtable->pushScope(&s);

  //how do i verify?

  //adding formals into scope
  List<VarDecl*> *formals = this->GetFormals();
  VarDecl *v = NULL;
  for(int i = 0; i < formals->NumElements(); i++){
    v = formals->Nth(i);
    v->Check();
  }
  //need to call check on each stmt inside stmtblock
  Stmt *stmtBody = this->body;
  Node::symtable->returnType = this->returnType;
  stmtBody->Check();

  if(Node::symtable->returnFlag == true){
    ReportError::ReturnMissing(this);
  }
  
  //popping scope
  symtable->popScope();
}

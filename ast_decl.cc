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
  string str = string( id->GetName() );
  scope* sc = symtable->currScope();
  Decl *d = symtable->lookupInScope(str, sc);
  //Check if variable is already present.
  if (d != NULL) {
    ReportError::DeclConflict(this, d);
  }
  else{
    symtable->addSymbol(str, this);
    sc = symtable->currScope();
  }
  if(assignTo != NULL){
    //cout << "ASSIGN TO IS NOT NULL" << endl;
    Type *rtype = assignTo->CheckWithType();
    if(!type->IsConvertibleTo(rtype)){
      ReportError::InvalidInitialization(id, type, rtype);
      //type = Type::errorType;
      //return;
    }
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
  if(formals->NumElements() > 0){
    VarDecl *v = NULL;
    for(int i = 0; i < formals->NumElements(); i++){
      v = formals->Nth(i);
      v->Check();
    }
  }
  //need to call check on each stmt inside stmtblock
  Stmt *stmtBody = this->body;
  Node::symtable->returnType = this->returnType;
  if(stmtBody != NULL){
    stmtBody->Check();
    if( Node::symtable->returnType != Type::voidType && Node::symtable->returnFlag == false ){
      ReportError::ReturnMissing(this);
    }
    else{
      Node::symtable->returnFlag = false;
    }
  }
  //popping scope
  symtable->popScope();
}

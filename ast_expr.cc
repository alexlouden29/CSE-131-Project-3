/* File: ast_expr.cc
 * -----------------
 * Implementation of expression node classes.
 */

#include <string.h>
#include "ast_expr.h"
#include "ast_type.h"
#include "ast_decl.h"
#include "symtable.h"
#include "errors.h"

/*** Expr Checks ***/

//Checks for incompatible types between operands.
Type* AssignExpr::CheckWithType(){
  if(!left->type->Type::IsConvertibleTo(right->type)){
    ReportError::IncompatibleOperands(op, left->type, right->type);
    return Type::errorType;
  }
  return left->type;
}

//Checks that both operands are boolean for logical expressions
//Boolean only
Type* LogicalExpr::CheckWithType(){
  if(left->type->Type::IsConvertibleTo(Type::boolType) &&
     right->type->Type::IsConvertibleTo(Type::boolType)){
    return Type::boolType;
  }
  else{
    ReportError::IncompatibleOperands(op, left->type, right->type);
    return Type::errorType;
  }
}

//Checks that operands match for comparative expressions
//Int/float only
Type* RelationalExpr::CheckWithType(){
  //One way to do it
  if(left->type->Type::IsConvertibleTo(Type::intType) &&
     left->type->Type::IsConvertibleTo(Type::floatType) &&
     right->type->Type::IsConvertibleTo(Type::intType) &&
     right->type->Type::IsConvertibleTo(Type::floatType) &&
     left->type->Type::IsConvertibleTo(right->type)){
    return left->type;
  }
  else{
    ReportError::IncompatibleOperands(op, left->type, right->type);
    return Type::errorType;
  }
}

/*** The four type setting expressions ***/

//Updates expr type and returns that type.
Type* BoolConstant::CheckWithType(){
  type = Type::boolType;
  return type;
}

//Updates expr type and returns that type.
Type* FloatConstant::CheckWithType(){
  type = Type::floatType;
  return type;
}

//Updates expr type and returns that type.
Type* IntConstant::CheckWithType(){
  type = Type::intType;
  return type;
}

//Checks if variable is in scope, if not return error and set to errorType.
Type* VarExpr::CheckWithType(){
  VarDecl* vType = (VarDecl*)Node::symtable->lookup(id->GetName());
  if(vType == NULL){ 
    ReportError::IdentifierNotDeclared(this->GetIdentifier(), reasonT(1));
    return Type::errorType;
  }
  type = vType->GetType();
  return type;
}



/*** Their Shit ***/

IntConstant::IntConstant(yyltype loc, int val) : Expr(loc) {
    value = val;
}
void IntConstant::PrintChildren(int indentLevel) { 
    printf("%d", value);
}

FloatConstant::FloatConstant(yyltype loc, double val) : Expr(loc) {
    value = val;
}
void FloatConstant::PrintChildren(int indentLevel) { 
    printf("%g", value);
}

BoolConstant::BoolConstant(yyltype loc, bool val) : Expr(loc) {
    value = val;
}
void BoolConstant::PrintChildren(int indentLevel) { 
    printf("%s", value ? "true" : "false");
}

VarExpr::VarExpr(yyltype loc, Identifier *ident) : Expr(loc) {
    Assert(ident != NULL);
    this->id = ident;
}

void VarExpr::PrintChildren(int indentLevel) {
    id->Print(indentLevel+1);
}

Operator::Operator(yyltype loc, const char *tok) : Node(loc) {
    Assert(tok != NULL);
    strncpy(tokenString, tok, sizeof(tokenString));
}

void Operator::PrintChildren(int indentLevel) {
    printf("%s",tokenString);
}

bool Operator::IsOp(const char *op) const {
    return strcmp(tokenString, op) == 0;
}

CompoundExpr::CompoundExpr(Expr *l, Operator *o, Expr *r) 
  : Expr(Join(l->GetLocation(), r->GetLocation())) {
    Assert(l != NULL && o != NULL && r != NULL);
    (op=o)->SetParent(this);
    (left=l)->SetParent(this); 
    (right=r)->SetParent(this);
}

CompoundExpr::CompoundExpr(Operator *o, Expr *r) 
  : Expr(Join(o->GetLocation(), r->GetLocation())) {
    Assert(o != NULL && r != NULL);
    left = NULL; 
    (op=o)->SetParent(this);
    (right=r)->SetParent(this);
}

CompoundExpr::CompoundExpr(Expr *l, Operator *o) 
  : Expr(Join(l->GetLocation(), o->GetLocation())) {
    Assert(l != NULL && o != NULL);
    (left=l)->SetParent(this);
    (op=o)->SetParent(this);
}

void CompoundExpr::PrintChildren(int indentLevel) {
   if (left) left->Print(indentLevel+1);
   op->Print(indentLevel+1);
   if (right) right->Print(indentLevel+1);
}
   
ConditionalExpr::ConditionalExpr(Expr *c, Expr *t, Expr *f)
  : Expr(Join(c->GetLocation(), f->GetLocation())) {
    Assert(c != NULL && t != NULL && f != NULL);
    (cond=c)->SetParent(this);
    (trueExpr=t)->SetParent(this);
    (falseExpr=f)->SetParent(this);
}

void ConditionalExpr::PrintChildren(int indentLevel) {
    cond->Print(indentLevel+1, "(cond) ");
    trueExpr->Print(indentLevel+1, "(true) ");
    falseExpr->Print(indentLevel+1, "(false) ");
}
ArrayAccess::ArrayAccess(yyltype loc, Expr *b, Expr *s) : LValue(loc) {
    (base=b)->SetParent(this); 
    (subscript=s)->SetParent(this);
}

void ArrayAccess::PrintChildren(int indentLevel) {
    base->Print(indentLevel+1);
    subscript->Print(indentLevel+1, "(subscript) ");
}
     
FieldAccess::FieldAccess(Expr *b, Identifier *f) 
  : LValue(b? Join(b->GetLocation(), f->GetLocation()) : *f->GetLocation()) {
    Assert(f != NULL); // b can be be NULL (just means no explicit base)
    base = b; 
    if (base) base->SetParent(this); 
    (field=f)->SetParent(this);
}


void FieldAccess::PrintChildren(int indentLevel) {
    if (base) base->Print(indentLevel+1);
    field->Print(indentLevel+1);
}

Call::Call(yyltype loc, Expr *b, Identifier *f, List<Expr*> *a) : Expr(loc)  {
    Assert(f != NULL && a != NULL); // b can be be NULL (just means no explicit base)
    base = b;
    if (base) base->SetParent(this);
    (field=f)->SetParent(this);
    (actuals=a)->SetParentAll(this);
}

void Call::PrintChildren(int indentLevel) {
   if (base) base->Print(indentLevel+1);
   if (field) field->Print(indentLevel+1);
   if (actuals) actuals->PrintAll(indentLevel+1, "(actuals) ");
}


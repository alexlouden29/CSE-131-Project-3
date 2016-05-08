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

//Function Call check
Type* Call::CheckWithType(){
  FnDecl* fDecl = (FnDecl*)Node::symtable->lookup(field->GetName());
  if(fDecl == NULL){
    ReportError::NotAFunction(field);
    type = Type::errorType;
    return type;
  }
  int fsize = fDecl->GetFormals()->NumElements();
  //Too many formals
  if( actuals->NumElements() > fsize ){
    ReportError::ExtraFormals(field, fsize, actuals->NumElements());
    type = Type::errorType;
    return type;
  }
  //Too few formals
  if( actuals->NumElements() < fsize ){
    ReportError::LessFormals(field, fsize, actuals->NumElements());
    type = Type::errorType;
    return type;
  }
  //Check arg types
  for(int x = 0; x < actuals->NumElements(); x++){
    Type* actualType = actuals->Nth(x)->CheckWithType();
    Type* formalType = fDecl->GetType();
    if(!actualType->IsConvertibleTo(formalType) &&
       !formalType->IsConvertibleTo(actualType) ) {
      ReportError::FormalsTypeMismatch(field, x, formalType, actualType);
      type = Type::errorType;
      return type;
    }
  }
  //Return return type of function
  return fDecl->GetType();
}

//Field Access
Type* FieldAccess::CheckWithType(){
  //Check if called on a vec or mat type
  Type* btype = base->CheckWithType();
  if(btype == Type::mat2Type)
    btype = Type::vec2Type;
  if(btype == Type::mat3Type)
    btype = Type::vec3Type;
  if(btype == Type::mat4Type)
    btype = Type::vec4Type;
  if(!(btype->IsVector() || btype->IsError())){
    ReportError::InaccessibleSwizzle(field, base);
    type = Type::errorType;
    return type;
  }
  //Check if swizzle is indeed a swizzle, or whatever
  string s = field->GetName();
  string::size_type i;
  for(i = 0; i < s.size(); i++){
    //Check swizzle letters are right
    if(s[i] != 'x' && s[i] != 'y' && s[i] != 'z' && s[i] != 'w' ){
      ReportError::InvalidSwizzle(field, base);
      type = Type::errorType;
      return type;
    }
    //Check if letters out of bounds
    if(btype == Type::vec2Type && s[i] != 'x' && s[i] != 'y' ){
      ReportError::SwizzleOutOfBound(field, base);
      type = Type::errorType;
      return type;
    }
    if(btype == Type::vec3Type && s[i] != 'x' && s[i] != 'y' && s[i] != 'z' ){
      ReportError::SwizzleOutOfBound(field, base);
      type = Type::errorType;
      return type;
    }
    //Check if swizzle is too long
    if(i > 4){
      ReportError::OversizedVector(field, base);
      type = Type::errorType;
      return type;
    }
  }
  if(i==2){
    //base->type = Type::vec2Type;
    type = Type::Type::vec2Type;
    return type;
  }
  if(i==3){
    //base->type = Type::vec3Type;
    type = Type::vec3Type;
    return type;
  }
  if(i==3){
    //base->type = Type::vec4Type;
    type = Type::vec4Type;
    return type;
  }
  else {
    type = btype;
    return type;
  }
}

//Check Array sutff
Type* ArrayAccess::CheckWithType(){
  VarExpr* vExpr = (VarExpr*)base;
  ArrayType* baseType = dynamic_cast<ArrayType*>(vExpr->CheckWithType());
  //If arrayType
  if(baseType != NULL){
    type = baseType->GetElemType();
    return type;
  }
  if(vExpr->CheckWithType()->IsMatrix() ){
    type = vExpr->type;
    return type;
  }
  VarExpr* vbase = (VarExpr*)base;
  ReportError::NotAnArray(vbase->GetIdentifier());
  type = Type::errorType;
  return type;
}

//Checks that it is an int or float so that it can be incremented.
Type* PostfixExpr::CheckWithType(){
  if(left->CheckWithType()->Type::IsConvertibleTo(Type::intType) ||
     left->CheckWithType()->Type::IsConvertibleTo(Type::floatType)){
    type = left->type;
    return type;
  }
  ReportError::IncompatibleOperand(op, left->type);
  type = Type::errorType;
  return type;
}

//Same as Relational except for when left is null.
Type* ArithmeticExpr::CheckWithType(){
  //One variable expr
  if(left == NULL){
    if(right->CheckWithType()->Type::IsConvertibleTo(Type::intType) ||
       right->CheckWithType()->Type::IsConvertibleTo(Type::floatType)){
      type = right->type;
      return type;
    }
    ReportError::IncompatibleOperand(op, right->CheckWithType());
    type = Type::errorType;
    return type;
  }
  //Two variable expr
  //One way to do it
  //cout << "HI FROM ARITHMETIC EXPR FUCKER" << endl;
  if((left->CheckWithType()->Type::IsConvertibleTo(Type::intType) ||
     left->type->Type::IsConvertibleTo(Type::floatType)) &&
     (right->CheckWithType()->Type::IsConvertibleTo(Type::intType) ||
     right->type->Type::IsConvertibleTo(Type::floatType)) &&
     left->type->Type::IsConvertibleTo(right->type)){
    type = left->type;
    return type;
  }
  else{
    //cout << "HI FROM ARITHMETIC ERROR FUCKER" << endl;
    ReportError::IncompatibleOperands(op, left->type, right->type);
    type = Type::errorType;
    return type;
  }
}

//Same as assignExpr, checks that types are the same.
Type* EqualityExpr::CheckWithType(){
  //cout << "HI FROM EQUALITY EXPR FUCKER" << endl;
  left->CheckWithType();
  right->CheckWithType();
  if(!left->type->Type::IsConvertibleTo(right->type) &&
     !right->type->Type::IsConvertibleTo(left->type)){
    //cout << "EQUALITY ERROR FUCKER" << endl;
    ReportError::IncompatibleOperands(op, left->type, right->type);
    type = Type::errorType;
    return type;
  }
  type = Type::boolType;
  return type;
}

//Checks for incompatible types between operands.
Type* AssignExpr::CheckWithType(){
  //cout << "HI FROM ASSIGN EXPR FUCKER" << endl;
  left->CheckWithType();
  right->CheckWithType();
  if(!left->type->Type::IsConvertibleTo(right->type) &&
      !right->type->Type::IsConvertibleTo(left->type)){
    //cout << "ASSIGN ERROR FUCKER" << endl;
    ReportError::IncompatibleOperands(op, left->type, right->type);
    type = Type::errorType;
    return type;
  }
  type = left->type;
  return type;
}

//Checks that both operands are boolean for logical expressions
//Boolean only
Type* LogicalExpr::CheckWithType(){
  left->CheckWithType();
  right->CheckWithType();
  if(left->type->Type::IsConvertibleTo(Type::boolType) &&
     right->type->Type::IsConvertibleTo(Type::boolType)){
    type = Type::boolType;
    return type;
  }
  else{
    ReportError::IncompatibleOperands(op, left->type, right->type);
    type = Type::errorType;
    return type;
  }
}

//Checks that operands match for comparative expressions
//Int or float only
Type* RelationalExpr::CheckWithType(){
  //Force types to be set.
  left->CheckWithType();
  right->CheckWithType();
  //One way to do it
  if((left->type->Type::IsConvertibleTo(Type::intType) ||
     left->type->Type::IsConvertibleTo(Type::floatType)) &&
     (right->type->Type::IsConvertibleTo(Type::intType) ||
     right->type->Type::IsConvertibleTo(Type::floatType)) &&
     left->type->Type::IsConvertibleTo(right->type)){
    type = Type::boolType;
    return type;
  }
  else{
    ReportError::IncompatibleOperands(op, left->type, right->type);
    type = Type::errorType;
    return type;
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
  //cout << "HI FROM VAR EXPR FUCKER" << endl;
  VarDecl* vType = (VarDecl*)Node::symtable->lookup(id->GetName());
  if(vType == NULL){ 
    //cout << "HI FROM VAR EXPR ERROR FUCKER" << endl;
    ReportError::IdentifierNotDeclared(this->GetIdentifier(), reasonT(1));
    type = Type::errorType;
    return type;
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


/* File: ast_stmt.cc
 * -----------------
 * Implementation of statement node classes.
 */
#include "ast_stmt.h"
#include "ast_type.h"
#include "ast_decl.h"
#include "ast_expr.h"
#include "errors.h"
#include "symtable.h"

Program::Program(List<Decl*> *d) {
    Assert(d != NULL);
    (decls=d)->SetParentAll(this);
}

void Program::PrintChildren(int indentLevel) {
    decls->PrintAll(indentLevel+1);
    printf("\n");
}

void Program::Check() {
    /* pp3: here is where the semantic analyzer is kicked off.
     *      The general idea is perform a tree traversal of the
     *      entire program, examining all constructs for compliance
     *      with the semantic rules.  Each node can have its own way of
     *      checking itself, which makes for a great use of inheritance
     *      and polymorphism in the node classes.
     */

    // sample test - not the actual working code
    // replace it with your own implementation
    if ( decls->NumElements() > 0 ) {
      for ( int i = 0; i < decls->NumElements(); ++i ) {
        Decl *d = decls->Nth(i);
        //Our Code
        //Create first scope.
        scope s;
        Node::symtable->pushScope(s);
        //Start checking.
        d->Check();
      }
    }
}

StmtBlock::StmtBlock(List<VarDecl*> *d, List<Stmt*> *s) {
    Assert(d != NULL && s != NULL);
    (decls=d)->SetParentAll(this);
    (stmts=s)->SetParentAll(this);
}

void StmtBlock::PrintChildren(int indentLevel) {
    decls->PrintAll(indentLevel+1);
    stmts->PrintAll(indentLevel+1);
}

void StmtBlock::Check(){
    if(Node::symtable->forFlag == false || Node::symtable->whileFlag == false
       || Node::symtable->ifFlag == false){
        scope s;
        Node::symtable->pushScope(s);
    }
    List<Stmt*> *stmtList = this->stmts;
    Stmt *stmt = NULL;
    for(int i = 0; i < stmtList->NumElements(); i++){
        stmt = stmtList->Nth(i);
        Stmt::Check();
    }
}

DeclStmt::DeclStmt(Decl *d) {
    Assert(d != NULL);
    (decl=d)->SetParent(this);
}

void DeclStmt::PrintChildren(int indentLevel) {
    decl->Print(indentLevel+1);
}

void DeclStmt::Check(){
    decl->CheckID(decl->GetIdentifier());
}

ConditionalStmt::ConditionalStmt(Expr *t, Stmt *b) { 
    Assert(t != NULL && b != NULL);
    (test=t)->SetParent(this); 
    (body=b)->SetParent(this);
    
}

ForStmt::ForStmt(Expr *i, Expr *t, Expr *s, Stmt *b): LoopStmt(t, b) { 
    Assert(i != NULL && t != NULL && b != NULL);
    (init=i)->SetParent(this);
    step = s;
    if ( s )
      (step=s)->SetParent(this);
    
}

void ForStmt::PrintChildren(int indentLevel) {
    init->Print(indentLevel+1, "(init) ");
    test->Print(indentLevel+1, "(test) ");
    if ( step )
      step->Print(indentLevel+1, "(step) ");
    body->Print(indentLevel+1, "(body) ");
}

void ForStmt::Check(){
    scope s;
    Node::symtable->pushScope(s);
    Node::symtable->forFlag = true;
    Expr *e = this ->init;
    e->CheckWithType();
    Expr *t = this -> test;
    t -> CheckWithType();
    Expr *step = this -> step;
    step -> CheckWithType();
    Stmt *stmt = this -> body;
    stmt->Check();
    Node::symtable->forFlag = false;
    if(Node::symtable->breakFlag != true){
        Node::symtable->popScope();
    }
    else{
        Node::symtable->breakFlag = false;
    }
}

void WhileStmt::PrintChildren(int indentLevel) {
    test->Print(indentLevel+1, "(test) ");
    body->Print(indentLevel+1, "(body) ");
}

void WhileStmt::Check(){
    scope s;
    Node::symtable->pushScope(s);
    Node::symtable->whileFlag = true;
    Expr *t = this -> test;
    t -> CheckWithType();
    Stmt *stmt = this -> body;
    stmt->Check();
    Node::symtable->whileFlag = false;
    if(Node::symtable->breakFlag != true){
        Node::symtable->popScope();
    }
    else{
        Node::symtable->breakFlag = false;
    }
}

IfStmt::IfStmt(Expr *t, Stmt *tb, Stmt *eb): ConditionalStmt(t, tb) { 
    Assert(t != NULL && tb != NULL); // else can be NULL
    elseBody = eb;
    if (elseBody) elseBody->SetParent(this);
}

void IfStmt::PrintChildren(int indentLevel) {
    if (test) test->Print(indentLevel+1, "(test) ");
    if (body) body->Print(indentLevel+1, "(then) ");
    if (elseBody) elseBody->Print(indentLevel+1, "(else) ");
}

void IfStmt::Check(){
    scope s;
    Node::symtable->pushScope(s);
    Node::symtable->ifFlag = true;
    Expr *t = this -> test;
    t -> CheckWithType();
    Stmt *stmtThen = this -> body;
    stmtThen->Check();
    Stmt *stmtElse = this -> elseBody;
    stmtElse -> Check();
    Node::symtable->ifFlag = false;
    if(Node::symtable->breakFlag != true){
        Node::symtable->popScope();
    }
    else{
        Node::symtable->breakFlag = false;
    }
}


ReturnStmt::ReturnStmt(yyltype loc, Expr *e) : Stmt(loc) { 
    expr = e;
    if (e != NULL) expr->SetParent(this);
}

void ReturnStmt::PrintChildren(int indentLevel) {
    if ( expr ) 
      expr->Print(indentLevel+1);
}

void ReturnStmt::Check(){
    Node::symtable->returnFlag = true;
    Expr *e = this->expr;
    Type * type = e-> CheckWithType();
    if(Node::symtable->returnType != type){
        ReportError::ReturnMismatch(this, type, Node::symtable->returnType);
    }
}

SwitchLabel::SwitchLabel(Expr *l, Stmt *s) {
    Assert(l != NULL && s != NULL);
    (label=l)->SetParent(this);
    (stmt=s)->SetParent(this);
}

SwitchLabel::SwitchLabel(Stmt *s) {
    Assert(s != NULL);
    label = NULL;
    (stmt=s)->SetParent(this);
}

void SwitchLabel::PrintChildren(int indentLevel) {
    if (label) label->Print(indentLevel+1);
    if (stmt)  stmt->Print(indentLevel+1);
}

SwitchStmt::SwitchStmt(Expr *e, List<Stmt *> *c, Default *d) {
    Assert(e != NULL && c != NULL && c->NumElements() != 0 );
    (expr=e)->SetParent(this);
    (cases=c)->SetParentAll(this);
    def = d;
    if (def) def->SetParent(this);
}

void SwitchStmt::PrintChildren(int indentLevel) {
    if (expr) expr->Print(indentLevel+1);
    if (cases) cases->PrintAll(indentLevel+1);
    if (def) def->Print(indentLevel+1);
}

void BreakStmt::Check(){
    if(Node::symtable->whileFlag != true || Node::symtable->forFlag != true){
        ReportError::BreakOutsideLoop(this);
    }
    Node::symtable->breakFlag = true;
    Node::symtable->popScope();
}

void ContinueStmt::Check(){
    if(Node::symtable->whileFlag != true || Node::symtable->forFlag != true){
        ReportError::ContinueOutsideLoop(this);
    }
}

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
      scope s;
      symtable->pushScope(&s);
      for ( int i = 0; i < decls->NumElements(); ++i ) {
        Decl *d = decls->Nth(i);
        //Our Code
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
    cout << "STMTBLOCK" << endl;
    Node *n = this->GetParent();
    StmtBlock *sBlock = dynamic_cast<StmtBlock*>(n);
    if(sBlock != NULL){
        cout << "pushing scope in stmt block" << endl;
        scope s;
        Node::symtable->pushScope(&s);
    }
    List<Stmt*> *stmtList = this->stmts;
    Stmt *stmt = NULL;
    for(int i = 0; i < stmtList->NumElements(); i++){
        stmt = stmtList->Nth(i);
        stmt->Check();
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
    cout << "declstmt" << endl;
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
    cout << "FOR" << endl;
    scope s;
    Node::symtable->pushScope(&s);
    Node::symtable->forFlag = true;
    cout << "checking expression"<<endl;
    Expr *e = this ->init;
    e->CheckWithType();
    cout << "checking test"<<endl;
    Expr *t = this -> test;
    Type *type = t -> CheckWithType();
    if( type != Type::boolType){
        ReportError::TestNotBoolean(t);
    }
    cout<<"checking step"<<endl;
    Expr *step = this -> step;
    step -> CheckWithType();
    cout << "checking FOR stmt body"<<endl;
    Stmt *stmt = this -> body;
    stmt->Check();
    if(Node::symtable->breakFlag != true){
        Node::symtable->popScope();
    }
    else{
        Node::symtable->breakFlag = false;
    }
    Node::symtable->forFlag = false;
}

void WhileStmt::PrintChildren(int indentLevel) {
    test->Print(indentLevel+1, "(test) ");
    body->Print(indentLevel+1, "(body) ");
}

void WhileStmt::Check(){
    cout << "WHILE" << endl;
    scope s;
    Node::symtable->pushScope(&s);
    Node::symtable->whileFlag = true;
    Expr *t = this -> test;
    Type *type = t -> CheckWithType();
    if( type != Type::boolType){
        ReportError::TestNotBoolean(t);
    }
    Stmt *stmt = this -> body;
    stmt->Check();
    if(Node::symtable->breakFlag != true){
        Node::symtable->popScope();
    }
    else{
        Node::symtable->breakFlag = false;
        if(Node::symtable->ifFlag == true){
            Node::symtable->popScope();
        }
    }
    Node::symtable->whileFlag = false;
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
    cout << "IF" << endl;
    scope s;
    Node::symtable->pushScope(&s);
    Node::symtable->ifFlag = true;
    Expr *t = this -> test;
    Type *type = t -> CheckWithType();
    if( type != Type::boolType){
        ReportError::TestNotBoolean(t);
    }
    Stmt *stmtThen = this -> body;
    stmtThen->Check();
    Stmt *stmtElse = this -> elseBody;
    if (stmtElse != NULL){
        scope ss;
        Node::symtable->pushScope(&ss);
        stmtElse -> Check();
        Node::symtable->popScope();
    }
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
    cout << "RETURN" << endl;
    Node::symtable->returnFlag = true;
    Expr *e = this->expr;
    if( e != NULL){
        Type * type = e-> CheckWithType();
        if(!type->IsConvertibleTo(symtable->returnType) && 
           !symtable->returnType->IsConvertibleTo(type)){
            ReportError::ReturnMismatch(this, type, Node::symtable->returnType);
        }
    }
    else{
        if(!symtable->returnType->IsConvertibleTo(Type::voidType)){
            ReportError::ReturnMismatch(this, Type::voidType, symtable->returnType);
        }
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

void Case::Check(){
    cout << "case" << endl;
    Expr *e = this->label;
    e->CheckWithType();
    Stmt *s = this->stmt;
    s->Check();
}

void Default::Check(){
    cout << "default" << endl;
    Stmt *s = this->stmt;
    s->Check();
}

void SwitchLabel::Check(){
    cout << "switchlabel"<<endl;
    if(this->label != NULL){
        this->label->CheckWithType();
    }
    
}

void SwitchStmt::Check(){
    cout << "switch"<<endl;
    scope s;
    Node::symtable->pushScope(&s);
    Node::symtable->switchFlag = true;
    
    Expr *e = this->expr;
    Type *t = e->CheckWithType();

    List<Stmt*> *c = this->cases;
    Stmt *st = NULL;
    cout << "NUM ELEMENTS = " << c->NumElements()<<endl;
    for(int i = 0; i < c->NumElements(); i++){
        st = c->Nth(i);
        st->Check();
    }
    cout << "about to check default" << endl;
    Default *d = this -> def;
    if( d != NULL){
        d->Check();
    }
    if(Node::symtable->breakFlag != true){
        Node::symtable->popScope();
    }
    else{
        Node::symtable->breakFlag = false;
    }
    Node::symtable->switchFlag = false;
}

void BreakStmt::Check(){
    cout << "IN BREAK" << endl;
    Node *n = this->GetParent();
    ForStmt *fStmt = dynamic_cast<ForStmt*>(n);
    WhileStmt *wStmt = dynamic_cast<WhileStmt*>(n);
    SwitchStmt *sStmt = dynamic_cast<SwitchStmt*>(n);
    StmtBlock *sBlock = dynamic_cast<StmtBlock*>(n);
    
    if(sBlock == NULL){
        cout << "breakStmt sBlock is NULL"<<endl;
        if(fStmt != NULL || wStmt != NULL){
            Node::symtable->breakFlag = true;
            Node::symtable->popScope();
            return;
        }
        ReportError::BreakOutsideLoop(this);
    }

    int counter = 0;
    while(n!=NULL){
        fStmt = dynamic_cast<ForStmt*>(n);
        wStmt = dynamic_cast<WhileStmt*>(n);
        sStmt = dynamic_cast<SwitchStmt*>(n);
        sBlock = dynamic_cast<StmtBlock*>(n);

        if(sBlock!=NULL){
            Node *gma = n->GetParent();
            if(gma != NULL){
                fStmt = dynamic_cast<ForStmt*>(gma);
                wStmt = dynamic_cast<WhileStmt*>(gma);
                sStmt = dynamic_cast<SwitchStmt*>(gma);
                if(fStmt != NULL || wStmt != NULL || sStmt != NULL){
                    Node::symtable->breakFlag = true;
                    for( int i = 0; i < counter;i++){
                        Node::symtable->popScope();
                    }
                    symtable->breakFlag = true;
                    return;
                }
                else{
                    n = gma->GetParent();
                    counter ++;
                }
            }
        }
        else{
            ReportError::BreakOutsideLoop(this);
            return;
        }
    }
}

void ContinueStmt::Check(){
    cout << "CONTINUE" << endl;
    Node *n = this->GetParent();
    ForStmt *fStmt = dynamic_cast<ForStmt*>(n);
    WhileStmt *wStmt = dynamic_cast<WhileStmt*>(n);
    StmtBlock *sBlock = dynamic_cast<StmtBlock*>(n);
    SwitchStmt *sStmt = dynamic_cast<SwitchStmt*>(n);
    
    if(sBlock == NULL){
        if(fStmt != NULL || wStmt != NULL){
            return;
        }
        ReportError::ContinueOutsideLoop(this);
    }

    while(n!=NULL){
        fStmt = dynamic_cast<ForStmt*>(n);
        wStmt = dynamic_cast<WhileStmt*>(n);
        sBlock = dynamic_cast<StmtBlock*>(n);
        sStmt = dynamic_cast<SwitchStmt*>(n);

        if(sBlock!=NULL){
            cout << "sBlock not null"<<endl;
            Node *gma = n->GetParent();
            if(gma != NULL){
                cout << "gma not null" << endl;
                fStmt = dynamic_cast<ForStmt*>(gma);
                wStmt = dynamic_cast<WhileStmt*>(gma);
                sStmt = dynamic_cast<SwitchStmt*>(gma);
                if(fStmt != NULL || wStmt != NULL){
                    if(wStmt != NULL) {cout<<"wStmt"<<endl;}
                    cout << "not here" << endl;
                    return;
                }
                else if(sStmt != NULL){
                    cout << "switch stmt not null" <<endl;
                    ReportError::ContinueOutsideLoop(this);
                    return;
                }
                else{
                    n = gma->GetParent();
                }
            }
        }
        else{
            ReportError::ContinueOutsideLoop(this);
            return;
        }
    }
}

%require "3.2"

%language "C++"
%skeleton "lalr1.cc"

%define api.value.type variant

%define parse.trace
%define parse.lac full

%define parse.error detailed
%locations

%param { Driver* driver }

%code requires {
#include <string>

#include <ast/ast.hpp>

class Driver;

}

%code {
#include <driver/driver.hpp>

parser::token_type yylex(parser::semantic_type *yylval, parser::location_type *yylloc, Driver *driver);

}

%token
    ROUND_BR_OPEN
    ROUND_BR_CLOSE
    CURLY_BR_OPEN
    CURLY_BR_CLOSE

    PLUS
    MINUS
    ASTERISK
    SLASH

    LESS
    LESS_EQUAL
    GREATER
    GREATER_EQUAL
    EQUAL
    NOT_EQUAL

    ASSIGN

    SEMICOLON
    COMMA

    INT_TYPE
    VOID_TYPE
    STRING_TYPE

    IF
    WHILE
    RETURN
;

%token <std::string> ID;

%token <IntVal *> INT_VAL;

%token <StrVal *> STRING_VAL;

%nterm <ValType> ValType;

%nterm <BinOpKind> CmpOp;

%nterm <ChainNode *>
    AST
    GlobDef
    Statement
;

%nterm <VarDef *> VarDef;
%nterm <FuncDef *> FuncDef;
%nterm <FuncArg *> FuncArg;
%nterm <FuncArg *> FuncArgNonEmpty;

%nterm <Return *> Return;
%nterm <While *> While;
%nterm <If *> If;
%nterm <ExprStmt *> ExprStmt;

%nterm <CallArg *> CallArg;
%nterm <CallArg *> CallArgNonEmpty;

%nterm <InterfaceExpr *>
    Expression
    Compare
    AddSub
    MulDiv
    Unary
    ExprBr
    Value
    Call
;

%%

AST:
    GlobDef { driver->setASTRoot($1); YYACCEPT; }
;

GlobDef:
    FuncDef GlobDef { $1->append($2); $$ = $1; } |
    VarDef GlobDef { $1->append($2); $$ = $1; } |
    %empty { $$ = nullptr; }
;

FuncDef:
    ValType ID ROUND_BR_OPEN FuncArg ROUND_BR_CLOSE CURLY_BR_OPEN Statement CURLY_BR_CLOSE
        { $$ = driver->create<FuncDef>($1, $2, $4, $7); }
;

FuncArg:
    FuncArgNonEmpty { $$ = $1; } |
    %empty { $$ = nullptr; }
;

FuncArgNonEmpty:
    ValType ID COMMA FuncArgNonEmpty
        { $$ = driver->create<FuncArg>($1, $2); $$->append($4); } |
    ValType ID
        { $$ = driver->create<FuncArg>($1, $2); }
;

Statement:
    Return Statement { $1->append($2); $$ = $1; } |
    While Statement { $1->append($2); $$ = $1; } |
    If Statement { $1->append($2); $$ = $1; } |
    VarDef Statement { $1->append($2); $$ = $1; } |
    ExprStmt Statement { $1->append($2); $$ = $1; } |
    %empty { $$ = nullptr; }
;

Return:
    RETURN Expression SEMICOLON { $$ = driver->create<Return>($2); }
;

While:
    WHILE ROUND_BR_OPEN Expression ROUND_BR_CLOSE CURLY_BR_OPEN Statement CURLY_BR_CLOSE
        { $$ = driver->create<While>($3, $6); }
;

If:
    IF ROUND_BR_OPEN Expression ROUND_BR_CLOSE CURLY_BR_OPEN Statement CURLY_BR_CLOSE
        { $$ = driver->create<If>($3, $6); }
;

VarDef:
    ValType ID ASSIGN Expression SEMICOLON
        { $$ = driver->create<VarDef>($1, $2, $4); }
;

ValType:
    INT_TYPE { $$ = ValType::INT; } |
    VOID_TYPE { $$ = ValType::VOID; } |
    STRING_TYPE { $$ = ValType::STRING; }
;

ExprStmt:
    Expression SEMICOLON { $$ = driver->create<ExprStmt>($1); }
;

Expression:
    Compare { $$ = $1; } |
    ID ASSIGN Expression { $$ = driver->create<Assign>($1, $3); }
;

Compare:
    AddSub { $$ = $1; } |
    Compare CmpOp AddSub { $$ = driver->create<BinOp>($2, $1, $3); }
;

CmpOp:
    LESS { $$ = BinOpKind::CMP_LESS; } |
    LESS_EQUAL { $$ = BinOpKind::CMP_LESS_EQUAL; } |
    GREATER { $$ = BinOpKind::CMP_GREATER; } |
    GREATER_EQUAL { $$ = BinOpKind::CMP_GREATER_EQUAL; } |
    EQUAL { $$ = BinOpKind::CMP_EQUAL; } |
    NOT_EQUAL { $$ = BinOpKind::CMP_NOT_EQUAL; }
;

AddSub:
    MulDiv { $$ = $1; } |
    AddSub PLUS MulDiv
        { $$ = driver->create<BinOp>(BinOpKind::ADD, $1, $3); } |
    AddSub MINUS MulDiv
        { $$ = driver->create<BinOp>(BinOpKind::SUB, $1, $3); }
;

MulDiv:
    Unary { $$ = $1; } |
    MulDiv ASTERISK Unary
        { $$ = driver->create<BinOp>(BinOpKind::MUL, $1, $3); } |
    MulDiv SLASH Unary
        { $$ = driver->create<BinOp>(BinOpKind::DIV, $1, $3); }
;

Unary:
    ExprBr { $$ = $1; } |
    PLUS ExprBr
        { $$ = driver->create<UnOp>(UnOpKind::PLUS, $2); } |
    MINUS ExprBr
        { $$ = driver->create<UnOp>(UnOpKind::MINUS, $2); }
;

ExprBr:
    Value { $$ = $1; } |
    ROUND_BR_OPEN Expression ROUND_BR_CLOSE { $$ = $2; }
;

Value:
    Call { $$ = $1; } |
    INT_VAL { $$ = $1; } |
    STRING_VAL { $$ = $1; } |
    ID { $$ = driver->create<VarVal>($1); }
;

Call:
    ID ROUND_BR_OPEN CallArg ROUND_BR_CLOSE
        { $$ = driver->create<Call>($1, $3); }
;

CallArg:
    CallArgNonEmpty { $$ = $1; } |
    %empty { $$ = nullptr; }
;

CallArgNonEmpty:
    Expression COMMA CallArgNonEmpty
        { $$ = driver->create<CallArg>($1); $$->append($3); } |
    Expression
        { $$ = driver->create<CallArg>($1); }
;

%%


parser::token_type yylex(parser::semantic_type* yylval,
    parser::location_type *yylloc, Driver* driver)
{
    return driver->yylex(yylval);
}

void parser::error(const parser::location_type &loc, const std::string& msg)
{
    std::cout << loc << ':' << msg << std::endl;
}


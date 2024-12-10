%option c++
%option yylineno noyywrap

%{

#include <lang_parser.tab.hpp>

%}

WHITE_SPACE         [\n\t\v ]+
COMMENT             "//".*

IDENTIFIER          [A-Za-zА-Яа-яЁё_][A-Za-z0-9А-Яа-яЁё_]*

INT_NUM             ([1-9][0-9]*|0)

STRING_LITERAL      "\""([^"\\]|\\.)*"\""

%%

{WHITE_SPACE}           ; // skip
{COMMENT}               ; // skip

"("                     return yy::parser::token_type::ROUND_BR_OPEN;
")"                     return yy::parser::token_type::ROUND_BR_CLOSE;

"{"                     return yy::parser::token_type::CURLY_BR_OPEN;
"}"                     return yy::parser::token_type::CURLY_BR_CLOSE;

"+"                     return yy::parser::token_type::PLUS;
"-"                     return yy::parser::token_type::MINUS;

"*"                     return yy::parser::token_type::ASTERISK;
"/"                     return yy::parser::token_type::SLASH;

"<"                     return yy::parser::token_type::LESS;
"<="                    return yy::parser::token_type::LESS_EQUAL;
">"                     return yy::parser::token_type::GREATER;
">="                    return yy::parser::token_type::GREATER_EQUAL;
"=="                    return yy::parser::token_type::EQUAL;
"!="                    return yy::parser::token_type::NOT_EQUAL;

"="                     return yy::parser::token_type::ASSIGN;

";"                     return yy::parser::token_type::SEMICOLON;
","                     return yy::parser::token_type::COMMA;

"НаМоихНогахПедали"     return yy::parser::token_type::INT_TYPE;
"ОниСмотрятНа"          return yy::parser::token_type::VOID_TYPE;
"НаМоейПодруге"         return yy::parser::token_type::STRING_TYPE;

"ЗалечуНаПодиум"        return yy::parser::token_type::IF;
"ЯТаскаю"               return yy::parser::token_type::WHILE;
"ИзКармановВылезают"    return yy::parser::token_type::RETURN;

{IDENTIFIER}            return yy::parser::token_type::ID;

{INT_NUM}               return yy::parser::token_type::INT_VAL;
{STRING_LITERAL}        return yy::parser::token_type::STRING_VAL;

.                       return yy::parser::token_type::YYerror;


%%

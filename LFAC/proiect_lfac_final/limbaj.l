%{
#include "limbaj.tab.h"
#include <stdlib.h>
#include <string.h>
%}

%%

"int"           { yylval.val_str = strdup(yytext); return TIP; }
"float"         { yylval.val_str = strdup(yytext); return TIP; }
"char"          { yylval.val_str = strdup(yytext); return TIP; }
"string"        { yylval.val_str = strdup(yytext); return TIP; }
"bool"          { yylval.val_str = strdup(yytext); return TIP; }
"class"         { return CLASS; }
"void"            { yylval.val_str = strdup(yytext); return VOID; }
"if"            { return IF; }
"else"          { return ELSE; }
"elif"          { return ELIF; }
"while"         { return WHILE; }
"for"           { return FOR; }
"return"        { return RETURN; }
"true"          { yylval.val_str = strdup(yytext); return BOOL; }
"false"         { yylval.val_str = strdup(yytext); return BOOL; }
"Print"         { return PRINT; }
"TypeOf"        { return TYPEOF; }
"begin_progr"   { return BGIN; }
"end_progr"     { return END; }

[\-]*[0-9]+          { yylval.val_str = strdup(yytext); return INTEGER; }
[\-]*[0-9]+\.[0-9]+  { yylval.val_str = strdup(yytext); return FLOAT; }
[a-zA-Z_][a-zA-Z0-9_]* { yylval.val_str = strdup(yytext); return NUME; }

"{"             { return '{'; }
"}"             { return '}'; }
"("             { return '('; }
")"             { return ')'; }
"["             { return '['; }
"]"             { return ']'; }
";"             { return ';'; }
","             { return ','; }
"="             {yylval.val_str = strdup(yytext);  return '='; }
"+"             {yylval.val_str = strdup(yytext);  return '+'; }
"-"             {yylval.val_str = strdup(yytext);  return '-'; }
"*"             {yylval.val_str = strdup(yytext);  return '*'; }
"/"             {yylval.val_str = strdup(yytext);  return '/'; }
"%"             {yylval.val_str = strdup(yytext);  return '%'; }
"=="            {yylval.val_str = strdup(yytext);  return EQUAL; }
"!="            {yylval.val_str = strdup(yytext);  return NEQ; }
"<"             {yylval.val_str = strdup(yytext);  return '<'; }
"."             { return '.'; }
">"             {yylval.val_str = strdup(yytext);  return '>'; }
"<="            {yylval.val_str = strdup(yytext);  return LEQ; }
">="            {yylval.val_str = strdup(yytext);  return GEQ; }
"&&"            { yylval.val_str = strdup(yytext); return AND; }
"||"            {yylval.val_str = strdup(yytext);  return OR; }
"!"             {yylval.val_str = strdup(yytext);  return '!'; }

"public:"       { return ACCESS; }
"private:"      { return ACCESS; }
"protected:"    { return ACCESS; }

\"[^\"]*\"      { yylval.val_str = strdup(yytext); return STRING; }
\'[^\']*\'       { yylval.val_str = strdup(yytext); return CHAR; }

[ \t]+          {  }
"\n"            { yylineno++; }
.               { return yytext[0]; }

%%

int yywrap() {
    return 1;
}

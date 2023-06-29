%{

#include <stdio.h>
#include <stdlib.h>

extern int yylex();
extern int yyparse();
extern FILE* yyin;

void yyerror(const char* s);
%}

%union{ 
    int number;
    char character;
    char* string;
}
%token <string> TYPE
%token <string> ID
%token <string> INT
%token <string> FLOAT
%token <string> CHAR
%token <string> RETURN
%token <string> RESULT
%token <string> WHILE
%token <string> IF
%token <string> ELSE
%token <string> COUNT
%token <string> IDENTIFIER
%token <string> SUM
%token <number> NUMBER
%token <string> WORD
%token <character> SEMICOLON
%token <character> EQUAL
%token <character> NOTEQUAL
%token <character> PLUS
%token <character> MINUS
%token <character> TIMES
%token <character> DIVIDE
%token <character> GREATERTHAN
%token <character> LESSTHAN
%token <character> ABS
%token <character> NOT
%token <character> AND
%token <character> COMMENT

%printer { fprintf(yyoutput, "%s", $$); } ID;

%start Program

%%

Program: DeclList
;

DeclList:   Decl DeclList
        | Decl
;   

StmtList: Stmt StmtList
        | Stmt
;

Stmt: ID EQUAL NUMBER SEMICOLON /* An assignment statement */
;


Decl: VarDecl
        | StmtList
;


VarDecl: TYPE ID SEMICOLON { printf("\n RECOGNIZED RULE: Variable declaration %s\n", $2);
//printf("Items recognized: %s, %s, %c \n", $1, $2, $3);
}
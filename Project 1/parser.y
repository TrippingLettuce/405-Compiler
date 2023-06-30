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

Program: VarDeclList StmtList {printf("The Parser has started\n");}
;

VarDeclList: {/*empty, i.e it is possible not to declare a variable*/}
	| VarDecl VarDeclList
;

VarDecl: Type ID EQ OptSemi { printf("\n RECOGNIZED RULE: Variable declaration %s\n", $2);}
;

OptSemi: SEMICOLON
| { printf("Warning: Missing semicolon. Inserting it automatically.\n"); }
;

Type: "int"
; 

StmtList: 
        | Stmt StmtList
;

Stmt: ID EQ Expr OptSemi /* An assignment statement */
        | WRITE ID OptSemi
;

Expr: Expr BinOp Expr
        | ID
        | NUMBER
;

BinOP: "+"
;
%%

int main(int argc, char**argv)
{
/*
	#ifdef YYDEBUG
		yydebug = 1;
	#endif
*/
	printf("Compiler started. \n\n");
	
	if (argc > 1){
	  if(!(yyin = fopen(argv[1], "r")))
          {
		perror(argv[1]);
		return(1);
	  }
	}
	yyparse();
}

void yyerror(const char* s) {
	fprintf(stderr, "Parse error: %s\n", s);
	exit(1);
}

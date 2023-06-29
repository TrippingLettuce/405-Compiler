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
%token <character> SEMICOLON
%token <number> NUMBER
%token <character> EQ
%token <character> BinOp
%token <character> MINUS
%token <character> WRITE

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

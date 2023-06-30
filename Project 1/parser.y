%{

#include <stdio.h>
#include <stdlib.h>

extern int yylex();
extern int yyparse();
extern FILE* yyin;

void yyerror(const char* s);
%}

%union {
	int number;
	char character;
	char* string;
}

%token <string> TYPE /* i.e.: int, char, float ...*/
%token <string> KEYWORD /* i.e: for, while, return...*/
%token <string> ID /* i.e: vairiable name: int x = 5 */
%token <char> PUNCTUATOR /*i.e: ; = {} () , ... */
%token <number> NUMBER /* 5 2.5 3.555 5/7 */
%token <string> STRVALUE /* "anything between quotes" */
%token <char> BINOP /* >= > < == && || != */
%token WRITE


%printer { fprintf(yyoutput, "%s", $$); } ID;

%start Program

%%

Program: DeclList  
;

DeclList:	Decl DeclList
	| Decl
;

Decl:	VarDecl
	| StmtList
;

VarDecl:	TYPE ID SEMICOLON	{ printf("\n RECOGNIZED RULE: Variable declaration %s\n", $2);
								  //printf("Items recognized: %s, %s, %c \n", $1, $2, $3);
								}
;

StmtList:	
	| Stmt StmtList
;

Stmt:	SEMICOLON
	| Expr SEMICOLON
;

Expr:	ID { printf("\n RECOGNIZED RULE: Simplest expression\n"); }
	| ID EQ ID 	{ printf("\n RECOGNIZED RULE: Assignment statement\n"); }
	| ID EQ NUMBER 	{ printf("\n RECOGNIZED RULE: Assignment statement\n"); }
	| WRITE ID 	{ printf("\n RECOGNIZED RULE: WRITE statement\n"); }

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

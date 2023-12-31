%option noyywrap

%{
#include <stdio.h>
#include <string.h>

#define YY_DECL int yylex()

int words = 0;
int chars = 0;
int lines = 0;

%}

letter      [a-zA-Z]
word        [a-zA-Z_][a-zA-Z0-9_]*
digit       [0-9]
ID          {letter}({letter}|{digit})*
delim       [ \t\n]
NUMBER         {digit}+(\.{digit}+)?(E[+\-]?(digit)+)?
ws          {delim}+

%%
"/*"    				{
							int c;
							while((c = input()) != 0) {
								if(c == '*') {
									if((c = input()) == '/')
										break;
									else
										unput(c);
								}
							}
						}
						
"int"	{words++; chars += strlen(yytext);
		 printf("%s : TYPE\n", yytext);
		}

"char"	{words++; chars += strlen(yytext);
		 printf("%s : TYPE\n", yytext);
		}

"float"	{words++; chars += strlen(yytext);
		 printf("%s : TYPE\n", yytext);
		}

"list" {words++; chars += strlen(yytext);
		 printf("%s : TYPE\n", yytext);
		}

"write"	{words++; 
		 chars += strlen(yytext);
		 printf("%s : KEYWORD\n", yytext);
		}

"writeln" {words++; 
		 chars += strlen(yytext);
		 printf("%s : KEYWORD\n", yytext);
		}

"return" {words++; 
		 chars += strlen(yytext);
		 printf("%s : KEYWORD\n", yytext);
		}

"read"  {words++; 
		 chars += strlen(yytext);
		 printf("%s : KEYWORD\n", yytext);
		}

"while" {words++; 
		 chars += strlen(yytext);
		 printf("%s : KEYWORD\n", yytext);
		}

"if" 	{words++; 
		 chars += strlen(yytext);
		 printf("%s : KEYWORD\n", yytext);
		}

"else"	{words++; 
		 chars += strlen(yytext);
		 printf("%s : KEYWORD\n", yytext);
		}

"main"	{words++; 
		 chars += strlen(yytext);
		 printf("%s : KEYWORD\n", yytext);
		}

{ID}	{words++; chars += strlen(yytext);
		 printf("%s : IDENTIFIER\n",yytext);
		}
			
{NUMBER}	{words++; chars += strlen(yytext);
			  printf("%s : NUMBER\n",yytext);
			}
";"		{chars++;
		 printf("%s : SEMICOLON\n", yytext);
		}
		
"="		{chars++;
		 printf("%s : EQ\n", yytext);
		}

"+"		{chars++;
		 printf("%s : BinOP\n", yytext);
		}

"-"		{chars++;
		 printf("%s : BinOP/\n", yytext);
		}

"*"		{chars++;
		 printf("%s : BinOP\n", yytext);
		}

"/"		{chars++;
		 printf("%s : BinOP\n", yytext);
		}

"=="	{chars++;
		 printf("%s : BinOP\n", yytext);
		}		

"!="	{chars++;
		 printf("%s : BinOP\n", yytext);
		}		

"<"		{chars++;
		 printf("%s : BinOP\n", yytext);
		}		

"<="	{chars++;
		 printf("%s : BinOP\n", yytext);
		}		

">"		{chars++;
		 printf("%s : BinOP\n", yytext);
		}		

">="	{chars++;
		 printf("%s : BinOP\n", yytext);
		}		

"&&"	{chars++;
		 printf("%s : BinOP\n", yytext);
		}		

"|"		{chars++;
		 printf("%s : BinOP\n", yytext);
		}		

"["		{chars++;
		 printf("%s : LBRAC\n", yytext);
		}	

"]"		{chars++;
		 printf("%s : RBRAC\n", yytext);
		}

"{"		{chars++;
		 printf("%s : LCBRAC\n", yytext);
		}	

"}"		{chars++;
		 printf("%s : RCBRAC\n", yytext);
		}	

"("		{chars++;
		 printf("%s : LPAREN\n", yytext);
		}

")"		{chars++;
		 printf("%s : RPAREN\n", yytext);
		}

","		{chars++;
		 printf("%s : COMMA\n", yytext);
		}

\n		{lines++; chars=0;}
[ \t]		{chars++;}
[\r\n]      	{lines++; chars=0;}
.		{chars++;
         printf("%s : ERROR - Unrecognized symbol at line %d char %d\n", yytext,lines,chars);
		}
		


%%
int main(int argc, char**argv)
{
	#ifdef YYDEBUG
		yydebug = 1;
	#endif

	printf("Compiler started. \n\n");

	if (argc > 1){
	  if(!(yyin = fopen(argv[1], "r")))
          {
		perror(argv[1]);
		return(1);
	  }
	}
	yylex();
}


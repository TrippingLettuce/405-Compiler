%option noyywrap

%{
#include <stdio.h>
#include <string.h>

#define YY_DECL int yylex()
#include "parser.tab.h"

int words = 0;
int chars = 0;
int charswords = 0;
int lines = 0;

%}

letter      [a-zA-Z]
digit       [0-9]
charQuote   [']
ID          {letter}({letter}|{digit})*
Char 		{charQuote}+({letter}|{digit})({letter}|{digit})*+{charQuote}
delim       [ \t\n]
NUMBER      {digit}+(\.{digit}+)?(E[+\-]?(digit)+)?
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
						
"if"	{words++; chars += strlen(yytext);
		 printf("%s : IF\n", yytext);
		 yylval.string = strdup(yytext); 
		 return IF;
		}	
		
"else"	{words++; chars += strlen(yytext);
		 printf("%s : ELSE\n", yytext);
		 yylval.string = strdup(yytext); 
		 return ELSE;
		}
		
"while"	{words++; chars += strlen(yytext);
		 printf("%s : WHILE\n", yytext);
		 yylval.string = strdup(yytext); 
		 return WHILE;
		}

"return"	{words++; chars += strlen(yytext);
		 printf("%s : RETURN\n", yytext);
		 yylval.string = strdup(yytext); 
		 return RETURN;
		}

"int"	{words++; chars += strlen(yytext);
		 printf("\n%s : TYPE\n", yytext);
		 yylval.string = strdup(yytext); 
		 return TYPE;
		}
"float"	{words++; chars += strlen(yytext);
		 printf("\n%s : TYPE\n", yytext);
		 yylval.string = strdup(yytext); 
		 return TYPE;
		}		

"char"	{words++; chars += strlen(yytext);
		 printf("\n%s : TYPE\n", yytext);
		 yylval.string = strdup(yytext); 
		 return TYPE;
		}

		
"write"	{words++; 
		 chars += strlen(yytext);
		 printf("%s : KEYWORD\n", yytext);
		 yylval.string = strdup(yytext); 
		 return WRITE;
		}

"string" {words++; chars += strlen(yytext);
		 printf("%s : TYPE\n", yytext);
		 yylval.string = strdup(yytext); 
		 return TYPE;
		}

"void"	{words++; chars += strlen(yytext);
		 printf("%s : TYPE\n", yytext);
		 yylval.string = strdup(yytext); 
		 return TYPE;
		}
		
{ID}	{words++; chars += strlen(yytext);
		 printf("%s : IDENTIFIER\n",yytext);
		 yylval.string = strdup(yytext); 
		 return ID;
		}


{NUMBER}	{words++; chars += strlen(yytext);
			 printf("%s : NUMBER\n",yytext);
	 		 yylval.string = strdup(yytext); 
	 		 return NUMBER;
			}

{Char}	{charswords++; chars += strlen(yytext);
		 printf("\n%s : Char\n", yytext);
		 yylval.string = strdup(yytext); 
		 return CHAR;
		}	


";"		{chars++;
		 printf("%s : SEMICOLON\n", yytext);
		 yylval.string = strdup(yytext); 
		 return SEMICOLON;
		}
		
","		{chars++;
		 printf("%s : COMMA\n", yytext);
		 yylval.string = strdup(yytext); 
		 return COMMA;
		}
		
"="		{chars++;
		 printf("%s : EQ\n", yytext);
		 yylval.string = strdup(yytext); 
		 return EQ;
		}

"||"	{chars++;
		 printf("%s : OR\n", yytext);
		 yylval.string = strdup(yytext); 
		 return OR;
		}

"<"	{chars++;
		 printf("%s : LSS\n", yytext);
		 yylval.string = strdup(yytext); 
		 return LSS;
		}

">"	{chars++;
		 printf("%s : GTR\n", yytext);
		 yylval.string = strdup(yytext); 
		 return GTR;
		}				

"<="	{chars++;
		 printf("%s : LEQ\n", yytext);
		 yylval.string = strdup(yytext); 
		 return LEQ;
		}

">="	{chars++;
		 printf("%s : GEQ\n", yytext);
		 yylval.string = strdup(yytext); 
		 return GEQ;
		}

"==" 	{chars++;
		printf("%s : DEQ\n", yytext);
		yylval.string = strdup(yytext); 
		return DEQ;
		}
		
"!=" 	{chars++;
		printf("%s : NEQ\n", yytext);
		yylval.string = strdup(yytext); 
		return NEQ;
		}

"("		{words++; chars += strlen(yytext);
		 printf("%s : LPAREN\n", yytext);
		 yylval.string = strdup(yytext); 
		 return LPAREN;
		}

")"		{words++; chars += strlen(yytext);
		 printf("%s : RPAREN\n", yytext);
		 yylval.string = strdup(yytext); 
		 return RPAREN;
		}	

"{"		{words++; chars += strlen(yytext);
		 printf("%s : LBRACE\n", yytext);
		 yylval.string = strdup(yytext); 
		 return LBRACE;
		}		

"}"		{words++; chars += strlen(yytext);
		 printf("%s : RBRACE\n", yytext);
		 yylval.string = strdup(yytext); 
		 return RBRACE;
		}	

"["		{words++; chars += strlen(yytext);
		 printf("%s : LBRACKET\n", yytext);
		 yylval.string = strdup(yytext); 
		 return LBRACKET;
		}	

"]"		{words++; chars += strlen(yytext);
		 printf("%s : RBRACKET\n", yytext);
		 yylval.string = strdup(yytext); 
		 return RBRACKET;
		}	
		
"+"		{words++; chars += strlen(yytext);
		 printf("%s : ADD\n", yytext);
		 yylval.string = strdup(yytext); 
		 return ADD;
		}		

"-"		{words++; chars += strlen(yytext);
		 printf("%s : SUB\n", yytext);
		 yylval.string = strdup(yytext); 
		 return SUB;
		}	

"*"		{words++; chars += strlen(yytext);
		 printf("%s : MULTIPLY\n", yytext);
		 yylval.string = strdup(yytext); 
		 return MULTIPLY;
		}	

"/"		{words++; chars += strlen(yytext);
		 printf("%s : DIV\n", yytext);
		 yylval.string = strdup(yytext); 
		 return DIV;
		}				

		
[\n]	{lines++; chars=0;}
[ \t]	{chars++;}
.		{chars++;
         printf("%s : Unrecognized symbol at line %d char %d\n", yytext,lines,chars);
		}
		

%%
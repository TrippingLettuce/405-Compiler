%option noyywrap

%{
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


#define RED  "\x1b[1;31m"
#define RESET "\x1b[0m"

#define YY_DECL int yylex()
#include  "parser.tab.h"

int words = 0;
int chars = 0;
int lines = 1;


%}

%option yylineno

NEWLINE [\n\r]
DELIM   [ \t]
WS      {DELIM}+
LETTER  [_a-zA-Z]
DIGIT   [-]?[0-9]
ID      {LETTER}({LETTER}|{DIGIT})*
NUMBER  {DIGIT}+
FLOATNUM [0-9]+["."][0-9]+
STRINGID \"([^\\\"]|\\.)*\"
CHARID \'([^\\\'']|\\.)*\'

%%  

"/*"    {
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


"char"  {
	words++; chars += strlen(yytext);
	printf("%s : TYPE CHAR\n", yytext);
    yylval.string = strdup(yytext);
    return CHAR;
}

"float"  {
	words++; chars += strlen(yytext);
	printf("%s : TYPE CHAR\n", yytext);
    yylval.string = strdup(yytext);
    return FLOAT;
}

"int"  {
	words++; chars += strlen(yytext);
	printf("%s : TYPE INT\n", yytext);
    yylval.string = strdup(yytext);
    return INT;
     
}

"void"  {
	words++; chars += strlen(yytext);
	printf("%s : TYPE VOID\n", yytext);
    yylval.string = strdup(yytext);
    return VOID;
     
}

"write"  {
	words++; chars += strlen(yytext);
	printf("%s : WRITE STATEMENT\n", yytext);
    yylval.string = strdup(yytext);
    return WRITE;
     
}

"return"  {
	words++; chars += strlen(yytext);
	printf("%s : RETURN STATEMENT\n", yytext);
    yylval.string = strdup(yytext);
    return RETURN;
     
}

"if"  {
	words++; chars += strlen(yytext);
	printf("%s : IF\n", yytext);
    yylval.string = strdup(yytext);
    return IF;
     
}

"else"  {
	words++; chars += strlen(yytext);
	printf("%s : ELSE\n", yytext);
    yylval.string = strdup(yytext);
    return ELSE;
     
}

"=="  {
	chars += 2;
	printf("%s : OPERATOR\n", yytext);
    yylval.string = strdup(yytext);
    return DEQ;
     
}

"!="  {
	chars += 2;
	printf("%s : OPERATOR\n", yytext);
    yylval.string = strdup(yytext);
    return NOTEQ;
     
}

"<="  {
	chars += 2;
	printf("%s : OPERATOR\n", yytext);
    yylval.string = strdup(yytext);
    return LEQ;
     
}

">="  {
	chars += 2;
	printf("%s : OPERATOR\n", yytext);
    yylval.string = strdup(yytext);
    return GEQ;
     
}
 
"<"  {
	chars++;
	printf("%s : OPERATOR\n", yytext);
    yylval.string = strdup(yytext);
    return LT; 
}

">"  {
	chars++;
	printf("%s : OPERATOR\n", yytext);
    yylval.string = strdup(yytext);
    return GT;
     
}

"&&"  {
	chars++;
	printf("%s : BOOLEAN OPERATOR\n", yytext);
    yylval.string = strdup(yytext);
    return AND; 
}

"||"  {
	chars++;
	printf("%s : BOOLEAN OPERATOR\n", yytext);
    yylval.string = strdup(yytext);
    return OR; 
}

"="  {
	chars++;
	printf("%s : OPERATOR\n", yytext);
    yylval.string = strdup(yytext);
    return EQ;
     
}


"+"  {
	chars++;
	printf("%s : OPERATOR\n", yytext);
    yylval.string = strdup(yytext);
    return ADD;
     
}

"*"  {
	chars++;
	printf("%s : OPERATOR\n", yytext);
    yylval.string = strdup(yytext);
    return MULTIPLY;
     
}

"-"  {
	chars++;
	printf("%s : OPERATOR\n", yytext);
    yylval.string = strdup(yytext);
    return SUB;
     
}

"/"  {
	chars++;
	printf("%s : OPERATOR\n", yytext);
    yylval.string = strdup(yytext);
    return DIV;
     
}

"^"  {
	chars++;
	printf("%s : OPERATOR\n", yytext);
    yylval.string = strdup(yytext);
    return EXPONENT;
}  

"("  {
	chars++;
	printf("%s : OPERATOR\n", yytext);
    yylval.string = strdup(yytext);
    return LPAREN;
     
}

")"  {
	chars++;
	printf("%s : OPERATOR\n", yytext);
    yylval.string = strdup(yytext);
    return RPAREN;
     
}

"["  {
	chars++;
	printf("%s : OPERATOR\n", yytext);
    yylval.string = strdup(yytext);
    return LBRACE;
     
}

"]"  {
	chars++;
	printf("%s : OPERATOR\n", yytext);
    yylval.string = strdup(yytext);
    return RBRACE;
     
}

"{"  {
	chars++;
	printf("%s : Left Bracket\n", yytext);
    yylval.string = strdup(yytext);
    return LBRACKET;
     
}

"}"  {
	chars++;
	printf("%s : Right Bracket\n", yytext);
    yylval.string = strdup(yytext);
    return RBRACKET;
     
}

","  {
	chars++;
	printf("%s : OPERATOR\n", yytext);
    yylval.string = strdup(yytext);
    return COMMA;
     
}

";"  {
	chars++;
	printf("%s : SEMICOLON\n", yytext);
	yylval.string = strdup(yytext);
    return SEMICOLON;
     
}

"~nl"  {
	chars++;
	printf("%s : NEWLINECHAR\n", yytext);
	yylval.string = strdup(yytext);
    return NEWLINECHAR;
     
}

{STRINGID}  {
	chars++;
	printf("%s : STRING LITERAL\n", yytext);
    yylval.string = strdup(yytext);
    return STRINGID;
     
}

{CHARID}  { 
	chars++;
	printf("%s : CHAR LITERAL\n", yytext);
    yylval.string = strdup(yytext);
    return CHARID;
     
}

{WS}  {

} 

{NEWLINE}  {
	lines++;
}

{ID}  {
	chars += strlen(yytext);
	printf("%s : ID\n", yytext); 
    yylval.string = strdup(yytext);
    return ID;

} 

{NUMBER}  {
	chars += strlen(yytext);
	printf("%s : NUMBER\n", yytext);
    yylval.string = strdup(yytext); 
    return NUMBER;
     
}

{FLOATNUM}  {
	chars += strlen(yytext);
	printf("%s : FLOATNUM\n", yytext);
    yylval.string = strdup(yytext); 
    return FLOATNUM;
     
}

.  {printf("%s", yytext);
	printf(RED " : Unrecognized symbol on line %d\n" RESET, lines);}

%%
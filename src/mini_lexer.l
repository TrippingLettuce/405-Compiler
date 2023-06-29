%option noyywrap
%{
int chars = 0;
int words = 0;
int lines = 0;
%}

%%
NUMBER         {digit}+(\.{digit}+)?(E[+\-]?(digit)+)?
[a-zA-Z]+ {words++; chars += strlen(yytext);
                         printf("%s : IDENTIFIER\n",yytext);
                         //return(IDENTIFIER);
}
\n {chars++; lines++;}
. {chars++;}

{NUMBER}	{words++; chars += strlen(yytext);
			  printf("%s : NUMBER\n",yytext);
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
"|"		{chars++;
		 printf("%s : BinOP\n", yytext);
		}		
\n		{lines++; chars=0;}
[ \t] { }
. { printf("Mystery character %s\n", yytext); }
%%

int main(int argc, char **argv)
{
if(argc > 1){
          if(!(yyin = fopen(argv[1],"r"))){
             perror(argv[1]);
             return(1);
          }
        }
        yylex();
printf("Lines: %8d\nWords: %8d\nChars: %8d\n", lines,words, chars);

}
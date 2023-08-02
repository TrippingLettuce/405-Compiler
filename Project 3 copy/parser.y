%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "FunctionST.h"
#include "VarST.h"
#include "AST.h"
#include "IRcode.h"
#include "Assembly.h"
#include "cal.h"
#include "logicops.h"
#include "while_ops.h"


typedef enum { F, T } boolean;

extern int yylex();
extern int yyparse();
extern FILE* yyin;
boolean FunctionFlag = F;

FILE * IRcode;
//FILE * MIPScode;

int condiotionFlag = 0;
int elseconditionBlockFlag = 0;

void yyerror(const char* s);

int sum = 0;
char curArr[50];
int arrIndex = 0;

char curFun[50];

char scope[50] = "Global";

char Global[50] = "Global";
char Local[50] = "Global";


int semanticCheckPassed = 1;
%}

%union {
	int number;
	char character;
	char* string;
	struct AST* ast;
}

%token <string> ID
%token <string> WRITE
%token <string> IF
%token <string> ELSE
%token <string> WHILE
%token <string> RETURN
%token <string> TYPE
%token <string> KEYWORD
%token <string> NUMBER
%token <string> CHAR
%token <string> SINGLE_QOUTE
%token <string> SEMICOLON
%token <string> COMMA
%token <string> EQ 
%token <string> OR
%token <string> LSS
%token <string> GTR
%token <string> LHS
%token <string> LEQ
%token <string> GEQ
%token <string> LPAREN
%token <string> RPAREN
%token <string> LBRACE
%token <string> RBRACE
%token <string> LBRACKET
%token <string> RBRACKET
%token <string> ADD
%token <string> SUB
%token <string> MULTIPLY
%token <string> DIV

%printer { fprintf(yyoutput, "%s", $$); } ID;
%printer { fprintf(yyoutput, "%d", $$); } NUMBER;
%printer { fprintf(yyoutput, "%s", $$); } CHAR;


%type <ast> Program FunDeclList FunDecl FuncallStmtList FuncallStmt ArrayDecl ArrayDeclList ParamDeclList ParamDecl DeclList Decl VarDeclList VarDecl Stmt StmtList AssignStmt WriteStmt  AssignStmtList MathStatList MathStat WriteStmtList Block Condition  ConditionBlock LogicalOp ConditionStmt ConditionList stmt_list_for_if stmt_for_if Write_stmt_for_ifs if_else_Condition_Stmt else_ConditionBlock stmt_list_for_else Write_stmt_for_else stmt_for_else WhileConditionList WhileCondition The_while_condition WhileBlock1 WhileBlock2 WhileBlock3 WhileLogicalOp WhileBinOp

%right EQ
%left ADD, SUB
%left MULTIPLY, DIV

%start Program
%%
// PARSER UPDATE
	// add funtions and add arrays to the 
	// fix current grammer to allow for multiple types of math finctions
	// update to the new grammer list


// SYMBOL TABLE UPDATE
	// add array to the symol table
	// create indipendent symbol tables for each scope
	// remove value from symbol table and have it declared in the AST


// SCOPE MANAGMENT AND MORE
	// remove global varibles and rely on the AST
	// learn how to properly handle the AST
	// create indipendent symbol tables for each scope


Program: DeclList  { $$ = $1;
					 printf("\n--- Abstract Syntax Tree ---\n\n");
					 printAST($$,0);
					}

;

DeclList:	Decl DeclList	{ $1->left = $2;
							  $$ = $1;
							}
	| Decl	{ $$ = $1; }
;

Decl: FunDeclList 
	| ConditionList
	| StmtList
	| VarDecl
	| ArrayDecl

;

FunDeclList:
			| FunDecl FunDeclList {$1->left = $2;
							  $$ = $1;}
			| FunDecl {$$ = $1;};

FunDecl:	TYPE ID LPAREN ParamDeclList RPAREN Block {printf("\nRECOGNIZED RULE: Function\n");
							
								char id1[50];
								char type[50];
								strcpy(id1, $2);
								strcpy(type, $1);
								strcpy(scope, Local);
								int inSymTab = found($2, scope);
								
								if (inSymTab == 0){
									add_Item_to_var_sym_table(id1, "Fun", $1, 0, scope);

									add_Item_to_func_sym_table(id1, "Fun", &type, 0, &id1, &scope);
								}
								else{					
									printf("SEMANTIC ERROR: Fun %s is already in the symbol table", $2);
								}
								showVarSymTable();
								showFuncSymTable();

								$$ = AST_Type("Fun", $1, $2);
								
			};

FuncallStmtList: FuncallStmt FuncallStmtList {$1->left = $2;
							  $$ = $1;}
			| FuncallStmt {$$ = $1;};

FuncallStmt: ID LPAREN ParamDeclList RPAREN SEMICOLON {printf("\nRECOGNIZED RULE: Function Call\n");
							
								char id1[50];
								strcpy(id1, $1);
								strcpy(scope, Local);
								int inSymTab = found(id1, scope);
								
								if (inSymTab == 0){
									printf("SEMANTIC ERROR: Fun %s is not in the symbol table", $1);
								}
								else{					
									

								}

								showFuncSymTable();

								$$ = AST_Type("FunCall", $1, "NULL");
								
			};

ParamDeclList: %empty
 			| ParamDecl ParamDeclList {$1->left = $2;
							  $$ = $1;}
											
			| ParamDecl {$$ = $1;}
							

ParamDecl: TYPE ID {printf("\n RECOGNIZED RULE: Variable declaration\n");						
									char id1[50];
									symTabAccess();
									int inSymTab = found($2, scope);

									
									if (inSymTab == 0) 
										add_Item_to_var_sym_table($2, "Var", $1, 0, scope);
									else						
										printf("SEMANTIC ERROR: Var %s is already in the symbol table", $2);

									showVarSymTable();
									
									sprintf(id1, "%s", $2);
									int numid = getItemID(id1, scope);   // ADDING TO IR CODE T0 = X
									emitConstantIntAssignment ($2, numid);								

									
								    $$ = AST_Type("Type",$1,$2);  	// SEMANTIC ACTIONS
								};
			| %empty


Block:	LBRACE FunBlock RBRACE

FunBlock: ArrayDeclList
		| VarDeclList
		| StmtList

LogicalOp:	LEQ
			| GEQ
			| EQ EQ
			| GTR
			| LSS
			| OR

ConditionList : Condition ConditionList {$1->left = $2;
							  $$ = $1;}
			| Condition {$$ = $1;};



Condition:  IF SUB ELSE LPAREN if_else_Condition_Stmt RPAREN LBRACE ConditionBlock RBRACE ELSE LBRACE else_ConditionBlock RBRACE SEMICOLON {
				$$ = AST_Type("IF-ELSE", $3, $10);
			
			};

		|	IF LPAREN ConditionStmt RPAREN LBRACE ConditionBlock RBRACE SEMICOLON { 
				$$ = AST_Type("IF", $3, $6);
			
			};


if_else_Condition_Stmt:%empty
		| NUMBER LogicalOp NUMBER {
			int logic = runLogic($1, $2, $3);
			printf("LOGIC: %d \n", logic);
			if (logic == 1){
				elseconditionBlockFlag = 0;
				condiotionFlag = 1;
			}
			else{
				condiotionFlag = 0;
				elseconditionBlockFlag = 1;
			}
		};
		| ID LogicalOp ID {
			int id1 = getItemID($1, scope);
			int id2 = getItemID($3, scope);
			char idVal1[50];
			char idVal2[50];
			sprintf(idVal1, "%d", id1);
			sprintf(idVal2, "%d", id2);
			int logic = runLogic(idVal1, $2, idVal2);
			printf("LOGIC: %d \n", logic);
			if (logic == 1){
				elseconditionBlockFlag = 0;
				condiotionFlag = 1;
			}
			else{
				condiotionFlag = 0;
				elseconditionBlockFlag = 1;

			}
		};
		| ID LogicalOp NUMBER {
			char ID[50];
			strcpy(ID, $1);
			int id1 = getVal(ID, scope);
			char idVal1[50];
			sprintf(idVal1, "%d", id1);
			int logic = runLogic(idVal1, $2, $3);
			printf("LOGIC: %d \n", logic);
			if (logic == 1){
				elseconditionBlockFlag = 0;
				condiotionFlag = 1;
			}
			else{
				condiotionFlag = 0;
				elseconditionBlockFlag = 1;
			}
			printf("%d \n", elseconditionBlockFlag);
		};
		| NUMBER LogicalOp ID {
			int id2 = getVal($3, scope);
			char idVal2[50];
			sprintf(idVal2, "%d", id2);
			int logic = runLogic($1, $2, idVal2);
			printf("LOGIC: %d \n", logic);
			if (logic == 1){
				elseconditionBlockFlag = 0;
				condiotionFlag = 1;
			}
			else{

				condiotionFlag = 0;
				elseconditionBlockFlag = 1;
			}
		};

ConditionStmt:  %empty
		| NUMBER LogicalOp NUMBER {
			int logic = runLogic($1, $2, $3);
			printf("LOGIC: %d \n", logic);
			if (logic == 1){
				condiotionFlag = 1;
			}
			else{
				condiotionFlag = 0;
			}
		};
		| ID LogicalOp ID {
			int id1 = getItemID($1, scope);
			int id2 = getItemID($3, scope);
			char idVal1[50];
			char idVal2[50];
			sprintf(idVal1, "%d", id1);
			sprintf(idVal2, "%d", id2);
			int logic = runLogic(idVal1, $2, idVal2);
			printf("LOGIC: %d \n", logic);
			if (logic == 1){
				condiotionFlag = 1;
			}
			else{
				condiotionFlag = 0;
			}
		};
		| ID LogicalOp NUMBER {
			char ID[50];
			strcpy(ID, $1);
			int id1 = getVal(ID, scope);
			char idVal1[50];
			sprintf(idVal1, "%d", id1);
			int logic = runLogic(idVal1, $2, $3);
			printf("LOGIC: %d \n", logic);
			if (logic == 1){
				condiotionFlag = 1;
			}
			else{
				condiotionFlag = 0;
			}
		};
		| NUMBER LogicalOp ID {
			int id2 = getVal($3, scope);
			char idVal2[50];
			sprintf(idVal2, "%d", id2);
			int logic = runLogic($1, $2, idVal2);
			printf("LOGIC: %d \n", logic);
			if (logic == 1){
				condiotionFlag = 1;
			}
			else{
				condiotionFlag = 0;
			}
		};




ConditionBlock: stmt_list_for_if
				| FunDeclList 
				| ConditionList
				| VarDeclList
				| ArrayDeclList
				| %empty;	


stmt_list_for_if: stmt_for_if stmt_list_for_if { $1->left = $2;
					$$ = $1;}
				| stmt_for_if { $$ = $1; };

stmt_for_if: AssignStmtList {printf("AssignStmt\n");}
	| MathStatList {printf("MathStat\n");}
	| Write_stmt_for_ifs {printf("WriteStmt\n");}
	| FuncallStmtList {printf("FuncallStmt\n");}

Write_stmt_for_ifs: WRITE ID SEMICOLON{ printf("\nRECOGNIZED RULE: WRITE STATMENT\n");
					if (condiotionFlag == 1){
						condiotionFlag = 0;
						char id1[50];
						sprintf(id1, "%s", $2);
						char *tyoe = getVariableType(id1, scope);
						char type[50];
						sprintf(type, "%s", tyoe);
						printf("Type: %s\n", type);
						$$ = AST_Write("write",type, $2);
						
						int numid = getItemID(id1, scope);


						// SEMANTIC ANALYSIS ACTIONS   
						if (found($2, scope) != 1) {	 
							printf("SEMANTIC ERROR: Variable %s has NOT been declared in scope %s \n", $2, scope);
							semanticCheckPassed = 0;
						}

						if (semanticCheckPassed == 1) {
							printf("\n\nRule is semantically correct!\n\n");
							// emitMIPSConstantIntAssignment(id1, id2, numid);
							if (strcmp(type, "int") == 0){
								int val = getVal($2, scope);
								char valStr[50];
								sprintf(valStr, "%d", val);
								emitMIPSConstantIntAssignment(valStr, numid);
								emitMIPSWriteId(numid);
							}
							else if(strcmp(type, "float") == 0){
								double val = getFloatVal($2, scope);
								char valStr[50];
								sprintf(valStr, "%f", val);
								char pythonCommand[50];
								sprintf(pythonCommand, "python3 WriteFloatsMips.py %s\n", valStr);
								char command[50];
								strcpy(command, pythonCommand);
							
								system(command);
								sleep(0.5);
								emitfloatAssignment();

							}
							else if(strcmp(type, "char") == 0){
								char *val = getCharVal($2, scope);
								char valStr[50];
								sprintf(valStr, "%s", val);
								char pythonCommand[50];
								sprintf(pythonCommand, "python3 writeCharToMips.py %s\n", valStr);
								char command[50];
								strcpy(command, pythonCommand);
								system(command);
								sleep(0.5);
								emitMIPSCharAssignment();
							}
				
							
						}
					}else{
						condiotionFlag = 0;
					}
				};
		| WRITE ID LBRACKET NUMBER RBRACKET SEMICOLON{ printf("\nRECOGNIZED RULE: WRITE STATMENT FOR ARRAY\n");
					if (condiotionFlag == 1)
					{
						condiotionFlag = 0;
						char id1[50];
						sprintf(id1, "%s[%s]", $2, $4);
						char *tyoe = getVariableType(id1, scope);
						char type[50];
						sprintf(type, "%s", tyoe);

						$$ = AST_Write("write",type, $2);
						
						int numid = getItemID(id1, scope);
						if (found(id1, scope) != 1) {	 
							printf("SEMANTIC ERROR: Variable %s has NOT been declared in scope %s \n", $2, scope);
							semanticCheckPassed = 0;
						}

						if (semanticCheckPassed == 1) {
							printf("\n\nRule is semantically correct!\n\n");
							if (strcmp(type, "int") == 0){
								int val = getVal(id1, scope);
								// emitWriteInt(id1, numid);
								// emitMIPSWriteInt(id1, numid);	// EMITS TO IR AND MIPS

								char valStr[50];
								sprintf(valStr, "%d", val);
								emitMIPSConstantIntAssignment(valStr, numid);	// EMITS TO IR AND MIPS

							} else if (strcmp(type, "float") == 0){
								double val = getFloatVal(id1, scope);
								char valStr[50];
								sprintf(valStr, "%lf", val);
								emitMIPSConstantIntAssignment(valStr, numid);

							} else if (strcmp(type, "char") == 0){
								char *val = getCharVal(id1, scope);
								char valStr[50];
								sprintf(valStr, "%s", val);
								emitMIPSConstantIntAssignment(valStr, numid); 				

							}
							emitMIPSWriteId(numid);
						}
					} 
					else
					{
						condiotionFlag = 0;
						elseconditionBlockFlag = 0;
					}

		};



else_ConditionBlock: stmt_list_for_else
				| FunDeclList 
				| ConditionList
				| VarDeclList
				| ArrayDeclList
				| %empty;

stmt_list_for_else: stmt_list_for_else stmt_for_else {$1->left = $2;
							  $$ = $1;}
				| stmt_for_else {$$ = $1;}

stmt_for_else: AssignStmtList {printf("AssignStmt\n");}
	| MathStatList {printf("MathStat\n");}
	| Write_stmt_for_else {printf("WriteStmt\n");}
	| FuncallStmtList {printf("FuncallStmt\n");}


Write_stmt_for_else: WRITE ID SEMICOLON{ printf("\nRECOGNIZED RULE: WRITE STATMENT\n");
					printf("%d \n", elseconditionBlockFlag);
					if (elseconditionBlockFlag == 1){
						elseconditionBlockFlag = 0;
						char id1[50];
						sprintf(id1, "%s", $2);
						char *tyoe = getVariableType(id1, scope);
						char type[50];
						sprintf(type, "%s", tyoe);
						printf("Type: %s\n", type);
						$$ = AST_Write("write",type, $2);
						
						int numid = getItemID(id1, scope);


						// SEMANTIC ANALYSIS ACTIONS   
						if (found($2, scope) != 1) {	 
							printf("SEMANTIC ERROR: Variable %s has NOT been declared in scope %s \n", $2, scope);
							semanticCheckPassed = 0;
						}

						if (semanticCheckPassed == 1) {
							printf("\n\nRule is semantically correct!\n\n");
							// emitMIPSConstantIntAssignment(id1, id2, numid);
							if (strcmp(type, "int") == 0){
								int val = getVal($2, scope);
								char valStr[50];
								sprintf(valStr, "%d", val);
								emitMIPSConstantIntAssignment(valStr, numid);
								emitMIPSWriteId(numid);
							}
							else if(strcmp(type, "float") == 0){
								double val = getFloatVal($2, scope);
								char valStr[50];
								sprintf(valStr, "%f", val);
								char pythonCommand[50];
								sprintf(pythonCommand, "python3 WriteFloatsMips.py %s\n", valStr);
								char command[50];
								strcpy(command, pythonCommand);
							
								system(command);
								sleep(0.5);
								emitfloatAssignment();

							}
							else if(strcmp(type, "char") == 0){
								char *val = getCharVal($2, scope);
								char valStr[50];
								sprintf(valStr, "%s", val);
								char pythonCommand[50];
								sprintf(pythonCommand, "python3 writeCharToMips.py %s\n", valStr);
								char command[50];
								strcpy(command, pythonCommand);
								system(command);
								sleep(0.5);
								emitMIPSCharAssignment();
							}
				
							
						}
					}else{
						condiotionFlag = 0;
						elseconditionBlockFlag = 0;
					}
				};
		| WRITE ID LBRACKET NUMBER RBRACKET SEMICOLON{ printf("\nRECOGNIZED RULE: WRITE STATMENT FOR ARRAY\n");
					if (elseconditionBlockFlag == 1)
					{
						elseconditionBlockFlag = 0;
						char id1[50];
						sprintf(id1, "%s[%s]", $2, $4);
						char *tyoe = getVariableType(id1, scope);
						char type[50];
						sprintf(type, "%s", tyoe);

						$$ = AST_Write("write",type, $2);
						
						int numid = getItemID(id1, scope);
						if (found(id1, scope) != 1) {	 
							printf("SEMANTIC ERROR: Variable %s has NOT been declared in scope %s \n", $2, scope);
							semanticCheckPassed = 0;
						}

						if (semanticCheckPassed == 1) {
							printf("\n\nRule is semantically correct!\n\n");
							if (strcmp(type, "int") == 0){
								int val = getVal(id1, scope);
								// emitWriteInt(id1, numid);
								// emitMIPSWriteInt(id1, numid);	// EMITS TO IR AND MIPS

								char valStr[50];
								sprintf(valStr, "%d", val);
								emitMIPSConstantIntAssignment(valStr, numid);	// EMITS TO IR AND MIPS

							} else if (strcmp(type, "float") == 0){
								double val = getFloatVal(id1, scope);
								char valStr[50];
								sprintf(valStr, "%lf", val);
								emitMIPSConstantIntAssignment(valStr, numid);

							} else if (strcmp(type, "char") == 0){
								char *val = getCharVal(id1, scope);
								char valStr[50];
								sprintf(valStr, "%s", val);
								emitMIPSConstantIntAssignment(valStr, numid); 				

							}
							emitMIPSWriteId(numid);
						}
					} 
					else
					{
						condiotionFlag = 0;
						elseconditionBlockFlag = 0;
					}

		};


WhileLogicalOp:	GTR{};
			| GEQ{};
			| EQ EQ{};
			| LSS{};
			| OR{};

WhileConditionList:	WhileCondition WhileConditionList {$1->left = $2;
							  $$ = $1;}
			| WhileCondition {$$ = $1;}


WhileCondition: WHILE LPAREN The_while_condition RPAREN LBRACE WhileBlock1 WhileBlock2 WhileBlock3 RBRACE {printf("\n RECOGNIZED RULE: While Condition\n");
					$$ = AST_assignment("while","cond", "block");
					FILE * WhileFile;
					char * line = NULL;
					size_t len = 0;
					ssize_t read;

					sleep(0.3);
					char command[50];
					sprintf(command, "python3 ./WhileOps/fill_json.py ");
					system(command);

					WhileFile = fopen("./WhileOps/resultes/resultes.txt", "r");
					if (WhileFile == NULL)
						exit(EXIT_FAILURE);

					while ((read = getline(&line, &len, WhileFile)) != -1) {
						printf("%s", line);
						emitConstantWhileAssignment(line);
						emitMIPSWhileAssignment(line);
					}
					fclose(WhileFile);
					};
The_while_condition: ID WhileLogicalOp ID {
					char ids[50];
					int id1Val = getVal($1, scope);
					int id2Val = getVal($3, scope);
					sprintf(ids, "\n%s=%d\n%s=%d\n", $1, id1Val, $3, id2Val);
					write_var_to_string(ids);
					char string[50];
					sprintf(string, "%s%s%s", $1, $2, $3);
					printf("%s\n",string);
					write_cond_to_string(string);

	};

WhileBinOp: ADD{};
			| SUB{};
			| MULTIPLY{};
			| DIV{};
WhileBlock1 : ID EQ ID WhileBinOp ID SEMICOLON {
					char ids[50];
					int id1Val = getVal($1, scope);
					int id2Val = getVal($3, scope);
					int id3Val = getVal($5, scope);
					sprintf(ids, "\n%s=%d\n%s=%d\n%s=%d\n", $1, id1Val, $3, id2Val, $5, id3Val);
					write_var_to_string(ids);
					char string[50];
				
					sprintf(string, "\t%s %s %s %s %s\n", $1, $2, $3, $4, $5);
					write_blcok_to_string(string);

			};
			| ID EQ ID WhileBinOp NUMBER SEMICOLON{

				int id1Val = getVal($1, scope);
				char ids[50];
				int id2Val = getVal($3, scope);

				sprintf(ids,"\n%s=%d\n%s=%d\n", $1, id1Val, $3, id2Val);
				write_var_to_string(ids);
				char string[50];
				sprintf(string, "\t%s %s %s %s %s\n", $1, $2, $3, $4, $5);
				printf("%s\n", string);
				write_blcok_to_string(string);

			};
			| WRITE ID SEMICOLON{	
				int id1Val = getVal($1, scope);
				char ids[50];
				sprintf(ids, "%s=%d\n", $1, id1Val);
				char string[50];
				sprintf(string, "\tprint(%s)\n", $2);
				write_blcok_to_string(string);

			};
			| %empty;			

WhileBlock2: ID EQ ID WhileBinOp ID SEMICOLON {
					char ids[50];
					int id1Val = getVal($1, scope);
					int id2Val = getVal($3, scope);
					int id3Val = getVal($5, scope);
					sprintf(ids, "\n%s=%d\n%s=%d\n%s=%d\n", $1, id1Val, $3, id2Val, $5, id3Val);
					write_var_to_string(ids);
					char string[50];
				
					sprintf(string, "\t%s %s %s %s %s\n", $1, $2, $3, $4, $5);
					write_blcok_to_string(string);


			};
			| ID EQ ID WhileBinOp NUMBER SEMICOLON{
				int id1Val = getVal($1, scope);
				char ids[50];
				int id2Val = getVal($3, scope);
				sprintf(ids,"\n%s=%d\n%s=%d\n", $1, id1Val, $3, id2Val);
				write_var_to_string(ids);
				char string[50];
				sprintf(string, "\t%s %s %s %s %s\n", $1, $2, $3, $4, $5);
				write_blcok_to_string(string);

			};
			| WRITE ID SEMICOLON{	
				int id1Val = getVal($1, scope);
				char ids[50];
				sprintf(ids, "%s=%d\n", $1, id1Val);
				char string[50];
				sprintf(string, "\tprint(%s)\n", $2);
				write_blcok_to_string(string);


			};
			| %empty;		
WhileBlock3: ID EQ ID WhileBinOp ID SEMICOLON {
					char ids[50];
					int id1Val = getVal($1, scope);
					int id2Val = getVal($3, scope);
					int id3Val = getVal($5, scope);
					sprintf(ids, "\n%s=%d\n%s=%d\n%s=%d\n", $1, id1Val, $3, id2Val, $5, id3Val);
					write_var_to_string(ids);
					char string[50];
				
					sprintf(string, "\t%s %s %s %s %s\n", $1, $2, $3, $4, $5);
					write_blcok_to_string(string);


			};
			| ID EQ ID WhileBinOp NUMBER SEMICOLON{
				int id1Val = getVal($1, scope);
				char ids[50];
				int id2Val = getVal($3, scope);
				sprintf(ids,"\n%s=%d\n%s=%d\n", $1, id1Val, $3, id2Val);
				write_var_to_string(ids);
				char string[50];
				sprintf(string, "\t%s %s %s %s %s\n", $1, $2, $3, $4, $5);
				write_blcok_to_string(string);

			};
			| WRITE ID SEMICOLON{	
				int id1Val = getVal($1, scope);
				char ids[50];
				sprintf(ids, "%s=%d\n", $1, id1Val);
				char string[50];
				sprintf(string, "\tprint(%s)\n", $2);
				write_blcok_to_string(string);


			};
			| %empty;		




VarDeclList:	VarDecl VarDeclList {$1->left = $2;
							  $$ = $1;}
			| VarDecl {$$ = $1;}

VarDecl:	TYPE ID SEMICOLON { printf("\n RECOGNIZED RULE: Variable declaration\n");

									char id1[50];

									symTabAccess();
									int inSymTab = found($2, scope);

									
									if (inSymTab == 0) 
										add_Item_to_var_sym_table($2, "Var", $1, 0, scope);
									else						
										printf("SEMANTIC ERROR: Var %s is already in the symbol table", $2);

									showVarSymTable();
									
									sprintf(id1, "%s", $2);
									int numid = getItemID(id1, scope);   // ADDING TO IR CODE T0 = X
									emitConstantIntAssignment ($2, numid);								

									
								    $$ = AST_Type("Type",$1,$2);  	// SEMANTIC ACTIONS
								};


ArrayDeclList : ArrayDecl ArrayDeclList {$1->left = $2;
							  $$ = $1;};
			| ArrayDecl {$$ = $1;};

ArrayDecl : TYPE ID LBRACKET NUMBER RBRACKET SEMICOLON { printf("\n RECOGNIZED RULE: Array declaration %s\n", $2);
									char id1[50];
									$4 = atoi($4);

									char concat[50];
									sprintf(concat, "%s[%d]", $2, $4);

									
									char temp[50];

									
									int inSymTab = found($2, scope);

									if (inSymTab == 0){
										printf("Adding array to symbol table\n");
										int tempint = $4;

										for (int i = 0; i < $4; i++){
											char arrayname[50];
											
											sprintf(temp, "%d", i);

											sprintf(arrayname, "%s[%s]", $2, temp);

											add_Item_to_var_sym_table(arrayname, "Array", $1, $4, &scope);
											
											tempint--;

	
										}
									}else{
														
										printf("SEMANTIC ERROR: Array %s is already in the symbol table", $2);
									}
									showVarSymTable();
									
									sprintf(id1, "%s", $2);
									int numid = getItemID(id1, scope);   // ADDING TO IR CODE T0 = X
									//emitConstantIntAssignment ($2, numid);								
									
								    $$ = AST_Type("Type",$1,concat);
									printf("%s", $$->LHS);
								}

StmtList: Stmt StmtList{ $1->left = $2;
					$$ = $1;}
	| Stmt { $$ = $1; };

Stmt: AssignStmtList {printf("AssignStmt\n");}
	| MathStatList {printf("MathStat\n");}
	| WriteStmtList {printf("WriteStmt\n");}
	| FuncallStmtList {printf("FuncallStmt\n");}
	| WhileConditionList {}



AssignStmtList: AssignStmt AssignStmtList{ $1->left = $2;
					$$ = $1;}
				| AssignStmt{ $$ = $1; };
				
AssignStmt:	ID LBRACKET NUMBER RBRACKET EQ NUMBER SEMICOLON { printf("\nRECOGNIZED RULE: Set Val of array at certine index\n"); 
									
									char concat[50];
									sprintf(concat, "%s[%s]", $1, $3);
									

									if (strcmp(scope, Global) == 0){
										if(found(concat, scope) != 1) { // Issue is here
											printf("SEMANTIC ERROR: Array %s has NOT been declared in scope %s \n", $1, scope);
											semanticCheckPassed = 0;
										}
										if(semanticCheckPassed == 1) {
											printf("\n\nRule is semantically correct!\n\n");
											setVal(concat, $6, scope);
											$$ = AST_assignment("=",concat, $6);
									
											int numid = getItemID(concat, scope);   // ADDING TO IR CODE T0 = X
											emitIRAssignment(concat, $6, numid);             // EMITS TO IR AND MIPS
											//emitMIPSConstantIntAssignment(concat, $6, numid);
											memset(concat, 0, sizeof(concat));
										}

									}else{
										if(found_in_fun_sym(concat, scope) != 1) { // Issue is here
											printf("SEMANTIC ERROR: Array %s has NOT been declared in scope %s \n", $1, scope);
											semanticCheckPassed = 0;
											set_Int_Fun_Val(concat, $6, scope);
										}
										if(semanticCheckPassed == 1) {
											printf("\n\nRule is semantically correct!\n\n");
											set_Int_Fun_Val(concat, $6, scope);
											$$ = AST_assignment("=",concat, $6);
									
											int numid = getItemID_fun_sym(concat, scope);   // ADDING TO IR CODE T0 = X
											emitIRAssignment(concat, $6, numid);             // EMITS TO IR AND MIPS
											//emitMIPSConstantIntAssignment(concat, $6, numid);
											memset(concat, 0, sizeof(concat));
										}

									}							
								}
	| ID LBRACKET NUMBER RBRACKET EQ CHAR SEMICOLON { printf("\nRECOGNIZED RULE: Set Val of array at certine index\n"); 
									
									char concat[50];
									sprintf(concat, "%s[%s]", $1, $3);
									

									if (strcmp(scope, Global) == 0){
										if(found(concat, scope) != 1) { // Issue is here
											printf("SEMANTIC ERROR: Array %s has NOT been declared in scope %s \n", $1, scope);
											semanticCheckPassed = 0;
										}
										if(semanticCheckPassed == 1) {
											printf("\n\nRule is semantically correct!\n\n");
											setcharVal(concat, $6, scope);
											$$ = AST_assignment("=",concat, $6);
									
											int numid = getItemID(concat, scope);   // ADDING TO IR CODE T0 = X
											emitIRAssignment(concat, $6, numid);             // EMITS TO IR AND MIPS
											//emitMIPSConstantIntAssignment(concat, $6, numid);
											memset(concat, 0, sizeof(concat));
										}

									}else{
										if(found_in_fun_sym(concat, scope) != 1) { // Issue is here
											printf("SEMANTIC ERROR: Array %s has NOT been declared in scope %s \n", $1, scope);
											semanticCheckPassed = 0;
										}
										if(semanticCheckPassed == 1) {
											printf("\n\nRule is semantically correct!\n\n");
											set_fun_char_val(concat, $6, scope);
											$$ = AST_assignment("=",concat, $6);
									
											int numid = getItemID_fun_sym(concat, scope);   // ADDING TO IR CODE T0 = X
											emitIRAssignment(concat, $6, numid);             // EMITS TO IR AND MIPS
											//emitMIPSConstantIntAssignment(concat, $6, numid);
											memset(concat, 0, sizeof(concat));
										}

									}							
								}

	| ID EQ CHAR SEMICOLON{ printf("\nRECOGNIZED RULE: Set String\n"); 
	
					char char1[50];
					char id1[50];
					sprintf(char1, "%s", $3);
					sprintf(id1, "%s", $1);
					if (strcmp(scope, Global) == 0){

						if(found(id1, scope) != 1) {
							printf("SEMANTIC ERROR: Variable %s has NOT been declared in scope %s \n", $1, scope);
							semanticCheckPassed = 0;
						}

						if (semanticCheckPassed == 1) {
							printf("\n\nRule is semantically correct!\n\n");
							setcharVal(id1, char1, scope);
							showVarSymTable();
							$$ = AST_assignment("=",$1, $3);
							int numid = getItemID($1, scope);   // ADDING TO IR CODE T0 = X
							emitIRAssignment($1, $3, numid);             // EMITS TO IR AND MIPS
							// emitMIPSConstantIntAssignment($1, $3, numid);
						}

					}else{
						if(found_in_fun_sym(id1, scope) != 1) {
							printf("SEMANTIC ERROR: Variable %s has NOT been declared in scope %s \n", $1, scope);
							semanticCheckPassed = 0;
						}
						if (semanticCheckPassed == 1) {
							printf("\n\nRule is semantically correct!\n\n");
							set_fun_char_val(id1, char1, scope);
							showVarSymTable();
							$$ = AST_assignment("=",$1, $3);
							int numid = getVal_from_fun_sym($1, scope);   // ADDING TO IR CODE T0 = X
							emitIRAssignment($1, $3, numid);             // EMITS TO IR AND MIPS
							// emitMIPSConstantIntAssignment($1, $3, numid);
						}

					}
				}

	| ID EQ NUMBER SEMICOLON { printf("\nRECOGNIZED RULE: Set Val\n"); 


						char str[50];
						char id1[50];
						char id2[50];

						if (strcmp(scope, Global) == 0){


							if(found($1, scope) != 1) {
								printf("SEMANTIC ERROR: Variable %s has NOT been declared in scope %s \n", $1, scope);
								semanticCheckPassed = 0;
							}


							if (semanticCheckPassed == 1) {
								printf("\n\nRule is semantically correct!\n\n");
								sprintf(id2, "%s", $3); 
								sprintf(id1, "%s", $1);
								symTabAccess();
								int CheckForFloat = 0;
								for(int i = 0; $3[i] != '\0'; ++i)
								{
									if($3[i] == '.')
									{
									CheckForFloat = 1;
									break;
									}
								}
								if (CheckForFloat == 1){
									printf("%s\n",$3);
									setfloatVal(id1, $3, scope);
								}else{
									// printf("Decimal point\n");
									setVal(id1, $3, scope);
								}



								showVarSymTable();
								$$ = AST_assignment("=",$1, id2);
								int numid = getItemID(id1, scope);   // ADDING TO IR CODE T0 = X
								emitIRAssignment(id1, id2, numid);             // EMITS TO IR AND MIPS
								// emitMIPSConstantIntAssignment(id2, numid);

							}
						}else{
							if(found_in_fun_sym($1, scope) != 1) {
								printf("SEMANTIC ERROR: Variable %s has NOT been declared in scope %s \n", $1, scope);
								semanticCheckPassed = 0;
							}
							if (semanticCheckPassed == 1) {
								printf("\n\nRule is semantically correct!\n\n");
								sprintf(id2, "%s", $3); 
								sprintf(id1, "%s", $1);
								int CheckForFloat = 0;
								for(int i = 0; $3[i] != '\0'; ++i)
								{
									if($3[i] == '.')
									{
									CheckForFloat = 1;
									break;
									}
								}
								if (CheckForFloat == 1){
									printf("%s\n",$3);
									set_float_Fun_Val(id1, $3, scope);
								}else{
									// printf("Decimal point\n");
									set_Int_Fun_Val(id1, $3, scope);
								}
								showFuncSymTable();
								$$ = AST_assignment("=",$1, id2);
								int numid = getItemID_fun_sym(id1, scope);   // ADDING TO IR CODE T0 = X
								emitIRAssignment(id1, id2, numid);             // EMITS TO IR AND MIPS
								// emitMIPSConstantIntAssignment(id1, id2, numid);

							}
						}
					}

	| ID EQ MathStat SEMICOLON{
					char id1[50];
					char id2[50];
					FILE * ResultF;
					sprintf(id1, "%s", $1);
					char command[50], mathVal[50];
					char ch;
					int i = 0;
					int numid = getItemID(id1, scope);
					reverseNumArr();
					strcpy( command, "python3 Operations.py" );
					printf("\n");
					addCalcFile();
					addOpArr('\0');
					system(command);
					sleep(1);
					ResultF = fopen("./Operations/Results/CalcF.txt_results.txt", "r");
					fgets(mathVal,20,ResultF);
					int x = atoi(mathVal);
					fclose(ResultF);

					int CheckForFloat = 0;
					for(int i = 0; mathVal[i] != '\0'; ++i){
						if(mathVal[i] == '.'){
							CheckForFloat = 1;
							break;
						}
					}
						if (CheckForFloat == 1){
							printf("%s\n",mathVal);
							setfloatVal($1, mathVal, scope);
						}else{
							setVal($1, mathVal, scope);
						}
					sprintf(id2, "%s", mathVal);	
					$$ = AST_assignment("=",$1,mathVal);
					emitConstantIntAssignment (mathVal, numid);
					// emitMIPSConstantIntAssignment(id1, id2, numid);	

					clearClacFile();
					clearArr();
					clearOpArr();
		};
		
WriteStmtList: WriteStmt WriteStmtList{ $1->left = $2;
					$$ = $1;}
				|	WriteStmt{ $$ = $1; };

WriteStmt: WRITE ID SEMICOLON{ printf("\nRECOGNIZED RULE: WRITE STATMENT\n");

					char id1[50];
					sprintf(id1, "%s", $2);
					char *tyoe = getVariableType(id1, scope);
					char type[50];
					sprintf(type, "%s", tyoe);
					printf("Type: %s\n", type);
					$$ = AST_Write("write",type, $2);
					
					int numid = getItemID(id1, scope);


					// SEMANTIC ANALYSIS ACTIONS   
					if (found($2, scope) != 1) {	 
						printf("SEMANTIC ERROR: Variable %s has NOT been declared in scope %s \n", $2, scope);
						semanticCheckPassed = 0;
					}

					if (semanticCheckPassed == 1) {
						printf("\n\nRule is semantically correct!\n\n");
						// emitMIPSConstantIntAssignment(id1, id2, numid);
						if (strcmp(type, "int") == 0){
							int val = getVal($2, scope);
							char valStr[50];
							sprintf(valStr, "%d", val);
							emitMIPSConstantIntAssignment(valStr, numid);
							emitMIPSWriteId(numid);
						}
						else if(strcmp(type, "float") == 0){
							double val = getFloatVal($2, scope);
							char valStr[50];
							sprintf(valStr, "%f", val);
							char pythonCommand[50];
							sprintf(pythonCommand, "python3 WriteFloatsMips.py %s\n", valStr);
							char command[50];
							strcpy(command, pythonCommand);
						
							system(command);
							sleep(0.5);
							emitfloatAssignment();

						}
						else if(strcmp(type, "char") == 0){
							char *val = getCharVal($2, scope);
							char valStr[50];
							sprintf(valStr, "%s", val);
							char pythonCommand[50];
							sprintf(pythonCommand, "python3 writeCharToMips.py %s\n", valStr);
							char command[50];
							strcpy(command, pythonCommand);
							system(command);
							sleep(0.5);
							emitMIPSCharAssignment();
						}
			
						
					}


				};
		| WRITE ID LBRACKET NUMBER RBRACKET SEMICOLON{ printf("\nRECOGNIZED RULE: WRITE STATMENT FOR ARRAY\n");

					char id1[50];
					sprintf(id1, "%s[%s]", $2, $4);
					char *tyoe = getVariableType(id1, scope);
					char type[50];
					sprintf(type, "%s", tyoe);

					$$ = AST_Write("write",type, $2);
					
					int numid = getItemID(id1, scope);
					if (found(id1, scope) != 1) {	 
						printf("SEMANTIC ERROR: Variable %s has NOT been declared in scope %s \n", $2, scope);
						semanticCheckPassed = 0;
					}

					if (semanticCheckPassed == 1) {
						printf("\n\nRule is semantically correct!\n\n");
						if (strcmp(type, "int") == 0){
							int val = getVal(id1, scope);
							// emitWriteInt(id1, numid);
							// emitMIPSWriteInt(id1, numid);	// EMITS TO IR AND MIPS

							char valStr[50];
							sprintf(valStr, "%d", val);
							emitMIPSConstantIntAssignment(valStr, numid);	// EMITS TO IR AND MIPS

						} else if (strcmp(type, "float") == 0){
							double val = getFloatVal(id1, scope);
							char valStr[50];
							sprintf(valStr, "%lf", val);
							emitMIPSConstantIntAssignment(valStr, numid);

						} else if (strcmp(type, "char") == 0){
							char *val = getCharVal(id1, scope);
							char valStr[50];
							sprintf(valStr, "%s", val);
							emitMIPSConstantIntAssignment(valStr, numid); 				

						}
						emitMIPSWriteId(numid);
					}


		};





BinOp:	ADD	{addOpArr('+');};

		| SUB	{addOpArr('-');};

		| MULTIPLY	{addOpArr('*');};

		| DIV	{addOpArr('/');};

MathStatList: MathStat MathStatList {$1->left = $2;
					$$ = $1;}
				| MathStat{ $$ = $1; };

MathStat:	NUMBER BinOp MathStat	{addNumArr($1);};
				
			| ID BinOp MathStat	{

					symTabAccess();
					int id1;
					id1 = getVal($1, scope);
					addIDNumArr(id1);  //ADD ID TO SUM GLOBAL VALUE
					
			};

			| NUMBER	{addNumArr($1);};

			| ID	{
					symTabAccess();
					int id1;
					id1 = getVal($1, scope);
					addIDNumArr(id1);	//ADD ID TO SUM GLOBAL VALUE
					};

%%

int main(int argc, char**argv)
{
	clearVarFile();
	create_Var_file();
	clearBlockFile();
	create_block_file();

	printf("\n\n##### COMPILER STARTED #####\n\n");
	
	if (argc > 1){
	  if(!(yyin = fopen(argv[1], "r")))
          {
		perror(argv[1]);
		return(1);
	  }
	}

	// Initialize IR and MIPS files
	initIRcodeFile();
	initAssemblyFile();

	// Start parser
	yyparse();

	// Add the closing part required for any MIPS file
	emitEndOfAssemblyCode();

}

void yyerror(const char* s) {
	fprintf(stderr, "Parse error: %s\n", s);
	exit(1);
}

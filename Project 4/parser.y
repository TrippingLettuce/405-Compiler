%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <string.h>

#include "symbolTable.h"
#include "AST.h"
#include "IRcode.h"
#include "assembly.h"
#include "calculator.h"


extern int yylex();
extern int yyparse();
extern FILE* yyin;
void yyerror(const char* s);

#define IN_ELSE_BLOCK 0 // Currently navigating through 'else' block.
#define IN_IF_BLOCK 1 // Currently navigating through 'if' block.
#define RUN_ELSE_BLOCK 0 // Execution of 'else' block is scheduled.
#define RUN_IF_BLOCK 1 // Execution of 'if' block is scheduled.
#define UPDATE_IF_ELSE 0 // Update the 'if-else' state.


// Constants for determining the output section in the intermediate code and the MIPS file.
#define IR_CODE 0 // Main section of the intermediate code (default).
#define IR_FUNC 1 // Function and loop sections of the intermediate code.
#define TEMP_MIPS 0  // Main section of the MIPS code (default).
#define MIPS_CODE 1  // Variable declaration section of the MIPS code.
#define MIPS_FUNC 2  // Function and loop sections of the MIPS code.

// Tracking variables.
char currentScope[50]; // The current scope which can be 'global' or the function's name.
char IDArg[50]; // Stores the name of the ID argument temporarily.
int argIsID = 0; // Flag to indicate if an argument is an ID.
int argCounter = 0; // Tracks the number of arguments.
char *args[50]; // Array of argument names.
char **argptr = args; // Pointer to the array of argument names.

// Current operator storage for mathematical and conditional operations.
char operator; // Current operator for mathematical expressions.
char op; // Current operator for conditions.

// Temporary storage for two operands in a binary mathematical operation.
char num1[50]; // First operand.
char num2[50]; // Second operand.

// Control flags for 'if-else'
int runIfElseBlock = 0; // Indicates whether to execute the 'if' block (1) or the 'else' block (0).
int ifElseCurrentBlock = 0; // Shows current active block: 'if' block (1) or 'else' block (0).
int inElse = 0; // Flag indicating which construct to update: 'if-else' (0)

int registerCounter = 0; // Tracks the number of registers used for parameters in MIPS.

// Scope initialization and symbol table.
char scope[50] = "G"; // Initialize the scope as 'global'.


%}

// different types of tokens
%union {
	int number;
	char character;
	char* string;
	struct AST* ast;
}

// token declarations: words
%token <string> CHAR // word: char
%token <string> INT // word: int
%token <string> FLOAT // word: float
%token <string> VOID // word: void
%token <string> IF // word: if
%token <string> ELSE // word: else
%token <string> WRITE // word: write
%token <string> RETURN // word: return

// token words
%token <string> COMMA // word: ,
%token <string> SEMICOLON // word: ;
%token <string> NEWLINECHAR // word: ~nl

// token operators
%token <string> DEQ 
%token <string> NOTEQ
%token <string> LEQ 
%token <string> GEQ 
%token <string> LT 
%token <string> GT 
%token <string> EQ 
%token <string> ADD
%token <string> MULTIPLY
%token <string> SUB 
%token <string> DIV
%token <string> EXPONENT 
%token <string> LPAREN 
%token <string> RPAREN 
%token <string> LBRACKET
%token <string> RBRACKET
%token <string> LBRACE 
%token <string> RBRACE 

// token declarations
%token <string> NUMBER
%token <string> FLOATNUM
%token <string> STRINGID 
%token <string> CHARID 
%token <string> ID 

%printer { fprintf(yyoutput, "%s", $$); } ID;

%type <ast> Program DeclList Decl VarDecl FuncDecl ParamDeclList IfStmt ElseStmt Condition ParamDecl ArgDeclList ArgDecl Block BlockDeclList BlockDecl StmtList Expr IDEQExpr MathStmt Math Operator CompOperator ArrDecl

%start Program

%%

Program: DeclList {
		// ast
		$$ = $1;

		printf("\n\n ---------------------" RESET);
		printf(BPINK " AST STARTED " RESET);
		printf("--------------------- \n\n" RESET);

		// print the ast
		//printAST($$,0);

		// output the end of the ast
		printf("\n\n ---------------------" RESET);
		printf(PINK " AST ENDED " RESET);
		printf("--------------------- \n\n" RESET);

		// append the two ir code files to each other
		appendFiles("IRFuncs.ir", "IRcode.ir");

		// end mips code
		addEndLoop(); // add the endloop function to the bottom of mips for any loops to jump to to get to main
		createEndOfAssemblyCode(); // add the end line of mips to kill the program

		// append the three mips files to each other
		appendFiles("tempMIPS.asm", "MIPScode.asm");
		printf("\n");
		appendFiles("MIPSfuncs.asm", "MIPScode.asm");

		// output that mips was generated
		printf("\n\n ---------------------" RESET);
		printf(BPINK " MIPS GENERATED " RESET);
		printf("--------------------- \n\n" RESET);

};

// declList consists of a recursive list of declarations
DeclList:      Decl DeclList {

				// ast
				$1->left = $2;
				$$ = $1;

			} | Decl {

				// ast
				$$ = $1;

};

// declaration types, any of these can show at any time in the source code
Decl:	   FuncDecl { // function declaration

			// ast
			$$ = $1;

		} | VarDecl { // variable declaration

			// ast
			$$ = $1;

		} | StmtList { // statement declaration list

			// ast
			$$ = $1;

		} |	IfStmt { // if statement declaration

			// ast
			$$ = $1;
	
};

// function declaration types: void, int, float, char
FuncDecl:				 VOID ID LPAREN { printf(BORANGE "RULE: (VOID) Function Initialization \n\n" RESET); // void function declaration
								
								// symbol table
								symTabAccess(); // access symbol table
								addSymbolTable($2,"VOID"); // add void function to symbol table
								strcpy(scope,$2); // set scope to function name

								// ir code
								createFunctionHeader($2); // create function
								changeIRFile(IR_FUNC); // change file to print block to the function IR code file

								// mips
								createMIPSFunction($2); // create function
	
							// second part of the function, including parameter list, right parentheses, and block
							} ParamDeclList RPAREN Block { printf(BGREEN "\nVoid Function End.\n" RESET); // void function end

								// ast
								$$ = AST_assignment("FNC",$1,$2); // add the function to the ast

								// ir code
								changeIRFile(IR_CODE); // change file back to main file

								// mips
								endMIPSFunction(); // end function in mips
						

						} | INT ID LPAREN {printf(BORANGE "RULE: (INT) Function Initialization \n\n" RESET); // int function declaration

								// symbol table
								symTabAccess(); // access symbol table
								addSymbolTable($2,"INT"); // add int function to symbol table
								strcpy(scope,$2); // set scope to function name

								// ir code
								createFunctionHeader($2); // create function
								changeIRFile(IR_FUNC); // change file to print block to the function IR code file

								// mips
								createMIPSFunction($2); // create function
						 
						 	// second part of the function, including parameter list, right parentheses, and block
						 	} ParamDeclList RPAREN Block { printf(BGREEN "\nInt Function End.\n" RESET); // void function end

								// ast
								$$ = AST_assignment("FNC",$1,$2); // add the function to the ast

								// ir code
								changeIRFile(IR_CODE); // change file back to main file

								// mips code
								endMIPSFunction(); // end function in mips

						
						} | CHAR ID LPAREN {printf(BORANGE "RULE: (Char) Function Initialization \n\n" RESET); // char function declaration

								// symbol table
								symTabAccess(); // access symbol table
								addSymbolTable($2,"CHR"); // add char function to symbol table
								strcpy(scope,$2); // set scope to function name

								// ir code
								createFunctionHeader($2); // create function
								changeIRFile(IR_FUNC); // change file to print block to the function IR code file

								// mips
								createMIPSFunction($2); // create function
						 
						 	// second part of the function, including parameter list, right parentheses, and block
							} ParamDeclList RPAREN Block { printf(BGREEN "\nChar Function End.\n" RESET); // char function end

								// ast
								$$ = AST_assignment("FNC",$1,$2); // add the function to the ast

								// ir code
								changeIRFile(IR_CODE); // change file back to main file

								// mips
								endMIPSFunction(); // end function in mips

						
						} | FLOAT ID LPAREN {printf(BORANGE "RULE: (Float) Function Initialization \n\n" RESET); // float function declaration

								// symbol table
								symTabAccess(); // access symbol table
								addSymbolTable($2,"FLT"); // add float function to symbol table
								strcpy(scope,$2); // set scope to function name

								// ir code
								createFunctionHeader($2); // create function
								changeIRFile(IR_FUNC); // change file to print block to the function IR code file

								// mips
								createMIPSFunction($2); // create function
								
							// second part of the function, including parameter list, right parentheses, and block
						 	} ParamDeclList RPAREN Block { printf(BGREEN "\nFloat Function End.\n" RESET); // float function end

								// ast
								$$ = AST_assignment("FNC",$1,$2); // add the function to the ast

								// ir code
								changeIRFile(IR_CODE); // change file back to main file

								// mips
								endMIPSFunction(); // end function in mips
 
}

// parameter declaration list consists of parameters separated by commas or a single parameter
ParamDeclList: ParamDecl COMMA ParamDeclList { // list of parameters separated by commas

					// ast
					$1->left = $2;
					$$ = $1;

				} | ParamDecl { // or single parameter

					// ast
					$$ = $1;

				}

// types of parameter declarations, integer, float, char
ParamDecl:		| INT ID { printf(BORANGE "RULE: (INT) Parameter Initialization \n\n" RESET); // integer parameter declaration

					// symbol table
					addItem($2,"PAR","INT",scope,0); // add integer parameter to symbol table

					// ir code
					printf(BLUE "IR Code" RESET);
					printf(RED " NOT " RESET);
					printf(BLUE "Created\n" RESET);


				} | FLOAT ID { printf(BORANGE "RULE: (Float) Parameter Initialization \n\n" RESET); // float parameter declaration

					// symbol table
					addItem($2,"PAR","FLT",scope,0); // add float parameter to symbol table

					// ir code
					printf(BLUE "IR Code" RESET);
					printf(RED " NOT " RESET);
					printf(BLUE "Created\n" RESET);


				} | CHAR ID { printf(BORANGE "RULE: (Char) Parameter Initialization \n\n" RESET); // char parameter declaration

					// symbol table
					addItem($2,"PAR","CHR",scope,0); // add char parameter to symbol table

					// ir code
					printf(BLUE "IR Code" RESET);
					printf(RED " NOT " RESET);
					printf(BLUE "Created\n" RESET);
					

}

// argument declaration list for calling a function, e.g. addValue(1,2): 1 & 2 are arguments, either a recursive list of arguments separated by a comma or a single argument
ArgDeclList: ArgDecl COMMA ArgDeclList { // recursive list of arguments

					// ast
					$1->left = $2;
					$$ = $1;

				} | ArgDecl { // or single argument

					// ast
					$$ = $1;

				}

// argdecl holds types of arguments: number, float number, CHARID, id
ArgDecl:	| NUMBER { printf(BORANGE "RULE: Parameter Set = %s\n\n" RESET, $1); // number argument

				argptr[argCounter] = $1; // add number to argument array
				argCounter++; // increment argument counter


			} | FLOATNUM { printf(BORANGE "RULE: Parameter Set = %s\n\n" RESET, $1); // float argument

				argptr[argCounter] = $1; // add float number to argument array
				argCounter++; // increment argument counter


			} | CHARID { printf(BORANGE "RULE: Parameter Set = %s\n\n" RESET, $1); // char argument

				argptr[argCounter] = $1; // add char to argument array
				argCounter++; // increment argument counter
				

			} | ID { printf(BORANGE "RULE: Parameter Set = %s\n\n" RESET, getValue($1, "G")); // id argument

				argptr[argCounter] = getValue($1, "G"); // add id value to argument array
				strcpy(IDArg, $1); // copy the name of the id into temporary IDArg variable
				argIsID = 1; // set flag so it knows the parameter is an ID, not a number
				argCounter++; // increment argument counter

}

// block is used for the block in functions, if statements
Block: LBRACKET BlockDeclList RBRACKET { // blockDeclList is the recursive list of statements inside the block

	strcpy(scope,"G"); // reset scope back to global after statements are parsed

}

// blockDeclList is a recursive list of statements or single statement, which is similar to DeclList
BlockDeclList: BlockDecl BlockDeclList { // recursive list of statements

				// ast
				$1->left = $2;
				$$ = $1;

		} | BlockDecl { // or single statement

				// ast
				$$ = $1;

}

// blockDecl types: variable declaration, stmtList, if statement
BlockDecl: VarDecl { // variable declaration

		   // ast
		   $$ = $1;

		} | StmtList { // statement list

			// ast
			$$ = $1;

		} | IfStmt { // if statement
			// ast
			$$ = $1;

};

// statement list is a recursive list of expressions or a single expression or nothing
StmtList:	| Expr StmtList { // nothing or recursive list of statements
				
				// ast
				$1->left = $2; 
				$$ = $1;
			
			} | Expr { // or single expression
				
				// ast
				$$ = $1;
		
};

/*----start vardecl-----------------------------------------------------------------------------------------------------*/

// variable declaration types
VarDecl:	INT ID SEMICOLON { printf(BOLD "RECOGNIZED RULE: (INT) Variable Declaration\n\n" RESET);	// e.g. int x;

						if (ifElseCurrentBlock == runIfElseBlock) { // if we are in an if block, both are 1, if we are in an else block, both are 0

							// semantic checks
								// is the variable already declared?
								symTabAccess(); // access symbol table
								if (found($2,scope) == 1) { // if we find the variable in the symbol table
									printf(RED "\nERROR: Variable '%s' already declared.\n" RESET,$2); // error message
									exit(0); // exit program
								}

							// symbol table
							addItem($2, "VAR", "INT", scope, 0); // add variable to the correct symbol table based on scope

							// ast
							$$ = AST_assignment("TYPE",$1,$2); // add variable to ast

							// ir code
							createIntDefinition($2, scope); // create ir code: T0 = x

							// mips code 
							createMIPSIntDecl($2,scope); // create mips: Gx: .word 0
							
							// code optimization
								// N/A

							/*
										VarDecl
									INT        ID
							*/
						}
				
			} |	ID EQ NUMBER SEMICOLON	{ printf(BORANGE "RULE: (INT) Variable Initialization \n\n" RESET); // e.g. x = 1;

						if (ifElseCurrentBlock == runIfElseBlock) { // if we are in an if block, both are 1, if we are in an else block, both are 0

							// semantic checks
								// is the variable already declared
								symTabAccess(); // access symbol table
								if (scope == "G") { // if the scope is global
									if (found($1,scope) == 0) { // if we don't find the variable in the global symbol table
										printf(RED "\n::::> CHECK FAILED: Variable '%s' not initialized in the global scope.\n\n" RESET,$1); // error message
										exit(0); // exit program
									}
								} 
								else { // else the scope is function
									if (found($1,scope) == 0) { // if we don't find the variable in the function symbol table
										if (found($1, "G") == 0) { // if the variable is not found in the global scope
											showSymTable(); // show the symbol tables
											printf(RED "\n::::> CHECK FAILED: Variable '%s' not initialized in the function or global scope.\n\n" RESET,$1); // error message
											exit(0); // exit program
										}
									}
								}

								// is the statement redundant
								if (redundantValue($1, scope, $3) == 0) { // if statement is redundant
									printf(RED "::::> CHECK FAILED: Variable %s has already been declared as: %s.\n\n" RESET,$1,$3); // error message
									exit(0); // exit program
								}

							// symbol table
							if (strcmp(scope, "G") != 0) { // if scope is in function

								if (found($1, scope) == 1) { // if the variable is found in the function's sym table

									updateValue($1, scope, $3); // update value in function sym table

								} else if (found($1, "G") == 1) { // if the variable is found in the global scope

									updateValue($1, "G", $3); // update value in global sym table

								}

							} else { // if scope is global
								updateValue($1, scope, $3); // update value normally
							}

							// ast
							$$ = AST_BinaryExpression("=",$1,$3); // add binary expression to the ast

							// ir code
							createIntAssignment($1, $3, scope); // create ir code: T0 = 1

							// mips code
							createMIPSIntAssignment($1, $3, scope); // create mips code for int assignment

							// code optimization
								// N/A

							/*
									=
								ID    NUMBER
							*/

						}

			} |	CHAR ID SEMICOLON	{ printf(BORANGE "RULE: (Char) Variable Declaration \n\n" RESET); // e.g. char c;

						if (ifElseCurrentBlock == runIfElseBlock) { // if we are in an if block, both are 1, if we are in an else block, both are 0
							// semantic checks
								// is the variable already declared?
								symTabAccess(); // access symbol table
								if (found($2,scope) == 1) { // if we find the variable in the symbol table
									exit(0); // variable already declared
								}

							// symbol table	
							addItem($2, "VAR", "CHR", scope, 0); // add char variable to the symbol table

							// ast
							$$ = AST_assignment("TYPE",$1,$2); // add char variable to the ast

							// ir code
							createCharDefinition($2, scope); // create ir code: T1 = c

							
							// code optimization
								// N/A

							/*
									VarDecl
								CHAR	   ID
							*/	

						}				
			
			} |	ID EQ CHARID SEMICOLON	  { printf(BORANGE "RULE: (Char) Variable Initialization \n\n" RESET); // e.g. c = 'a';	

						if (ifElseCurrentBlock == runIfElseBlock) { // if we are in an if block, both are 1, if we are in an else block, both are 0

							// remove apostrophes from CHARID
							char* str = removeApostrophes($3); // symbol table function to return char without apostrophes

							// semantic checks
								// is the variable already declared?
								symTabAccess(); // access symbol table
								if (scope == "G") { // if the scope is global
									if (found($1,scope) == 0) { // if the variable is not found in the global scope
										printf(RED "\n::::> CHECK FAILED: Variable '%s' not initialized in the global scope.\n\n" RESET,$1); // error message
										exit(0); // exit program
									}
								}
								else { // else we are in function scope
									if (found($1,scope) == 0) { // if the variable is not found in the function scope
										if (found($1, "G") == 0) { // if the variable is not found in the global scope
											showSymTable(); // access symbol table
											printf(RED "\n::::> CHECK FAILED: Variable '%s' not initialized in the function or global scope.\n\n" RESET,$1); // error message
											exit(0); // exit program
										}
									}
								}

								// is the statement redundant
								if (redundantValue($1, scope, str) == 0) { // if statement is redundant
									printf(RED "::::> CHECK FAILED: Variable '%s' has already been declared as: %s.\n\n" RESET,$1,$3); // error message
									exit(0); // exit the program
								}

							// symbol table
							if (strcmp(scope, "G") != 0) { // if scope is in function

								if (found($1, scope) == 1) { // if the variable is found in the function's sym table

									updateValue($1, scope, str); // update value in function sym table

								} else if (found($1, "G") == 1) { // if the variable is found in the global scope

									updateValue($1, "G", str); // update value in global sym table

								}

							} else { // if scope is global
								updateValue($1, scope, str); // update value normally
							}
							
							// ast
							$$ = AST_BinaryExpression("=",$1,str); // add binary expression to ast

							// ir code
							createCharAssignment($1, str, scope); // create it code: T1 = 'a'

							// mips code
							createMIPSCharAssignment($1, str, scope); // create mips

							// code optimization
								// N/A

							/*
									=
								ID	   CHARID
							*/

						}

			} | FLOAT ID SEMICOLON	{ printf(BORANGE "RULE: (Float) Variable Declaration\n\n" RESET);	// e.g. float f;

						if (ifElseCurrentBlock == runIfElseBlock) { // if we are in an if block, both are 1, if we are in an else block, both are 0

							// semantic checks
								// is the variable already declared?
								symTabAccess(); // access symbol table
								if (found($2,scope) == 1) { // if the variable is found in the symbol table
									printf(RED "\nERROR: Variable '%s' already declared.\n" RESET,$2); // error message
									exit(0); // exit program
								}

							// symbol table
							addItem($2, "VAR", "FLT", scope, 0); // add the float variable to the symbol table

							// ast
							$$ = AST_assignment("TYPE",$1,$2); // add the float variable to the ast

							// ir code
							createFloatDefinition($2, scope); // create ir code: T2 = f

							// mips code
							
							// code optimization
								// N/A

							/*
										VarDecl
									INT        ID
							*/

						}

				} |	ID EQ FLOATNUM SEMICOLON	{ printf(BORANGE "RULE: (Float) Variable Initialization \n\n" RESET); // e.g. f = 1.0;
							
						if (ifElseCurrentBlock == runIfElseBlock) { // if we are in an if block, both are 1, if we are in an else block, both are 0

							// semantic checks
								// is the variable already declared
								symTabAccess(); // access symbol table
								if (scope == "G") { // if the scope is global
									if (found($1,scope) == 0) { // if the variable is not found in the global scope
										printf(RED "\n::::> CHECK FAILED: Variable '%s' not initialized in the global scope.\n\n" RESET,$1); // error message
										exit(0); // exit program
									}
								} 
								else { // else the scope is function
									if (found($1,scope) == 0) { // if the variable is not found in the function scope
										if (found($1, "G") == 0) { // if the variable is not found in the global scope
											showSymTable(); // show the symbol table
											printf(RED "\n::::> CHECK FAILED: Variable '%s' not initialized in the function or global scope.\n\n" RESET,$1); // error message
											exit(0); // exit program
										}
									}
								}

								// is the statement redundant
								if (redundantValue($1, scope, $3) == 0) { // if statement is redundant
									printf(RED "\n::::> CHECK FAILED: Variable '%s' has already been declared as: %s.\n\n" RESET,$1,$3); // error message
									exit(0); // exit program
								}

							// symbol table
							if (strcmp(scope, "G") != 0) { // if scope is in function

								if (found($1, scope) == 1) { // if the variable is found in the function's sym table

									updateValue($1, scope, $3); // update value in function sym table

								} else if (found($1, "G") == 1) { // if the variable is found in the global scope

									updateValue($1, "G", $3); // update value in global sym table

								}

							} else { // if scope is global
								updateValue($1, scope, $3); // update value normally
							}

							// ast
							$$ = AST_BinaryExpression("=",$1,$3); // add float variable to ast

							// ir code
							createFloatAssignment($1,$3, scope); // create ir code: T3 = 1.0

							// mips code
							createMIPSFloatAssignment($1, $3, scope); // create mips

							// code optimization
								// N/A

							/*
									=
								ID    NUMBER
							*/

						}

				} |	ID EQ ID SEMICOLON	{ printf(BORANGE "RULE: Assignment Statement\n\n" RESET); // e.g. x = y;

					if (ifElseCurrentBlock == runIfElseBlock) { // if we are in an if block, both are 1, if we are in an else block, both are 0

						// semantic checks
							// are both variables already declared?
							symTabAccess(); // access symbol table
							printf("\n"); // print newline
							if (found($1,scope) == 0 || found($3,scope) == 0) { // if both variables are not found in the scope
								printf(RED "\nERROR: Variable %s or %s not declared.\n\n" RESET,$1,$3); // error message
								exit(0); // exit program
							}

							// does the second id have a value?
							//initialized($3, scope);

							// are the id's both variables?
							//compareKinds($1, $3, scope);

							// are the types of the id's the same
							compareTypes($1, $3, scope);

						// symbol table
						updateValue($1, scope, getValue($3, scope)); // update the value of the first id in the symbol table

						// ast
						$$ = AST_BinaryExpression("=",$1,$3); // add expression to the ast

						// ir code
						createIDtoIDAssignment($1, $3, scope); // create ir code: T0 = T1

						// mips code
						createMIPSIDtoIDAssignment($1, $3, scope); // create mips

						// code optimization
							// mark the two id's as used
							isUsed($1, scope);
							isUsed($3, scope);

					}


				} | IDEQExpr SEMICOLON { printf(BORANGE "RULE: ADD Statement\n\n" RESET); // id = math statement, e.g. x = 10 - 8;

					if (ifElseCurrentBlock == runIfElseBlock) { // if we are in an if block, both are 1, if we are in an else block, both are 0

						// ast
						$$ = $1;

					}

				} | ArrDecl { // array declaration

};


/*----end vardecl-------------------------------------------------------------------------------------------------------*/





/*----start expr--------------------------------------------------------------------------------------------------------*/


// expr is any possible expression in our language: e.g. write x; or return y;
Expr:	SEMICOLON {  // just a semicolon

	} |	ID EQ ID SEMICOLON { printf(BORANGE "RULE: Assignment Statement\n\n" RESET); // e.g. x = y like above, but can also be present in a stmtList

		if (ifElseCurrentBlock == runIfElseBlock) { // if we are in an if block, both are 1, if we are in an else block, both are 0

			// semantic checks
				// are both variables already declared?
				symTabAccess(); // access symbole table
				printf("\n"); // print newline
				if (found($1,scope) == 0 || found($3,scope) == 0) { // if both variables are not found in the scope
					printf(RED "\nERROR: Variable %s or %s not declared.\n\n" RESET,$1,$3); // error message
					exit(0); // exit progrma
				}

				// does the second id have a value?
				initialized($3, scope);

				// are the id's both variables?
				compareKinds($1, $3, scope);

				// are the types of the id's the same
				compareTypes($1, $3, scope);

			// symbol table
			updateValue($1, scope, getValue($3, scope)); // update value of first id in symbol table

			// ast
			$$ = AST_BinaryExpression("=",$1,$3); // add expression to the ast

			// ir code
			createIDtoIDAssignment($1, $3, scope); // create ir code: T0 = T1

			// mips code
			createMIPSIDtoIDAssignment($1, $3, scope); // create mips

			// code optimization
				// mark the two id's as used
				isUsed($1, scope);
				isUsed($3, scope);

		}

	} | ID EQ ID LPAREN ArgDeclList RPAREN SEMICOLON { printf(BORANGE "RULE: ID = Function\n" RESET); // e.g. x = addValue(1,2);

		if (ifElseCurrentBlock == runIfElseBlock) { // if we are in an if block, both are 1, if we are in an else block, both are 0

			// set scope to function
			strcpy(scope, $3);

			// loop through arguments and do parser functions
			for (int i = 0; i < argCounter; i++) { // from 0 to however many arguments there are

				printf(BGREEN "IF Parameter Accepted\n" RESET); // output to console

				// ir code
				printf(BLUE "IR Code" RESET);
				printf(RED " NOT " RESET);
				printf(BLUE "Created\n" RESET); // ir code not yet created

				// variables for getting parameter name based on index
				char itemName[50]; // stores name of parameter
				char itemID[50]; // stores id of the parameter
				char result[50]; // stores the result of below function

				// get parameter name based on index of for loop
				sprintf(itemID, "%d", i); // convert i into a string
				sprintf(itemName, "%s", getNameByID(itemID, scope)); // add the name of the parameter into itemName
				strcpy(result, ""); // redundant
				strcat(result, itemName); // store itemName in result

				// variables to hold the type of the parameter
				char type[50];
				int isInt, isFloat, isChar;

				// get the type of the parameter
				sprintf(type, "%s", getVariableType(itemName, scope));
				
				// determine whether the type is INT, FLT, or CHR
				isInt = strcmp(type, "INT"); // compare type to "INT"
				isFloat = strcmp(type, "FLT"); // compare type to "FLT"
				isChar = strcmp(type, "CHR"); // compare type to "CHR"

				if (isInt == 0) { // if the parameter is an integer
					if (argIsID == 1) { // if parameter is an ID

						// mips
						createIntIDParameter(IDArg, i+1, "G"); // create mips for an id parameter
						argIsID = 0; // revert argIsID to 0 (it gets set to 1 when it sees an ID parameter in ArgDeclList)

					} 
					else { // if parameter is an integer

						// mips
						createIntParameter(args[i], i+1, scope); // create mips for an integer parameter

					}
				} else if (isFloat == 0) { // if parameter is a float

					// mips
					createFloatParameter(args[i], i+1, scope); // create mips for a float parameter
	
				} else if (isChar == 0) { // if parameter is a char

					// mips
					createMIPSCharAssignment(result, args[i], scope); // create mips for a char parameter

				}
				
			}
			argCounter = 0; // revert argCounter to 0 (it gets incremented when counting arguments in ArgDeclList)

			// set scope back to global
			strcpy(scope, "G");

			// symbol table
			printf(BGREEN "Function Call --- Parameters Accepted\n" RESET); // output to console

			// mips again
			callMIPSFunction($3); // create mips for the calling of a function
			setVariableToReturn($1, $3, scope); // update the variable for the return type of this function

		}

	} |	WRITE ID SEMICOLON { printf(BORANGE "RULE: Write Statement (Var)\n" RESET); // e.g. write x;

		if (ifElseCurrentBlock == runIfElseBlock) { // if we are in an if block, both are 1, if we are in an else block, both are 0

			// semantic checks
				// is the id initialized as a value?
				initialized($2, scope); // symbol table function: exits if not initialized
			
			// symbol table
				// N/A

			// ast
			$$ = AST_BinaryExpression("Expr", $1, getValue($2, scope)); // add the write statement to the ast

			// ir code
			createWriteId($2, scope); // create ir code: output T0

			// mips
			// get the type of the variable
			char* type = getVariableType($2, scope);

			// determine if its int or char
			int isInt = strcmp(type, "INT"); // compare type to "INT"
			int isChar = strcmp(type, "CHR"); // compare type to "CHR"
			int isFloat = strcmp(type, "FLT"); // compare type to "FLT"

			// run correct mips function according to type
			if (isInt == 0) { // if the variable is an integer
				createMIPSWriteInt($2, scope); // create mips
			} 
			else if (isChar == 0) { // if the variable is a char
				createMIPSWriteChar($2, scope); // create mips
			} 
			else if (isFloat == 0) { // if the variable is a float
				createMIPSWriteFloat($2, scope); // create mips
			}

			// code optimization
				// mark the id as used
				isUsed($2, scope);

			/*
						Expr
				WRITE     getValue(ID)
			*/
		}

	} |	WRITE STRINGID SEMICOLON { printf(BORANGE "RULE: Write Statement (String)\n" RESET); // e.g. write "Hello World!";

		if (ifElseCurrentBlock == runIfElseBlock) { // if we are in an if block, both are 1, if we are in an else block, both are 0

			// semantic checks
				// N/A

			// symbol table
				// N/A

			// ast
			$$ = AST_BinaryExpression("Expr", $1, $2); // add expression to the ast

			// ir code
			char str[50]; // variable to hold string without apostrophes
			strcpy(str, removeApostrophes($2)); // remove apostrophes and copy string into str
			createWriteString(str); // create ir code: output "Hello World!""

			// mips code
			defineMIPSTempString(str); // create mips temp definition at the top of the file to hold the string
			createMIPSWriteString($2, scope); // create mips code to display the string in scope

			// code optimization
				// mark the id as used
				isUsed($2, scope);

		}

	} |	WRITE ID LBRACE NUMBER RBRACE SEMICOLON { printf(BORANGE "RULE: Write Statement (Array)\n" RESET); // e.g. write arr[0];

		if (ifElseCurrentBlock == runIfElseBlock) { // if we are in an if block, both are 1, if we are in an else block, both are 0

			// concatenate the array in this format: "$2[$4]"
			char elementID[50]; // holds the id of the element in the array
			strcpy(elementID, $2); // elementID: arr
			strcat(elementID, "["); // elementID: arr[
			strcat(elementID, $4); // elementID: arr[0
			strcat(elementID, "]"); // elementID: arr[0]

			// semantic checks
				// is the id initialized as a value?
				initialized(elementID, scope); // symbol table function: exits if not initialized
				
			// symbol table
				// N/A

			// ast
			$$ = AST_BinaryExpression("Expr", $1, getValue(elementID, scope)); // add expression to ast

			// ir code
			createWriteId(elementID, scope); // create ir code: T0 = arr[0]

			// mips code
				// get the type of the element
				char* type = getVariableType(elementID, scope); // symbol table function that returns type

				// determine if its int or char
				int isInt = strcmp(type, "INT"); // compare type to "INT"
				int isChar = strcmp(type, "CHR"); // compare type to "CHR"
				int isFloat = strcmp(type, "FLT"); // compare type to "FLT"

				// run correct mips function according to type
				if (isInt == 0) { // if the elemnt is an integer
					removeBraces(elementID); // remove the braces to make its name in mips
					createMIPSWriteInt(elementID, scope); // create mips to write the element
				} 
				else if (isChar == 0) { // if the element is a char
					removeBraces(elementID); // remove the braces to make its name in mips
					createMIPSWriteChar(elementID, scope); // create mips to write the element
				} 
				else if (isFloat == 0) { // if the element is a float
					removeBraces(elementID); // remove the braces to make its name in mips
					createMIPSWriteFloat(elementID, scope); // create mips to write the element
				}

			// code optimization
				// mark the id as used
				isUsed($2, scope);

		}

	} | WRITE NEWLINECHAR SEMICOLON { printf(BORANGE "RULE: New Line\n\n" RESET); // e.g. write ~nl;

		if (ifElseCurrentBlock == runIfElseBlock) { // if we are in an if block, both are 1, if we are in an else block, both are 0

			// ast
			$$ = AST_BinaryExpression("Expr", $1, "NEWLINE"); // add newline expression to ast

			// ir code
			createNewLine(); // create ir code: output *newline*

			// mips
			makeMIPSNewLine(scope); // create newline in mips

		}

	} | IDEQExpr SEMICOLON { printf(BORANGE "RULE: Math Statement\n\n" RESET); // e.g. x = 3 - 1; same as above, just can also be in a stmtList

		if (ifElseCurrentBlock == runIfElseBlock) { // if we are in an if block, both are 1, if we are in an else block, both are 0

			// ast
			$$ = $1;

		}

	} | ID LBRACE NUMBER RBRACE EQ NUMBER SEMICOLON { printf(BORANGE "RULE: Integer Array Index\n\n" RESET); // e.g. arr[0] = 1;

		if (ifElseCurrentBlock == runIfElseBlock) { // if we are in an if block, both are 1, if we are in an else block, both are 0

			// add backets to id
			char temp[50]; // temp variable to hold id with brackets
			sprintf(temp,"%s[%s]",$1,$3); // fills temp with: arr[0] for example

			// convert index to integer
			int index = atoi($3); // stores converted integer in index variable

			// symbol table
			updateArrayValue($1, index, scope, "INT", $6); // update value of the array element in the symbol table

			// symbol table
			if (strcmp(scope, "G") != 0) { // if scope is in function

				if (found(temp, scope) == 1) { // if the variable is found in the function's sym table

					updateArrayValue($1, index, scope, "INT", $6); // update value in function sym table

				} else if (found(temp, "G") == 1) { // if the variable is found in the global scope

					updateArrayValue($1, index, "G", "INT", $6); // update value in global sym table

				} else { // variable not found

					showSymTable(); // show symbol table
					printf(RED "\nERROR: Variable '%s' does not exist.\n\n" RESET, temp); // error message
					exit(0); // exit program

				}

			} else { // if scope is global
				updateArrayValue($1, index, scope, "INT", $6); // update value normally
			}

			// ast
			$$ = AST_assignment($1,$3,$6); // add expression to the ast

			// ir code
			createIntAssignment(temp, $6, scope); // create ir code

			// mips code
			if (strcmp(scope, "G") != 0) { // if scope is function

				if (found(temp, scope) == 1) { // if the variable is found in the function's sym table

					removeBraces(temp); // remove the braces to make its name in mips
					createMIPSIntAssignment(temp, $6, scope); // create mips to update the array element

				} else if (found(temp, "G") == 1) { // if the variable is found in the global scope

					removeBraces(temp); // remove the braces to make its name in mips
					createMIPSIntAssignment(temp, $6, "G"); // create mips to update the array element

				} else { // variable not found

					showSymTable(); // show symbol table
					printf(RED "\nERROR: Variable '%s' does not exist.\n\n" RESET, temp); // error message
					exit(0); // exit program

				}

			} 
			else { // if scope is global
				removeBraces(temp); // remove the braces to make its name in mips
				createMIPSIntAssignment(temp, $6, scope); // create mips to update the array element
			}

		}

	} | ID LBRACE NUMBER RBRACE EQ Math SEMICOLON { printf(BORANGE "RULE: Integer Array Index (Math)\n\n" RESET); // e.g. arr[0] = 1 + 2;

		if (ifElseCurrentBlock == runIfElseBlock) { // if we are in an if block, both are 1, if we are in an else block, both are 0

			system("python3 calculate.py"); // perform calculation
	
			char result[100]; // store result of calculation
			readEvalOutput(&result); // read the output and store in result
			clearCalcInput(); // clear the input to the calculator
			printf(RED"\nResult from evaluation ==> %s \n"RESET,result); // output result to console
	
			// convert index to integer
			int index = atoi($3); // convert index to integer and store in index variable

			// symbol table
			updateArrayValue($1, index, scope, "INT", result); // update array element in symbol table

			// ast
			$$ = AST_assignment($1,$3,result); // add expression to symbol table

			// ir code
			char temp[50]; // temp variable to hold id with brackets
			sprintf(temp,"%s[%s]",$1,$3); // fills temp with: arr[0] for example
			createIntAssignment(temp, result, scope); // create ir code

			// mips code
			if (strcmp(scope, "G") != 0) { // if scope is in function
				if (found(temp, scope) == 1) { // if the variable is found in the function scope
					removeBraces(temp); // remove the braces to make its name in mips
					createMIPSIntAssignment(temp, result, scope); // create mips to update the array element
				} 
				else if (found(temp, "G") == 1) { // if the variable is found in the global scope
					removeBraces(temp); // remove the braces to make its name in mips
					createMIPSIntAssignment(temp, result, "G"); // create mips to update the array element
				} 
				else { // variable not found
					showSymTable(); // show symbol table
					printf(RED "\nERROR: Variable '%s' does not exist.\n\n" RESET, temp); // error message
					exit(0); // exit program
				}
			} else { // if scope is global
				removeBraces(temp); // remove the braces to make its name in mips
				createMIPSIntAssignment(temp, result, scope); // create mips to update the array element
			}
		}
	
	} | ID LBRACE NUMBER RBRACE EQ CHARID SEMICOLON { printf(BORANGE "RULE: Char Array Index\n\n" RESET); // e.g. arr[0] = 'c';

		if (ifElseCurrentBlock == runIfElseBlock) { // if we are in an if block, both are 1, if we are in an else block, both are 0

			// add brackets to id for sym table searches
			char temp[50]; // temp variable to hold id with brackets
			sprintf(temp,"%s[%s]",$1,$3); // fills temp with: arr[0] for example

			// convert index to integer
			int index = atoi($3); // store converted array index in index variable

			// remove apostrophes from CHARID
			char* str = removeApostrophes($6); // remove apostrophes function from symbol table

			// symbol table
			if (strcmp(scope, "G") != 0) { // if scope is in function

				if (found(temp, scope) == 1) { // if the variable is found in the function's sym table

					updateArrayValue($1, index, scope, "CHR", str); // update value in function sym table

				} else if (found(temp, "G") == 1) { // if the variable is found in the global scope

					updateArrayValue($1, index, "G", "CHR", str); // update value in global sym table

				} else { // variable not found

					showSymTable(); // show symbol table
					printf(RED "\nERROR: Variable '%s' does not exist.\n\n" RESET, temp); // error message
					exit(0); // exit program

				}

			} else { // if scope is global
				updateArrayValue($1, index, scope, "CHR", str); // update value normally
			}

			// ast
			$$ = AST_assignment($1,$3,str); // add expression to the ast

			// ir code
			createIntAssignment(temp, str, scope); // create ir code

			// mips code
			if (strcmp(scope, "G") != 0) { // if scope is in function

				if (found(temp, scope) == 1) { // if the variable is found in the function's sym table

					removeBraces(temp); // remove the braces to make its name in mips
					createMIPSCharAssignment(temp, str, scope); // create mips to update the array element

				} else if (found(temp, "G") == 1) { // if the variable is found in the global scope

					removeBraces(temp); // remove the braces to make its name in mips
					createMIPSCharAssignment(temp, str, "G"); // create mips to update the array element

				} else { // variable not found

					showSymTable(); // show symbol table
					printf(RED "\nERROR: Variable '%s' does not exist.\n\n" RESET, temp); // error message
					exit(0); // exit program

				}

			} else { // if scope is global
				removeBraces(temp); // remove the braces to make its name in mips
				createMIPSCharAssignment(temp, str, scope); // create mips to update the array element
			}
		}

	} | ID LPAREN ArgDeclList RPAREN SEMICOLON { printf(BORANGE "RULE: Call Function\n\n" RESET); // e.g. addValue(1,2);

		if (ifElseCurrentBlock == runIfElseBlock) { // if we are in an if block, both are 1, if we are in an else block, both are 0

			// set scope to function
			strcpy(scope, $1);

			// loop through arguments
			for (int i = 0; i < argCounter; i++) {

				printf(BGREEN "IF Parameter Accepted\n" RESET); // output to console

				// ir code
				printf(BLUE "IR Code" RESET);
				printf(RED " NOT " RESET);
				printf(BLUE "Created\n" RESET); // ir code not yet created

				// variables for getting parameter name based on index
				char itemName[50]; // stores name of parameter
				char itemID[50]; // stores id of the parameter
				char result[50]; // stores the result of below function

				// get parameter name based on index of for loop
				sprintf(itemID, "%d", i); // convert i into a string
				sprintf(itemName, "%s", getNameByID(itemID, scope)); // add the name of the parameter into itemName
				strcpy(result, ""); // redundant
				strcat(result, itemName); // store itemName in result

				// variables to hold the type of the parameter
				char type[50];
				int isInt, isFloat, isChar;

				// get the type of the parameter
				sprintf(type, "%s", getVariableType(itemName, scope));
				
				// get type of parameter
				isInt = strcmp(type, "INT"); // compare type to "INT"
				isFloat = strcmp(type, "FLT"); // compare type to "FLT"
				isChar = strcmp(type, "CHR"); // compare type to "CHR"

				// run mips based on type
				if (isInt == 0) { // if parameter is an integer
					if (argIsID == 1) { // if parameter is an ID
						createIntIDParameter(IDArg, i+1, scope); // create integer ID parameter in mips
						argIsID = 0; // reset argIsID to 0 (gets changed to 1 in argDeclList)
					} 
					else { // if parameter is an integer number
						createIntParameter(args[i], i+1, scope); // create integer parameter in mips
					}
				} 
				else if (isFloat == 0) { // if parameter is a float
					createFloatParameter(args[i], i+1, scope); // create float parameter in mips
				} 
				else if (isChar == 0) { // if parameter is a char
					createMIPSCharAssignment(result, args[i], scope); // create char parameter in mips
				}
			}
			argCounter = 0; // reset argCounter to 0 (gets set to 1 when counting arguments in argDeclList)

			// set scope back to global
			strcpy(scope, "G");

			// symbol table
			printf(BGREEN "Function Call --- Parameters Accepted\n" RESET); // output to console

			// ast
			$$ = AST_assignment($1,$2,$4); // add expression to the ast

			// ir code
			printf(BLUE "IR Code" RESET);
			printf(RED " NOT " RESET);
			printf(BLUE "Created\n" RESET); // ir code currently not needed

			// mips
			callMIPSFunction($1); // create function call in mips

		}

	} | RETURN ID SEMICOLON { printf(BORANGE "RULE: Return Statement (ID)\n\n" RESET); // e.g. return x; (inside a function)

		if (ifElseCurrentBlock == runIfElseBlock) { // if we are in an if block, both are 1, if we are in an else block, both are 0

			// symbol table
			updateValue(scope, "G", getValue($2, scope)); // update the value of the function in the global table
			printf(BGREEN "Updated ID Return Value of Function.\n" RESET); // output to console

			// ir code
			printf(BLUE "IR Code" RESET);
			printf(RED " NOT " RESET);
			printf(BLUE "Created\n" RESET); // ir code not currently needed

			// temp variables
			char str[50]; // temp string to hold variable type
			strcpy(str, getVariableType($2, scope)); // store variable type in 'str'

			char str1[50]; // temp string to hold "G{scope}"
			strcpy(str1, "G"); // store "G" in 'str1'
			strcat(str1, scope); // concatenate the scope to 'str1'

			char str2[50]; // temp string to hold "{scope}Return" for function return variable in mips
			strcpy(str2, scope); // store scope in 'str2'
			strcat(str2, "Return"); // concatenate "Return" to 'str2'
			
			// mips based on type
			if (strcmp(str, "INT") == 0) { // if the id is an integer

				// ir code
				createReturnIDStatement($2); // create ir code: return T2

				// mips
				createMIPSReturnStatementNumber(str2, $2, getValue($2, scope), scope); // create mips return variable

			} 
			else if (strcmp(str, "FLT") == 0) { // if the id is a float

				// ir code
				createReturnIDStatement($2); // create ir code: return T2

				// mips
				createMIPSFloatAssignment("", getValue($2, scope), str1); // create mips return variable

			} 
			else if (strcmp(str, "CHR") == 0) { // if the id is char

				// ir code
				createReturnIDStatement($2); // create ir code: return T2

				// mips
				createMIPSCharAssignment("", getValue($2, scope), str1); // create mips return variable
			}
			
		}

	} | RETURN NUMBER SEMICOLON { printf(BORANGE "RULE: Return Statement (INT)\n\n" RESET);

		if (ifElseCurrentBlock == runIfElseBlock) { // if we are in an if block, both are 1, if we are in an else block, both are 0
			// symbol table
			updateValue(scope, "G", $2);
			printf(BGREEN "Updated Integer Return Value of Function.\n" RESET);

			// ir code
			printf(BLUE "IR Code" RESET);
			printf(RED " NOT " RESET);
			printf(BLUE "Created\n" RESET);

			// mips
			// create scope so that it has G and then the function scope, since
			// we are accessing the global variable that is called the function name
			char str[50];
			strcpy(str, "G");
			strcat(str, scope);

			createMIPSIntAssignment("", $2, str);
		}

	} | RETURN FLOATNUM SEMICOLON {

		if (ifElseCurrentBlock == runIfElseBlock) { // if we are in an if block, both are 1, if we are in an else block, both are 0
			// symbol table
			updateValue(scope, "G", $2);
			printf(BGREEN "Updated Float Return Value of Function.\n" RESET);

			// ir code
			printf(BLUE "IR Code" RESET);
			printf(RED " NOT " RESET);
			printf(BLUE "Created\n" RESET);

			// mips
			// create scope so that it has G and then the function scope, since
			// we are accessing the global variable that is called the function name
			char str[50];
			strcpy(str, "G");
			strcat(str, scope);

			createMIPSFloatAssignment("", $2, str);
		}

	} | RETURN CHARID SEMICOLON {

		if (ifElseCurrentBlock == runIfElseBlock) { // if we are in an if block, both are 1, if we are in an else block, both are 0
			// symbol table
			updateValue(scope, "G", $2);
			printf(BGREEN "Updated Char Return Value of Function.\n" RESET);

			// ir code
			printf(BLUE "IR Code" RESET);
			printf(RED " NOT " RESET);
			printf(BLUE "Created\n" RESET);

			// mips
			char str[50];
			strcpy(str, "G");
			strcat(str, scope);
			createMIPSCharAssignment("", $2, str);
		}

}

/*----end expr----------------------------------------------------------------------------------------------------------*/



IDEQExpr: ID EQ MathStmt {

	// ast
	// TODO: EVAN
	if (scope == "G") { 

		system("python3 calculate.py");
		
		char result[100];
		readEvalOutput(&result);
		clearCalcInput();
		printf(RED"\nResult from evaluation ==> %s \n"RESET,result);

		// semantic checks
			// inside Math

		// calculations: code optimization
			// turn the integer returned from calculate() into a string

		// symbol table

		if (strcmp(scope, "G") != 0) { // if scope is in function

			if (found($1, scope) == 1) { // if the variable is found in the function's sym table

				updateValue($1, scope, result); // update value in function sym table

			} else if (found($1, "G") == 1) { // if the variable is found in the global scope

				updateValue($1, "G", result); // update value in global sym table

			}

		} else { // if scope is global
			updateValue($1, scope, result); // update value normally
		}

		// ast
		$$ = AST_BinaryExpression("=", $1, result);

		
		char type[50];

		strcpy(type,getVariableType($1,scope));

		if (strcmp(type,"INT") == 0){
			// ir code
			createIntAssignment($1, result, scope);

			// mips code
			createMIPSIntAssignment($1, result, scope);
		}

		else if(strcmp(type,"FLT") == 0){
			// ir code
			createFloatAssignment($1, result, scope);

			// mips code
			createMIPSFloatAssignment($1, result, scope);
		}

		
		// code optimization
		// mark the id as used
		isUsed($1, scope);

	} else {

		if (scope != "G") { // in a function

			if (op == '+') {

				// ir code
				createFunctionAddition($1);

				// mips
				createMIPSParameterAddition($1, scope);

			} else if (op == '-') {

				// ir code
				createFunctionSubtraction($1);

				// mips
				createMIPSSubtraction($1, num1, num2, scope);
			}
		
		} 

	}

}

MathStmt: Math MathStmt {

}

		| Math {

}


Math: LPAREN {addToInputCalc($1);}
		| RPAREN {addToInputCalc($1);}
		| ID {
			addToInputCalc(getValue($1,scope)); 
			strcpy(num1, $1);
		} 

		| NUMBER {
			addToInputCalc($1); 
			strcpy(num2, $1); 
		
		}
		| FLOATNUM {addToInputCalc($1);}
		| EXPONENT {addToInputCalc("**");}
		| Operator {addToInputCalc($1);}



Operator: ADD {op = '+';}	
		| SUB {op = '-';}
		| MULTIPLY {op = '*';}
		| DIV {op = '/';}


CompOperator: DEQ {}
			| LT {}
			| GT {}
			| LEQ {}
			| GEQ {}
			| NOTEQ {}

// ARRAY DECLARATIONS ----------------------------------------------------------------------
ArrDecl:	
			INT ID LBRACE RBRACE SEMICOLON { printf(BORANGE "RULE: Integer Array Initialization\n\n" RESET);
				//int foo[]; //We should only have arrays be declared with range imo.



			} | CHAR ID LBRACE RBRACE SEMICOLON { printf(BORANGE "RULE: Char Array Initialization\n\n" RESET);
				//char foo[]; //We should only have arrays be declared with range imo.

			

			} | INT ID LBRACE NUMBER RBRACE SEMICOLON { printf(BORANGE "RULE: Integer Array Initialization\n\n" RESET);
				// e.g. int foo[4];

						if (ifElseCurrentBlock == runIfElseBlock) {
							// semantic checks
							symTabAccess();

								// is the range > 0?
								if (atoi($4) <= 0) {
									printf(RED "\nERROR: Array range must be greater than 0.\n" RESET,$2);
									showSymTable(); // show symbol table
									exit(0); // array already declared
								}

								// is the array already declared in this scope?			
								// add "[0]" to the ID
								char temp[50];	
								sprintf(temp,"%s[0]",$2);

								if (found(temp, scope) == 1) {
									printf(RED "\nERROR: Array '%s' already declared in this scope.\n" RESET,$2);
									showSymTable(); // show symbol table
									exit(0); // array already declared
								}

							// symbol table
							addArray($2, "ARR", "INT", $4, scope);

							// ast
							$$ = AST_assignment("ARR",$1,$2);

							// ir code
							int range = atoi($4);
							//printf("\n%d\n", range);
							for (int i = 0; i < range; i++) {
								char temp[50];	
								sprintf(temp,"%s[%d]",$2,i);
								createIntDefinition(temp, scope);
							}
							printf("\n\n");
						}

			} | CHAR ID LBRACE NUMBER RBRACE SEMICOLON { printf(BORANGE "RULE: Char Array Initialization\n\n" RESET);
				// e.g. char foo[5];
	
						if (ifElseCurrentBlock == runIfElseBlock) {
							// semantic checks
							symTabAccess();

								// is the range > 0?
								if (atoi($4) <= 0) {
									printf(RED "\nERROR: Array range must be greater than 0.\n" RESET,$2);
									showSymTable(); // show symbol table
									exit(0); // array already declared
								}
								// is the array already declared?
								// add "[0]" to the ID
								char temp[50];	
								sprintf(temp,"%s[0]",$2);
								
								if (found(temp, scope) == 1) {
									printf(RED "\nERROR: Array '%s' already declared in this scope.\n" RESET,$2);
									showSymTable();
									exit(0); // variable already declared
								}

							// symbol table
							addArray($2, "ARR", "CHR", $4, scope);

							// ast
							$$ = AST_assignment("ARR",$1,$2);

							// ir code
							int range = atoi($4);
							//printf("\n%d\n", range);
							for (int i = 0; i < range; i++) {
								sprintf(temp,"%s[%d]",$2,i);
								createIntDefinition(temp, scope);
							}
							printf("\n\n");
						}

}; 

IfStmt: IF {inElse = UPDATE_IF_ELSE;} LPAREN Condition RPAREN { printf(BORANGE "RULE: If-Else Statement Initialization \n\n" RESET);
						
						inElse = 0; //reset before block since Condition has been run already		 
						ifElseCurrentBlock = IN_IF_BLOCK;
						 
						 } Block { printf(BORANGE "\nRULE: IF Statement Block\n\n" RESET);

							if (runIfElseBlock == RUN_IF_BLOCK) {
								
								printf(BORANGE "Done with If Statement.\n\n" RESET);

							}

							ifElseCurrentBlock = IN_ELSE_BLOCK;

						 } ElseStmt { printf(BORANGE "\nRULE: ELSE Statement Block\n\n" RESET);

							if (runIfElseBlock == RUN_ELSE_BLOCK) {
								
								printf(BORANGE "Done With Else Statement.\n\n" RESET);

							}
							runIfElseBlock = 0; // reset the pass variable
							ifElseCurrentBlock = 0; // reset the current variable

}

ElseStmt: | ELSE Block

Condition: NUMBER CompOperator NUMBER {

				int temp1, temp2;
				temp1 = atoi($1);
				temp2 = atoi($3);

				if (compareIntOp($2, temp1, temp2)) {
					runIfElseBlock = 1;
				}


		} | ID CompOperator ID {

				char type1[50];
				char type2[50];
				strcpy(type1, getVariableType($1, scope));
				strcpy(type2, getVariableType($3, scope));
				//printf(BORANGE "type1: %s\ntype2: %s\n" RESET, type1, type2);

				// semantic checks
				// are the types the same?
				int check;
				check = strcmp(type1, type2);

				if (!check) { // if the types are the same
					printf(BGREEN "\nID types are the same.\n" RESET);
				} else {
					printf(RED "\nERROR: Trying to compare two ID's that are not of the same type.\n" RESET);
					showSymTable();
					exit(0);
				}

				// are the variables intitalized as a value?
				check = strcmp(getValue($1, scope), "NULL");

				if (!check) { // if first ID is NULL
					printf(RED "\nERROR: ID '%s' is not assigned to a value.\n" RESET, $1);
					showSymTable();
					exit(0);
				}

				check = strcmp(getValue($3, scope), "NULL");

				if (!check) { // if second ID is NULL
					printf(RED "\nERROR: ID '%s' is not assigned to a value.\n" RESET, $3);
					showSymTable();
					exit(0);
				}

				// go further based on type of id's
				int typeInt, typeFloat, typeChar;
				typeInt = strcmp(type1, "INT");
				typeFloat = strcmp(type1, "FLT");
				typeChar = strcmp(type1, "CHR");

				if (!typeInt) { // if type is integer
					int temp1, temp2;
					temp1 = atoi(getValue($1, scope));
					temp2 = atoi(getValue($3, scope));
					//printf(BORANGE "temp1: %d\ntemp2: %d\n" RESET, temp1, temp2);

					if (compareIntOp($2, temp1, temp2) && inElse == UPDATE_IF_ELSE) {
					runIfElseBlock = 1;
					}
				}
				else if (!typeFloat) { // if type is float
					float temp1, temp2;
					temp1 = atof(getValue($1, scope));
					temp2 = atof(getValue($3, scope));
					//printf(BORANGE "temp1: %f\ntemp2: %f\n" RESET, temp1, temp2);

					if (compareFloatOp($2, temp1, temp2) && inElse == UPDATE_IF_ELSE) {
					runIfElseBlock = 1;
					}
				}
				else if (!typeChar) { // if type is char
					char temp1[50], temp2[50];
					strcpy(temp1, getValue($1, scope));
					strcpy(temp2, getValue($3, scope));
					//printf(BORANGE "temp1: %s\ntemp2: %s\n" RESET, temp1, temp2);

					if (compareCharOp($2, temp1, temp2) && inElse == UPDATE_IF_ELSE) {
					runIfElseBlock = 1;
					}
				}


		} | ID CompOperator NUMBER {

				// is the variable intitalized as a value?
				int check;
				check = strcmp(getValue($1, scope), "NULL");

				if (!check) { // if first ID is NULL
					printf(RED "\nERROR: ID '%s' is not assigned to a value.\n" RESET, $1);
					showSymTable();
					exit(0);
				}

				int temp1, temp2;
				temp1 = atoi(getValue($1, scope));
				temp2 = atoi($3);

				if (compareIntOp($2, temp1, temp2)) {
					runIfElseBlock = 1;
				}


		} | FLOATNUM CompOperator FLOATNUM {

				float temp1, temp2;
				temp1 = atof($1);
				temp2 = atof($3);
				//printf(BORANGE "temp1: %f\ntemp2: %f\n" RESET, temp1, temp2);

				if (compareFloatOp($2, temp1, temp2) && inElse == UPDATE_IF_ELSE) {
					runIfElseBlock = 1;
				}

		} | CHARID CompOperator CHARID {

				char temp1[50], temp2[50];
				strcpy(temp1, $1);
				strcpy(temp2, $3);
				//printf(BORANGE "temp1: %s\ntemp2: %s\n" RESET, temp1, temp2);

				if (compareCharOp($2, temp1, temp2) && inElse == UPDATE_IF_ELSE) {
					runIfElseBlock = 1;
				}

		}



ConditionVar:	NUMBER {

			} | ID {
				
			} | FLOATNUM {
				
			} | CHARID {

			}

%%

int main(int argc, char**argv)
{

	/*
	#ifdef YYDEBUG
		yydebug = 1;
	#endif
	*/

	printf(BORANGE "\n\n -----------------------> COMPILER STARTED <----------------------- \n\n" RESET);
	clearCalcInput();
	initializeSymbolTable();
	changeIRFile(IR_CODE);
	changeMIPSFile(TEMP_MIPS);

	// initialize ir code file
	initIRcodeFile();

	// initialize mips code file
	initAssemblyFile();
	
	if (argc > 1){
	  if(!(yyin = fopen(argv[1], "r")))
          {
		perror(argv[1]);
		return(1);
	  }
	}
	yyparse();
	

	printf(BORANGE "\n\n --------------------->" RESET);
	printf(BORANGE " COMPILER ENDED " RESET);
	printf(BORANGE "<--------------------- \n\n" RESET);
	
	printf("\n\n ---------------------" RESET);
	printf(BCYAN " SHOW SYMBOL TABLE " RESET);
	printf("--------------------- \n" RESET);
	showSymTable();

	//printf("\n\n ---------------------" RESET);
	//printf(BCYAN " SHOW ARRAY TABLES " RESET);
	//printf("--------------------- \n\n" RESET);
	//showArrTable();

	printf("\n\n\n ---------------------" RESET);
	printf(BCYAN " END SYMBOL TABLE " RESET);
	printf("--------------------- \n\n" RESET);
	
	//printf("\n\n\n ---------------------" RESET);
	//printf(BCYAN " REMOVE UNUSED VARIABLES " RESET);
	//printf("--------------------- n\n" RESET);
	//cleanAssemblyCodeOfUnsuedVariables();
	//printf("--------------------- \n\n" RESET);
}

void yyerror(const char* s) {
	fprintf(stderr, RED "\nBison Parse Error: %s\n" RESET, s);
	showSymTable();
	exit(1);
}
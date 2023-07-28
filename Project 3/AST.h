
//Abstract Syntax Tree Implementation
#include <string.h>
#include <stdio.h>


// Define the structure of an AST node. Each node has a type (nodeType), left-hand-side (LHS) and right-hand-side (RHS).
// Also, each node has pointers to left and right child nodes in the tree.
struct AST{
	char nodeType[50];
	char LHS[50];
	char RHS[50];
	
	struct AST * left;
	struct AST * right;
	// review pointers to structs in C 
	// complete the tree struct with pointers
};


// Function to create an assignment node in AST.
struct AST * AST_assignment(char nodeType[50], char LHS[50], char RHS[50]){
	

	struct AST* ASTassign = malloc(sizeof(struct AST));
	strcpy(ASTassign->nodeType, nodeType);
	strcpy(ASTassign->LHS, LHS);
	strcpy(ASTassign->RHS, RHS);
	
	return ASTassign;
	
}

// Function to create a binary expression node in AST.
struct AST * AST_BinaryExpression(char nodeType[50], char LHS[50], char RHS[50]){

	struct AST* ASTBinExp = malloc(sizeof(struct AST));
	strcpy(ASTBinExp->nodeType, nodeType);
	strcpy(ASTBinExp->LHS, LHS);
	strcpy(ASTBinExp->RHS, RHS);
	return ASTBinExp;
	
}
// Function to create a type node in AST. The type node represents the type of a variable or expression.
struct AST * AST_Type(char nodeType[50], char LHS[50], char RHS[50]){

	struct AST* ASTtype = malloc(sizeof(struct AST));
	strcpy(ASTtype->nodeType, nodeType);
	strcpy(ASTtype->LHS, LHS);
	strcpy(ASTtype->RHS, RHS);
		
	return ASTtype;
	
}


// Function to create a function node in AST. This node represents a function in the program.
struct AST * AST_Func(char nodeType[50], char LHS[50], char RHS[50]){
	
	struct AST* ASTtype = malloc(sizeof(struct AST));
	strcpy(ASTtype->nodeType, nodeType);
	strcpy(ASTtype->LHS, LHS);
	strcpy(ASTtype->RHS, RHS);
		
	return ASTtype;
	
}

// Function to create a write node in AST. This node represents a write operation in the program.
struct AST * AST_Write(char nodeType[50], char LHS[50], char RHS[50]){
	
	struct AST* ASTtype = malloc(sizeof(struct AST));
	strcpy(ASTtype->nodeType, nodeType);
	strcpy(ASTtype->LHS, LHS);
	strcpy(ASTtype->RHS, RHS);
		
	return ASTtype;
	
}

// Function to print a number of dots, used to help visualize the tree structure in the printAST function.
void printDots(int num)
{
	for (int i = 0; i < num; i++)
		printf("       ");
}

// Function to print the AST structure starting from the given node. 
// The function is recursive and traverses the tree depth-first. 
// 'level' is used to determine the amount of indentation for visualization purposes.
void printAST(struct AST* tree, int level){
	if (tree == NULL) return;
	printDots(level);

	printf("%s\n", tree->nodeType);
	printDots(level);

	printf("%s %s\n", tree->LHS, tree->RHS);
	if(tree->left != NULL) printAST(tree->left, level+1); else return;
	if(tree->right != NULL) printAST(tree->right, level+1); else return;
	
}

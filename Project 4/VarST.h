#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Linked list structure for tracking functions
struct linked_list_of_function {
    char name[50];
    struct linked_list_of_function *next;
    struct linked_list_of_function *prev;
};
// Initialize an empty function list
struct linked_list_of_function *init_function_list() {
    struct linked_list_of_function *head = NULL;
    return head;
};

// Old add a new function to the function list new one is in FunctionST.h
void add_to_function_list(char *name[50], struct linked_list_of_function **function_list) {
    struct linked_list_of_function *temp = (struct linked_list_of_function *)malloc(sizeof(struct linked_list_of_function));
    strcpy(temp->name,*name);
    temp->next = NULL;


    if ((*function_list) == NULL) {
        *function_list = temp;
        temp->prev = NULL;
        return;
    }
    else {
        struct linked_list_of_function *temp2;
        temp2 = (*function_list);
        while (temp2->next != NULL) {
            temp2 = temp2->next;
        }
        temp2->next = temp;
        temp->prev = temp2;
        return;
    }
}


struct VarSymTableEntry
{
	int itemID;
	char itemName[50];
	char itemKind[8];
	char itemType[8];
	int arrayLength;
	int intVal;
	double floatVal;
	char charVal[50];
	char functionName[50];
	char scope[50];
};


struct VarSymTableEntry symTabItems[100];
int symTabIndex = 0;
int SYMTAB_SIZE = 30;

void symTabAccess(void){
	printf("ACCESSED SYMBOLTABLE\n\n");
}

// Add an item to the symbol table
void addItemVST(char itemName[50], char itemKind[8], char itemType[8], int arrayLength, char *scope[50]){
	

		symTabItems[symTabIndex].itemID = symTabIndex;
		strcpy(symTabItems[symTabIndex].itemName, itemName);
		strcpy(symTabItems[symTabIndex].itemKind, itemKind);
		strcpy(symTabItems[symTabIndex].itemType, itemType);
		symTabItems[symTabIndex].intVal = 0;
		symTabItems[symTabIndex].floatVal = 0;
		strcpy(symTabItems[symTabIndex].charVal, "NULL");
		strcpy(symTabItems[symTabIndex].functionName, "NULL");
		symTabItems[symTabIndex].arrayLength = arrayLength;
		strcpy(symTabItems[symTabIndex].scope, scope);
		symTabIndex++;
	
}


// Set an integer value for an item in the symbol table
int setVal(char itemName[50], char intVal[50], char scope[50]){
	int intValint = atoi(intVal);
	printf("itemName: %s\n", itemName);
	for(int i=0; i<SYMTAB_SIZE; i++){
		int str1 = strcmp(symTabItems[i].itemName, itemName);
		int str2 = strcmp(symTabItems[i].scope,scope);	
		if( str1 == 0){
			symTabItems[i].intVal = intValint;
			printf("finished\n");
			return 1;
		}
	}
	return 0;
}
// Set a float value for an item in the symbol table
double setfloatVal(char itemName[50], char intVal[50], char scope[50]){
	double intValint = atof(intVal);
	printf("float val: %f\n", intValint);
	printf("itemName: %s\n", itemName);
	for(int i=0; i<SYMTAB_SIZE; i++){
		int str1 = strcmp(symTabItems[i].itemName, itemName);
		int str2 = strcmp(symTabItems[i].scope,scope);	
		if( str1 == 0){
			symTabItems[i].floatVal = intValint;
			printf("finished\n");
			return 1;
		}
	}
	return 0;
}
// Set a character value for an item in the symbol table
int setcharVal(char itemName[50], char CharVal[50], char scope[50]){
	for(int i=0; i<SYMTAB_SIZE; i++){
		int str1 = strcmp(symTabItems[i].itemName, itemName);
		int str2 = strcmp(symTabItems[i].scope,scope);	
		if( str1 == 0){
			strcpy(symTabItems[i].charVal, CharVal);
			printf("finished\n");
			return 1;
		}
	}
	return 0;
}



// Display the current status of the symbol table
void showVarSymTable(){
	printf("----------------------------------------Global Variable Symbol Table------------------------------------------\n");
	printf("itemID    Name     Int      float       Char      itemKind        Type   ArrayLength     FunName    itemScope\n");
	printf("--------------------------------------------------------------------------------------------------------------\n");
	for (int i=0; i<symTabIndex; i++){
		printf("%5d %8s %9d \t%0.2f %9s %9s %11s %10d %14s %14s \n",symTabItems[i].itemID, symTabItems[i].itemName, symTabItems[i].intVal, symTabItems[i].floatVal, symTabItems[i].charVal, symTabItems[i].itemKind, symTabItems[i].itemType, symTabItems[i].arrayLength, symTabItems[i].functionName, symTabItems[i].scope);
	}
	printf("--------------------------------------------------------------------------------------------------------------\n");
}

// Check if an item exists in the symbol table under a given scope
int found(char itemName[50], char scope[50]){
	for(int i=0; i<SYMTAB_SIZE; i++){
		int str1 = strcmp(symTabItems[i].itemName, itemName); 
		int str2 = strcmp(symTabItems[i].scope,scope); 
		if( str1 == 0 && str2 == 0){
			return 1;
		} 
	}
	return 0;
}

// Get the integer value of an item in the symbol table
int getVal(char itemName[50],char scope[50]){
	int returnNum;
	for(int i=0; i<SYMTAB_SIZE; i++){
		int str1 = strcmp(symTabItems[i].itemName, itemName); 
		int str2 = strcmp(symTabItems[i].scope,scope); 
			if( str1 == 0 && str2 == 0){
				returnNum = symTabItems[i].intVal;
				return symTabItems[i].intVal;
		
			}
	}

	return 0;
}

void printVal(){
	for(int i = 0; i < 4; i++) {
		printf("%7d\n", symTabItems[i].intVal);
	}
}


// Get the ID of an item in the symbol table
int getItemID(char itemName[50],char scope[50]){
	int returnID;
	for(int i=0; i<SYMTAB_SIZE; i++){
		int str1 = strcmp(symTabItems[i].itemName, itemName); 
		int str2 = strcmp(symTabItems[i].scope,scope); 
		if( str1 == 0 && str2 == 0){
			returnID = (int)(symTabItems[i].itemID)+0;
			return returnID; 
	
		}
	}
	return 0;
}

// Function to get the data type of a variable in the symbol table
const char* getVariableType(char itemName[50], char scope[50]){

	for(int i=0; i<SYMTAB_SIZE; i++){
		int str1 = strcmp(symTabItems[i].itemName, itemName); 
		int str2 = strcmp(symTabItems[i].scope,scope); 
		if( str1 == 0 && str2 == 0){
			return symTabItems[i].itemType;
		}
	}
	return NULL;
}

// Function to compare the types of two variables in the symbol table
int compareTypes(char itemName1[50], char itemName2[50],char scope){
	const char* idType1 = getVariableType(itemName1, scope);
	const char* idType2 = getVariableType(itemName2, scope);
	
	printf("%s = %s\n", idType1, idType2);
	
	int typeMatch = strcmp(idType1, idType2);
	if(typeMatch == 0){
		return 1; 
	}
	else return 0;
}


    

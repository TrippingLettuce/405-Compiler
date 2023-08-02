#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct FuncSymTable
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

struct FuncSymTable funcSymTabIteam[100];
int funcSymTabIteamCount = 0;
int FUNSYMTAB_SIZE = 30;

void add_Item_to_func_sym_table(char itemName[50], char *itemKind[50], char *itemType[50], int arrayLength, char *FunctionName[50], char *scope[50]){
	
	funcSymTabIteam[funcSymTabIteamCount].itemID = funcSymTabIteamCount;
	strcpy(funcSymTabIteam[funcSymTabIteamCount].itemName, itemName);
	funcSymTabIteam[funcSymTabIteamCount].intVal = 0;
	funcSymTabIteam[funcSymTabIteamCount].floatVal = 0;
	strcpy(funcSymTabIteam[funcSymTabIteamCount].charVal, "NULL");
	strcpy(funcSymTabIteam[funcSymTabIteamCount].functionName, FunctionName);
	strcpy(funcSymTabIteam[funcSymTabIteamCount].itemKind, itemKind);
	strcpy(funcSymTabIteam[funcSymTabIteamCount].itemType, itemType);
	strcpy(funcSymTabIteam[funcSymTabIteamCount].scope, scope);
	funcSymTabIteamCount++;
	
}

void showFuncSymTable(){
	printf("----------------------------------------------Functions Symbol Table----------------------------------------\n");
	printf("itemID    itemName  intVal   floatVal   CharVal    itemKind    itemType   ArrayLength    FunName   itemScope\n");
	printf("------------------------------------------------------------------------------------------------------------\n");
	for (int i=0; i<funcSymTabIteamCount; i++){
		printf("%5d %11s %7d \t%0.2f %9s %9s %11s %10d %14s %14s \n",funcSymTabIteam[i].itemID, funcSymTabIteam[i].itemName, funcSymTabIteam[i].intVal, funcSymTabIteam[i].floatVal, funcSymTabIteam[i].charVal, funcSymTabIteam[i].itemKind, funcSymTabIteam[i].itemType, funcSymTabIteam[i].arrayLength, funcSymTabIteam[i].functionName, funcSymTabIteam[i].scope);
	}
	printf("------------------------------------------------------------------------------------------------------------\n");
}

void FunsymTabAccess(void){
    printf("ACCESSED FUNCTION SYMBOLTABLE\n\n");
}
int set_Int_Fun_Val(char itemName[50], char intVal[50], char scope[50]){
	int intValint = atoi(intVal);
	printf("itemName: %s\n", itemName);
	for(int i=0; i<FUNSYMTAB_SIZE; i++){
		int str1 = strcmp(funcSymTabIteam[i].itemName, itemName);
		int str2 = strcmp(funcSymTabIteam[i].scope,scope);	
		if( str1 == 0){
			funcSymTabIteam[i].intVal = intValint;
			printf("finished\n");
			return 1;
		}
	}
	return 0;
}

double set_float_Fun_Val(char itemName[50], char intVal[50], char scope[50]){
	double intValint = atof(intVal);
	printf("float val: %f\n", intValint);
	printf("itemName: %s\n", itemName);
	for(int i=0; i<FUNSYMTAB_SIZE; i++){
		int str1 = strcmp(funcSymTabIteam[i].itemName, itemName);
		int str2 = strcmp(funcSymTabIteam[i].scope,scope);	
		if( str1 == 0){
			funcSymTabIteam[i].floatVal = intValint;
			printf("finished\n");
			return 1;
		}
	}
	return 0;
}

int set_fun_char_val(char itemName[50], char CharVal[50], char scope[50]){
	for(int i=0; i<FUNSYMTAB_SIZE; i++){
		int str1 = strcmp(funcSymTabIteam[i].itemName, itemName);
		int str2 = strcmp(funcSymTabIteam[i].scope,scope);	
		if( str1 == 0){
			strcpy(funcSymTabIteam[i].charVal, CharVal);
			printf("finished\n");
			return 1;
		}
	}
	return 0;
}




int found_in_fun_sym(char itemName[50], char scope[50]){
	for(int i=0; i<FUNSYMTAB_SIZE; i++){
		int str1 = strcmp(funcSymTabIteam[i].itemName, itemName); 
		int str2 = strcmp(funcSymTabIteam[i].scope,scope); 
		if( str1 == 0 && str2 == 0){
			return 1;
		} 
	}
	return 0;
}


int getVal_from_fun_sym(char itemName[50],char scope[50]){
	int returnNum;
	for(int i=0; i<FUNSYMTAB_SIZE; i++){
		int str1 = strcmp(funcSymTabIteam[i].itemName, itemName); 
		int str2 = strcmp(funcSymTabIteam[i].scope,scope); 
			if( str1 == 0 && str2 == 0){
				returnNum = funcSymTabIteam[i].intVal;
				return funcSymTabIteam[i].intVal;
		
			}
	}

	return 0;
}


int getItemID_fun_sym(char itemName[50],char scope[50]){
	int returnID;
	for(int i=0; i<FUNSYMTAB_SIZE; i++){
		int str1 = strcmp(funcSymTabIteam[i].itemName, itemName); 
		int str2 = strcmp(funcSymTabIteam[i].scope,scope); 
		if( str1 == 0 && str2 == 0){
			returnID = (int)(funcSymTabIteam[i].itemID)+0;
			return returnID; 
	
		}
	}
	return 0;
}

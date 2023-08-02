#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void write_var_to_string(char var_array[50]){
    FILE * VarFile;
    VarFile = fopen("./WhileOps/static/vars.txt", "a");
    fprintf(VarFile,"%s", var_array);
    fclose(VarFile);
}   

void write_cond_to_string(char cond_array[50]){
    FILE * CondFile;
    CondFile = fopen("./WhileOps/static/cond.txt", "w");
    fprintf(CondFile,"%s", cond_array);
    fclose(CondFile);
}

void write_blcok_to_string(char while_array[50]){
    FILE * WhileFile;
    WhileFile = fopen("./WhileOps/static/block.txt", "a");
    fprintf(WhileFile,"%s", while_array);
    fclose(WhileFile);
}

void clearBlockFile(){
    char clearCMD[50], clearCMD2[50];
    strcpy(clearCMD, "rm -f ./WhileOps/static/block.txt" );
	system(clearCMD);
}

void create_block_file(){
    char clearCMD[50], clearCMD2[50];
    strcpy(clearCMD, "touch ./WhileOps/static/block.txt" );
	system(clearCMD);
}

void clearVarFile(){
    char clearCMD[50], clearCMD2[50];
    strcpy(clearCMD, "rm -f ./WhileOps/static/vars.txt" );
	system(clearCMD);
}

void create_Var_file(){
    char clearCMD[50], clearCMD2[50];
    strcpy(clearCMD, "touch ./WhileOps/static/vars.txt" );
	system(clearCMD);
}
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void addToInputCalc(char input[100]) {
    // creating file pointer to work with files
    FILE *file;
    // opening file in writing mode
    file = fopen("calc.input", "a");
    fprintf(file, "%s",input);
    fclose(file);

}

void readEvalOutput(char *result){
    // creating file pointer to work with files
    FILE *file;
    // opening file in writing mode
    file = fopen("calc.output", "r");
    fscanf(file,"%s",result);
    if (strcmp(result,"ERROR") == 0){
        exit(0);
    }
    fclose(file);
}

void clearCalcInput(){
    FILE *file;
    file = fopen("calc.input", "w");
    fclose(file);
}


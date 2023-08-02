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

void readEvalOutput(char* result) {
    // Creating a file pointer to work with files
    FILE* file;
    // Opening file in reading mode
    file = fopen("calc.output", "r");
    fscanf(file, "%s", result);
    if (strcmp(result, "ERROR") == 0) {
        exit(0);
    }
    fclose(file);

    // Write the result to the new file
    writeResultToNewFile(result);
}

void clearCalcInput(){
    FILE *file;
    file = fopen("calc.input", "w");
    fclose(file);
}


//Newww
void writeResultToNewFile(char* result) {
    // Creating a file pointer
    FILE* file;
    // Opening the file in write mode
    file = fopen("results.input", "w");
    // Write the result to the file
    fprintf(file, "%s", result);
    // Closing the file
    fclose(file);
}




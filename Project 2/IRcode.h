#include <stdio.h>

// ---- Functions to handle IR code emissions ---- //

FILE *IRcode;  // Global file pointer

// This function emits binary operations like '+', '-', '*', '/' into IR code
void emitBinaryOperation(char op[1], const char* id1, const char* id2){
    IRcode = fopen("IRcode.ir", "a"); // Append mode
    fprintf(IRcode, "T1 = %s %s %s", id1, op, id2); // Emit operation
    fclose(IRcode); // Close the file after writing
}
 
// This function initializes the IR code file
void initIRcodeFile(){
    IRcode = fopen("IRcode.ir", "w"); // Write mode
    fprintf(IRcode, "\n\n#### IR Code ####\n\n"); // Initial content
    fclose(IRcode); // Close the file after writing
}

// This function emits assignment operations into IR code
void emitAssignment(char * id1, char * id2){
  // This is the temporary approach, until temporary variables management is implemented
  IRcode = fopen("IRcode.ir", "a"); // Append mode
  fprintf(IRcode, "T0 = %s\n", id1);
  fprintf(IRcode, "T1 = %s\n", id2);
  fprintf(IRcode, "T1 = T0\n");
  fclose(IRcode); // Close the file after writing
}

// This function emits IR code for an assignment operation with a specific scope
void emitIR(char id1[50], char id2[50], int curScope[50]){
    IRcode = fopen("IRcode.ir", "a"); // Append mode
    fprintf(IRcode, "T%d = %s\n", curScope, id2); // Emit operation with scope
    fclose(IRcode); // Close the file after writing
}

// This function emits IR code for assignment operation with an integer constant
void emitConstantIntAssignment(char id1[50], int id2[50]){
    IRcode = fopen("IRcode.ir", "a"); // Append mode
    fprintf(IRcode, "T%d = %s\n", id2, id1); // Emit operation
    fclose(IRcode); // Close the file after writing
}

// This function emits IR code for writing an identifier (variable)
void emitWriteId(char * id){
    // Hardcoding "T2" for now. Need a mechanism to manage temporary variables
    IRcode = fopen("IRcode.ir", "a"); // Append mode
    fprintf(IRcode, "output %s\n", "T2");
    fclose(IRcode); // Close the file after writing
}

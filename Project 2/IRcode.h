#include <stdio.h>

// ---- Functions to handle IR code emissions ---- //
FILE * IRcode;



void emitBinaryOperation(char op[1], const char* id1, const char* id2){
    fprintf(IRcode, "T1 = %s %s %s", id1, op, id2);
    fclose(IRcode);
}

void  initIRcodeFile(){
    IRcode = fopen("IRcode.ir", "w");
    fprintf(IRcode, "\n\n#### IR Code ####\n\n");
    fclose(IRcode);
}
void emitAssignment(char * id1, char * id2){
  // This is the temporary approach, until temporary variables management is implemented

  fprintf(IRcode, "T0 = %s\n", id1);
  fprintf(IRcode, "T1 = %s\n", id2);
  fprintf(IRcode, "T1 = T0\n");
  fclose(IRcode);
}

void emitIR(char id1[50], char id2[50],int curScope[50]){
    IRcode = fopen("IRcode.ir", "a");
    fprintf(IRcode, "T%d = %s\n",curScope, id2);
    fclose(IRcode);
}

void emitConstantIntAssignment (char id1[50], int id2[50]){
    IRcode = fopen("IRcode.ir", "a");
    fprintf(IRcode, "T%d = %s\n",id2, id1);
    fclose(IRcode);
}

void emitWriteId(char * id){
    //fprintf (IRcode, "output %s\n", id); // This is the intent... :)

    // This is what needs to be printed, but must manage temporary variables
    // We hardcode T2 for now, but you must implement a mechanism to tell you which one...
    fprintf (IRcode, "output %s\n", "T2");
    fclose(IRcode);
}
    

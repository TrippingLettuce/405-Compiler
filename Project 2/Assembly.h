#include <stdio.h>

// Set of functions to emit MIPS code
FILE * MIPScode;
void  initAssemblyFile(){
    // Creates a MIPS file with a generic header that needs to be in every file

    MIPScode = fopen("MIPScode.asm", "a");
    
    fprintf(MIPScode, ".text\n");
    fprintf(MIPScode, "main:\n");
    fprintf(MIPScode, "# -----------------------\n");

}

void emitMIPSAssignment(char * id1, char * id2){
  // This is the temporary approach, until register management is implemented

  fprintf(MIPScode, "li $t1,%s\n", id1);
  fprintf(MIPScode, "li $t2,%s\n", id2);
  fprintf(MIPScode, "li $t2,$t1\n");
}
int anything = 0;
void emitMIPSConstantIntAssignment (char id1[50], char id2[50],int curScope[50]){
     //                                  x               6
     // This is the temporary approach, until register management is implemented
     // The parameters of this function should inform about registers
     // For now, this is "improvised" to illustrate the idea of what needs to 
     // be emitted in MIPS

     // nextRegister = allocateRegister(id1);  // This is conceptual to inform what needs to be done later
    // while (anything < 10){
    //int curScope1 = atoi(curScope);
    fprintf(MIPScode, "li $t%d,%s\n",curScope, id2);
    //anything++;

    //     if (anything == 2){
    //         break;
    //     }
    //     anything ++;
    // }
            


  

}

void emitMIPSWriteId(char * id, int count){
    // This is what needs to be printed, but must manage registers
    // $a0 is the register through which everything is printed in MIPS
    
    //fprintf(MIPScode, "li $a0,%s\n", id);
    //for (int i = 0; i < count; i++)
        fprintf(MIPScode, "move $a0,$t%d\n", count);
        fprintf(MIPScode, "li $v0,1   # call code for terminate\n");
        fprintf(MIPScode, "syscall      # system call (terminate)\n");
        fprintf(MIPScode, "li $a0, 10\nli $v0, 11\nsyscall\n\n");
}

void emitEndOfAssemblyCode(){
    fprintf(MIPScode, "# -----------------\n");
    fprintf(MIPScode, "#  Done, terminate program.\n\n");
    // fprintf(MIPScode, "li $v0,1   # call code for terminate\n");
    // fprintf(MIPScode, "syscall      # system call (terminate)\n");
    fprintf(MIPScode, "li $v0,10   # call code for terminate\n");
    fprintf(MIPScode, "syscall      # system call (terminate)\n");
    fprintf(MIPScode, ".end main\n");
}
    
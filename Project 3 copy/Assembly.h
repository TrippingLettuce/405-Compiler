#include <stdio.h>
#include <stdlib.h>
int counter = 0;
FILE * MIPScode;
void  initAssemblyFile(){

    MIPScode = fopen("MIPScode.asm", "a");
    fprintf(MIPScode, ".data\n");
    fprintf(MIPScode, "\tCHAR: .byte\n");
    fprintf(MIPScode, "\tfval: .float\n");
    fprintf(MIPScode, ".text\n");
    fprintf(MIPScode, "main:\n");
    fprintf(MIPScode, "# -----------------------\n");
    fclose(MIPScode);
}

void emitMIPSAssignment(char * id1, char * id2){
    MIPScode = fopen("MIPScode.asm", "a");
    fprintf(MIPScode, "li $t1,%s\n", id1);
    fprintf(MIPScode, "li $t2,%s\n", id2);
    fprintf(MIPScode, "li $t2,$t1\n");
    fclose(MIPScode);
}

void emitMIPSConstantIntAssignment (char *Value[50],int curScope[50]){
    MIPScode = fopen("MIPScode.asm", "a");
    fprintf(MIPScode, "li $t%d,%s\n",curScope, Value);
    fclose(MIPScode);
}

void emitMIPSWriteId(int count){
    MIPScode = fopen("MIPScode.asm", "a");
    fprintf(MIPScode, "move $a0,$t%d\n", count);
    fprintf(MIPScode, "li $v0,1   # call code for terminate\n");
    fprintf(MIPScode, "syscall      # system call (terminate)\n");
    fprintf(MIPScode, "li $a0, 10\nli $v0, 11\nsyscall\n\n");
    fclose(MIPScode);
}

void emitEndOfAssemblyCode(){
    MIPScode = fopen("MIPScode.asm", "a");
    fprintf(MIPScode, "# -----------------\n");
    fprintf(MIPScode, "#  Done, terminate program.\n\n");
    fprintf(MIPScode, "li $v0,10   # call code for terminate\n");
    fprintf(MIPScode, "syscall      # system call (terminate)\n");
    fprintf(MIPScode, ".end main\n");
    fclose(MIPScode);
}

void emitfloatAssignment(){
    MIPScode = fopen("MIPScode.asm", "a");
    fprintf(MIPScode, "li $v0, 2\nlwc1 $f12, fval\n");
    fprintf(MIPScode, "syscall\n");
    fprintf(MIPScode, "li $v0, 10\n");
    fprintf(MIPScode, "li $v0, 11\n");
    fprintf(MIPScode, "syscall\n\n");
    fclose(MIPScode);
}

void emitMIPSCharAssignment(){
    MIPScode = fopen("MIPScode.asm", "a");
    fprintf(MIPScode, "li $v0, 4\nla $a0, CHAR\n");
    fprintf(MIPScode, "syscall\n");
    fprintf(MIPScode, "li $a0, 10\nli $v0, 11\n");
    fprintf(MIPScode, "syscall\n\n");
    fclose(MIPScode);
}

void emitMIPSWhileAssignment(char *num[50]){
    MIPScode = fopen("MIPScode.asm", "a");
    fprintf(MIPScode, "li $t5,%s\n", num);
    fprintf(MIPScode, "move $a0,$t5\n");
    fprintf(MIPScode, "li $v0,1\n");
    fprintf(MIPScode, "syscall      # system call (terminate)\n");
    fprintf(MIPScode, "li $a0, 10\nli $v0, 11\nsyscall\n\n");
    fclose(MIPScode);
}
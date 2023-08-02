#include <stdio.h>
FILE * CalcF;
int NumArr[10];
char OpArr[10];
char endArr[10];
int numIndex = 0;
int opIndex = 0;


void  initCalcFile(){
    CalcF = fopen("./Operations/CalcF.txt", "w");
    fclose(CalcF);
}

void clearClacFile(){
    char clearCMD[50], clearCMD2[50];
    strcpy( clearCMD, "rm -f ./Operations/CalcF.txt" );
	system(clearCMD);
	strcpy( clearCMD2, "rm -f ./Operations/Results/CalcF.txt_results.txt" );
	system(clearCMD2);
}

void addCalcFile(){
    int numtemp;
    char optemp;
    int numlast;

    size_t len = strlen(OpArr);
    int numlen = sizeof(NumArr) / sizeof(NumArr[0]);
    CalcF = fopen("./Operations/CalcF.txt", "a");
    for (int i=0; i<len; i++){
        numtemp = NumArr[i];
        optemp = OpArr[i];
        fprintf(CalcF, "%d", numtemp);
        fprintf(CalcF, "%c", optemp);
    }
    numlast = NumArr[len];
    fprintf(CalcF, "%d", numlast);
    fclose(CalcF);
}


void totalVal(){

	FILE * ResultF;
	char ch;

	ResultF = fopen("./Operations/Results/CalcF.txt_results.txt", "r");
	if (NULL == ResultF) {
		printf("File Empty \n");
	}
	do {
		ch = fgetc(ResultF);
		printf("%c", ch);
	} while (ch != EOF);
	fclose(ResultF);
}


void addNumArr(char item[50])
{
    int temp;
    temp = atoi(item);
    NumArr[numIndex] = temp;
    numIndex++;
}
void addIDNumArr(int item){
    NumArr[numIndex] = item;
    numIndex++;
}

void addOpArr(char item[50])
{
    OpArr[opIndex] = item;
    opIndex++;
}

void printOpArr(){
    int oploop;
    for (int i = 0; i< 10 - 1; i++) {  
            printf (" OpArr[%d] = ", i);  
            printf (" %c \n", OpArr[i]);  
        }
}

void printArr(){
        for (int i = 0; i< 10 - 1; i++) {  
            printf (" NumArr[%d] = ", i);  
            printf (" %d \n", NumArr[i]);  
        }
}

void clearArr() {
    int loop;
    for(loop = 0; loop < 10; loop++)
      NumArr[loop] = 0;
      numIndex = 0;
}

void clearOpArr() {
    int loop;
    memset(OpArr, 0, 10);
      opIndex = 0;
}


void reverseNumArr()
{
    int temp;
    int start = 0;
    int end = numIndex - 1;
    while (start < end)
    {
        temp = NumArr[start];  
        NumArr[start] = NumArr[end];
        NumArr[end] = temp;
        start++;
        end--;
    }  
}   



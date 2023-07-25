#include <stdio.h>
FILE * CalcF;
int NumArr[10];
char OpArr[10];
char endArr[10];
int numIndex = 0;
int opIndex = 0;

void  initCalcFile(){
    CalcF = fopen("./Calc/CalcF.txt", "w");
    fclose(CalcF);
}

void clearClacFile(){
    char clearCMD[50], clearCMD2[50];
    strcpy( clearCMD, "rm -f ./Calc/CalcF.txt" );
	system(clearCMD);
	strcpy( clearCMD2, "rm -f ./Calc/Results/CalcF.txt_results.txt" );
	system(clearCMD2);
}

void addCalcFile(){
    int numtemp;
    char optemp;
    int numlast;


    size_t len = strlen(OpArr);
    int numlen = sizeof(NumArr) / sizeof(NumArr[0]);
    CalcF = fopen("./Calc/CalcF.txt", "a");
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


	ResultF = fopen("./Calc/Results/CalcF.txt_results.txt", "r");
	if (NULL == ResultF) {
		printf("file can't be opened \n");
	}
	printf("content of this file are \n");
	do {
		ch = fgetc(ResultF);
		printf("%c", ch);
	} while (ch != EOF);
	fclose(ResultF);
	//return ch;
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



// OLD FILE //


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

void reverseOpArr()
{
    char* temp;
    

    int j = opIndex - 1;
    for (int i = 0; i < j; i++) {
        temp = OpArr[i];
        OpArr[i] = OpArr[j];
        OpArr[j] = temp;
        j--;
    }
}

void removeArr(int pos, int num) {
    for (int i = pos; i < num -1; i++) {  
        NumArr[i] = NumArr[i+1];
       
    }  
}
void removeOpArr(int pos, int num) {
    for (int i = pos; i < num -1; i++) {  
        OpArr[i] = OpArr[i+1];
       
    }  
}

int calc() {
    int total;
    int i;
    int size;
    int test;
    int tempIndex;
    size = 10;
 

        for(int z = 0; z < opIndex; z++) {
            if(OpArr[z] == '*') {
                printf("%d", z);
                printf("\n");
                test = NumArr[z] * NumArr[z + 1];
                NumArr[z] = test;
                removeArr(z + 1, 10);
                removeOpArr(z, 10);
            }
        }
        numIndex--;

        for(int z = 0; z < opIndex; z++) {
            if(OpArr[z] == '+') {
                printf("\n");
                test = NumArr[z] + NumArr[z + 1];
                NumArr[z] = test;
                removeArr(z + 1, 10);
                removeOpArr(z, 10);
            }

        }
        numIndex--;




    

        return NumArr[0];

}


void mergeArrays(){
    char tempArr[50];
    char id1[50], id2[50];
    for (int i = 0; i < 15; i++) {
        
        tempArr[i] = NumArr[i];
        printf("%c", NumArr[i]);
        i++;
    }
    for (int i = 0; i < 15; i++) {
        
        int tempop = 1;
        tempArr[tempop] = OpArr[i];
        printf("%c", tempArr[i]);
        tempop = tempop + 2;
    }
    for (int i = 0; i < 10 - 1; i++) {  
            printf (" temp[%d] = ", i);  
            printf (" %c \n", tempArr[i]);  
        }
}


int sumOfItems()
{
    int sum = 0;
    for (int i = 0; i < 50; i++)
    {
        sum += NumArr[i];
        NumArr[i] = 0;
    }
    return sum;
}
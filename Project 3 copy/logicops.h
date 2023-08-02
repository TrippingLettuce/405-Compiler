#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int runLogic(char left_hand_side[50], char logic_op[50], char right_hand_side[50]){
    printf("%s\n", left_hand_side);
    if (strcmp(logic_op, "<=") == 0){
        printf("1\n");
        int LHS = atoi(left_hand_side);
        int RHS = atoi(right_hand_side);
        if (LHS <= RHS){
            return 1;
        }
        else{
            return 0;
        }
    }
    else if (strcmp(logic_op, ">=") == 0){
        printf("2\n");
        int LHS = atoi(left_hand_side);
        int RHS = atoi(right_hand_side);
        if (LHS >= RHS){
            return 1;
        }
        else{
            return 0;
        }
    }
    else if (strcmp(logic_op, "<") == 0){
        printf("3\n");
        int LHS = atoi(left_hand_side);
        int RHS = atoi(right_hand_side);
        if (LHS < RHS){
            return 1;
        }
        else{
            return 0;
        }
    }
    else if (strcmp(logic_op, ">") == 0){
        printf("4\n");
        int LHS = atoi(left_hand_side);
        int RHS = atoi(right_hand_side);
        if (LHS > RHS){
            return 1;
        }
        else{
            return 0;
        }
    }
    else if (strcmp(logic_op, "==") == 0){
        printf("5\n");
        int LHS = atoi(left_hand_side);
        int RHS = atoi(right_hand_side);
        if (LHS == RHS){
            return 1;
        }
        else{
            return 0;
        }
    }
    else if (strcmp(logic_op, "!=") == 0){
        printf("6\n");
        int LHS = atoi(left_hand_side);
        int RHS = atoi(right_hand_side);
        if (LHS != RHS){
            return 1;
        }
        else{
            return 0;
        }
    }

}

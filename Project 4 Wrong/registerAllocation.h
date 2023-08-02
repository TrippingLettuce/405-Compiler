#include "registerManagement.h"
#include <stdio.h>

static int registers_t[MAX_REGISTERS] = {0};
static int registers_p[MAX_REGISTERS] = {0};
static int registers_r[MAX_REGISTERS] = {0};

int isRegisterInUse(RegisterType reg_type, int r) {
    int* registers;
    if (r >= 0 && r < MAX_REGISTERS) {
        switch (reg_type) {
            case REG_TYPE_T:
                registers = registers_t;
                break;
            case REG_TYPE_P:
                registers = registers_p;
                break;
            case REG_TYPE_R:
                registers = registers_r;
                break;
            default:
                return 0;
        }
        return registers[r];
    }
    return 0;
}

int getNextAvailableRegister(RegisterType reg_type) {
    int* registers;
    switch (reg_type) {
        case REG_TYPE_T:
            registers = registers_t;
            break;
        case REG_TYPE_P:
            registers = registers_p;
            break;
        case REG_TYPE_R:
            registers = registers_r;
            break;
        default:
            return -1;
    }
    for (int i = 0; i < MAX_REGISTERS; ++i) {
        if (!registers[i]) {
            registers[i] = 1;
            return i;
        }
    }
    // Return -1 if no available register is found
    return -1;
}

void printRegistersStatus() {
    printf("Register Status:\n");
    for (int i = 0; i < MAX_REGISTERS; ++i) {
        printf("T%d: %s, P%d: %s, R%d: %s\n", i,
               (registers_t[i] ? "Unavailable" : "Available"),
               i, (registers_p[i] ? "Unavailable" : "Available"),
               i, (registers_r[i] ? "Unavailable" : "Available"));
    }
}

void freeRegister(RegisterType reg_type, int r) {
    int* registers;
    switch (reg_type) {
        case REG_TYPE_T:
            registers = registers_t;
            break;
        case REG_TYPE_P:
            registers = registers_p;
            break;
        case REG_TYPE_R:
            registers = registers_r;
            break;
        default:
            return;
    }
    if (r >= 0 && r < MAX_REGISTERS)
        registers[r] = 0;
}

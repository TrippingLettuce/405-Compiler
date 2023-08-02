#ifndef REGISTER_MANAGEMENT_H
#define REGISTER_MANAGEMENT_H

// Maximum number of registers for each family (T0 - T9, P0 - P9, R0 - R9)
#define MAX_REGISTERS 10

// Register family type
typedef enum {
    REG_TYPE_T,
    REG_TYPE_P,
    REG_TYPE_R
} RegisterType;

// Function to check if a register is in use
int isRegisterInUse(RegisterType reg_type, int r);

// Function to allocate the next available register
int getNextAvailableRegister(RegisterType reg_type);

// Function to print the status of all registers
void printRegistersStatus();

// Function to free a register
void freeRegister(RegisterType reg_type, int r);

#endif // REGISTER_MANAGEMENT_H

.globl main
.data

	Gw: .word 0
	Gx: .word 0
	Gresult: .word 0
	Gcarr0: .asciiz "h"
	Gcarr1: .asciiz "i"
	Gcarr2: .asciiz "m"
	Gcarr3: .asciiz "o"
	Gcarr4: .asciiz "m"
	addValueresult: .word 0
	addValueReturn: .word 0
	TEMP0: .asciiz "result:"

.text
main:
# -----------------------

	la $a0, 20      # store value in $a0
	la $t0, Gx      # load variable address into $t0
	sw $a0, 0($t0)  # move value from $a0 into .word variable
	la $a0, 223      # store value in $a0
	la $t0, Garr1      # load variable address into $t0
	sw $a0, 0($t0)  # move value from $a0 into .word variable
	la $a0, 2332      # store value in $a0
	la $t0, Garr2      # load variable address into $t0
	sw $a0, 0($t0)  # move value from $a0 into .word variable

	jal assignMath       # goto function: assignMath

	jal assignArr       # goto function: assignArr

	lw $t0, Gw       # load the value of w into $t0

	li $v0, 1       # call code to print an integer
	move $a0, $t0   # move the value of w into $a0
	syscall         # system call to print integer

	lw $t0, Gx       # load the value of x into $t0

	li $v0, 1       # call code to print an integer
	move $a0, $t0   # move the value of x into $a0
	syscall         # system call to print integer

	jal whileLoop0       # goto loop: whileLoop0

	next:       # return from loop here

	# -----------------------
	#  done, terminate program.

	li $v0, 10      # call code to terminate program
	syscall         # system call (terminate)
	.end main


# -----------------------
# function declarations

assignMath:

	add $t0, $a1, $a2         # add the two values into $t0
	sw $t0, assignMathw      # store the sum into target variable

	jr $ra       # return to main

assignArray:

	jr $ra       # return to main

addValue:

	add $t0, $a1, $a2         # add the two values into $t0
	sw $t0, addValueresult      # store the sum into target variable

	lw $t0, addValueresult   # load the value of the first variable into $t0
	sw $t0, addValueReturn   # store the value of the first variable into the second

	jr $ra       # return to main

whileLoop0:

	lw $t0, Gx              # load the variable into $t0
	li $t1, 0               # load the number into $t1
	blt $t0, $t1, endloop   # break loop if true 

	lw $a1, Gx         # load x into $a1 as a parameter

	li $a2, -5         # load -5 into $a2 as a parameter

	jal addValue       # goto function: addValue

	lw $t0, addValueReturn     # load the value of the first variable into $t0
	sw $t0, Gresult   # store the value of the first variable into the second

	li $v0, 4       # call code to print an string
	la $a0, TEMP0   # print stored string from above
	syscall

	lw $t0, Gresult       # load the value of result into $t0

	li $v0, 1       # call code to print an integer
	move $a0, $t0   # move the value of result into $a0
	syscall         # system call to print integer

	addi $a0, $0 0xA  # new line
	addi $v0, $0 0xB  # new line
	syscall           # syscall to print new line

	lw $s0, Gx

	li $s1, 5

	sub $t0, $s0, $s1   # subtract the two values into $t0
	sw $t0, Gx          # store the result into target variable

	j whileLoop0       # loop back

endloop:

	jal next       # return to main


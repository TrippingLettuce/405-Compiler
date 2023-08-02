.globl main
.data

	Gw: .word 0
	Gx: .word 0
	Gy: .word 0
	Gcarr0: .asciiz "h"
	Gcarr1: .asciiz "i"
	Gcarr2: .asciiz "m"
	Gcarr3: .asciiz "o"
	Gcarr4: .asciiz "m"
	TEMP0: .asciiz "no change"
	TEMP1: .asciiz "x is positive or less than 10"

.text
main:
# -----------------------

	la $a0, 12      # store value in $a0
	la $t0, Gx      # load variable address into $t0
	sw $a0, 0($t0)  # move value from $a0 into .word variable
	la $a0, 223      # store value in $a0
	la $t0, Garr1      # load variable address into $t0
	sw $a0, 0($t0)  # move value from $a0 into .word variable
	la $a0, 2332      # store value in $a0
	la $t0, Garr2      # load variable address into $t0
	sw $a0, 0($t0)  # move value from $a0 into .word variable

	jal assignMath       # goto function: assignMath

	jal assignArray       # goto function: assignArray

	lw $t0, Gw       # load the value of w into $t0

	li $v0, 1       # call code to print an integer
	move $a0, $t0   # move the value of w into $a0
	syscall         # system call to print integer

	li $v0, 4       # call code to print an string
	la $a0, TEMP0   # print stored string from above
	syscall

	li $v0, 4       # call code to print an string
	la $a0, TEMP1   # print stored string from above
	syscall

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

endloop:

	jal next       # return to main


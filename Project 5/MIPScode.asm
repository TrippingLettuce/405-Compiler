.globl main
.data

	Gw: .word 0
	Gx: .word 0
	Gj: .word 0
	Gi: .word 0
	Gon: .word 0
	Gtime: .word 0
	Gage: .word 0
	Gp: .word 0
	Gcarr0: .asciiz "h"
	Gcarr1: .asciiz "i"
	Gcarr2: .asciiz "m"
	Gcarr3: .asciiz "o"
	Gcarr4: .asciiz "m"
	removeOnei: .word 0
	TEMP0: .asciiz "j is positive and less than 10"
	TEMP1: .asciiz "j is positive or less than 10"
	TEMP2: .asciiz "age is a teenager"
	TEMP3: .asciiz "p is 6"

.text
main:
# -----------------------

	la $a0, 223      # store value in $a0
	la $t0, Garr1      # load variable address into $t0
	sw $a0, 0($t0)  # move value from $a0 into .word variable
	la $a0, 2332      # store value in $a0
	la $t0, Garr2      # load variable address into $t0
	sw $a0, 0($t0)  # move value from $a0 into .word variable
	la $a0, 7      # store value in $a0
	la $t0, Gj      # load variable address into $t0
	sw $a0, 0($t0)  # move value from $a0 into .word variable
	la $a0, 1      # store value in $a0
	la $t0, Gon      # load variable address into $t0
	sw $a0, 0($t0)  # move value from $a0 into .word variable
	la $a0, 4      # store value in $a0
	la $t0, Gtime      # load variable address into $t0
	sw $a0, 0($t0)  # move value from $a0 into .word variable
	la $a0, 100      # store value in $a0
	la $t0, Gi      # load variable address into $t0
	sw $a0, 0($t0)  # move value from $a0 into .word variable
	la $a0, 5      # store value in $a0
	la $t0, Gx      # load variable address into $t0
	sw $a0, 0($t0)  # move value from $a0 into .word variable
	la $a0, 14      # store value in $a0
	la $t0, Gage      # load variable address into $t0
	sw $a0, 0($t0)  # move value from $a0 into .word variable
	la $a0, 8      # store value in $a0
	la $t0, Gp      # load variable address into $t0
	sw $a0, 0($t0)  # move value from $a0 into .word variable

	jal whileLoop0       # goto loop: whileLoop0

	next:       # return from loop here

	li $v0, 4       # call code to print an string
	la $a0, TEMP0   # print stored string from above
	syscall

	li $v0, 4       # call code to print an string
	la $a0, TEMP1   # print stored string from above
	syscall

	li $v0, 4       # call code to print an string
	la $a0, TEMP2   # print stored string from above
	syscall

	jal whileLoop1       # goto loop: whileLoop1

	next:       # return from loop here

	jal assignMath       # goto function: assignMath

	jal assignArr       # goto function: assignArr

	lw $t0, Gw       # load the value of w into $t0

	li $v0, 1       # call code to print an integer
	move $a0, $t0   # move the value of w into $a0
	syscall         # system call to print integer

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

removeOne:
	sub $t0, $t0, 1    # subtract the two values into $t0
	sw $t0, Gi          # store the sum into target variable

	jr $ra       # return to main

whileLoop0:

	lw $s0, Gx

	li $s1, 1

	sub $t0, $s0, $s1   # subtract the two values into $t0
	sw $t0, Gx          # store the result into target variable

	j whileLoop0       # loop back

whileLoop1:

	li $v0, 4       # call code to print an string
	la $a0, TEMP3   # print stored string from above
	syscall

	jal removeOne       # goto function: removeOne

	lw $s2, Gp

	li $s3, 1

	sub $t0, $s0, $s1   # subtract the two values into $t0
	sw $t0, Gx          # store the result into target variable

	j whileLoop1       # loop back

endloop:

	jal next       # return to main


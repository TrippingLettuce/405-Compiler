.globl main
.data

	Gx: .word 0
	TEMP0: .asciiz "Hello World"

.text
main:
# -----------------------

	la $a0, 20      # store value in $a0
	la $t0, Gx      # load variable address into $t0
	sw $a0, 0($t0)  # move value from $a0 into .word variable

	jal whileLoop0       # goto loop: whileLoop0

	next:       # return from loop here

	# -----------------------
	#  done, terminate program.

	li $v0, 10      # call code to terminate program
	syscall         # system call (terminate)
	.end main


# -----------------------
# function declarations

whileLoop0:

	lw $t0, Gx              # load the variable into $t0
	li $t1, 0               # load the number into $t1
	blt $t0, $t1, endloop   # break loop if true 

	li $v0, 4       # call code to print an string
	la $a0, TEMP0   # print stored string from above
	syscall

	j whileLoop0       # loop back

endloop:

	jal next       # return to main


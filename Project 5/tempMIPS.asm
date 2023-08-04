
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

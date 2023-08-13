
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

	li $v0, 4       # call code to print an string
	la $a0, TEMP0   # print stored string from above
	syscall

	li $v0, 4       # call code to print an string
	la $a0, TEMP1   # print stored string from above
	syscall
	la $a0, 125      # store value in $a0
	la $t0, Gw      # load variable address into $t0
	sw $a0, 0($t0)  # move value from $a0 into .word variable

	lw $t0, Gw       # load the value of w into $t0

	li $v0, 1       # call code to print an integer
	move $a0, $t0   # move the value of w into $a0
	syscall         # system call to print integer

	jal whileLoop0       # goto loop: whileLoop0

	next:       # return from loop here

	li $v0, 4       # call code to print an string
	la $a0, TEMP2   # print stored string from above
	syscall

	jal whileLoop1       # goto loop: whileLoop1

	next:       # return from loop here

	jal assignArr       # goto function: assignArr

	# -----------------------
	#  done, terminate program.

	li $v0, 10      # call code to terminate program
	syscall         # system call (terminate)
	.end main


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

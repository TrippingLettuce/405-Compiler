

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


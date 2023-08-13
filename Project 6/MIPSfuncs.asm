

# -----------------------
# function declarations

whileLoop0:

	lw $s0, Gx

	li $s1, 1

	sub $t0, $s0, $s1   # subtract the two values into $t0
	sw $t0, Gx          # store the result into target variable

	j whileLoop0       # loop back

removeOne:

	lw $s2, removeOnei

	li $s3, 1

	sub $t0, $s0, $s1   # subtract the two values into $t0
	sw $t0, Gx          # store the result into target variable

	jr $ra       # return to main

whileLoop1:

	li $v0, 4       # call code to print an string
	la $a0, TEMP3   # print stored string from above
	syscall

	jal removeOne       # goto function: removeOne

	lw $s4, Gp

	li $s5, 1

	sub $t0, $s0, $s1   # subtract the two values into $t0
	sw $t0, Gx          # store the result into target variable

	j whileLoop1       # loop back

assignArray:

	jr $ra       # return to main

endloop:

	jal next       # return to main


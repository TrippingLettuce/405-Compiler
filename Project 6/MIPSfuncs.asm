

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




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


.text
main:
# -----------------------
li $t2,48.0

move $a0,$t2
li $v0,1   # call code for terminate
syscall      # system call (terminate)
li $a0, 10
li $v0, 11
syscall

move $a0,$t2
li $v0,1   # call code for terminate
syscall      # system call (terminate)
li $a0, 10
li $v0, 11
syscall

li $t2,-5

move $a0,$t2
li $v0,1   # call code for terminate
syscall      # system call (terminate)
li $a0, 10
li $v0, 11
syscall

move $a0,$t2
li $v0,1   # call code for terminate
syscall      # system call (terminate)
l.text
main:
# -----------------------
li $t2,48.0

move $a0,$t2
li $v0,1   # call code for terminate
syscall      # system call (terminate)
li $a0, 10
li $v0, 11
syscall

move $a0,$t2
li $v0,1   # call code for terminate
syscall      # system call (terminate)
li $a0, 10
li $v0, 11
syscall

li $t2,-5

move $a0,$t2
li $v0,1   # call code for terminate
syscall      # system call (terminate)
li $a0, 10
li $v0, 11
syscall

move $a0,$t2
li $v0,1   # call code for terminate
syscall      # system call (terminate)
li $a0, 10
li $v0, 11
syscall

# -----------------
#  Done, terminate program.

li $v0,10   # call code for terminate
syscall      # system call (terminate)
.end main

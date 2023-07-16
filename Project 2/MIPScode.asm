.text
main:
# -----------------------
li $t0,8
li $t1,5
li $t2,22
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
.text
main:
# -----------------------
li $t0,8
li $t1,5
li $t2,22
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
.text
main:
# -----------------------
li $t0,14
li $t1,5
li $t2,14
move $a0,$t2
li $v0,1   # call code for terminate
syscall      # system call (terminate)
li $a0, 10
li $v0, 11
syscall

.text
main:
# -----------------------
li $t0,14
li $t1,5
li $t2,28
li $t1,0
# -----------------
#  Done, terminate program.

li $v0,10   # call code for terminate
syscall      # system call (terminate)
.end main
.text
main:
# -----------------------
li $t0,14
li $t1,5
li $t2,28
li $t1,0
# -----------------
#  Done, terminate program.

li $v0,10   # call code for terminate
syscall      # system call (terminate)
.end main

.text
main:
# -----------------------
li $t0,2
li $t0,3
li $t1,z
li $t2,x
li $t2,$t1
.text
main:
# -----------------------
li $t0,2
li $t0,3
move $a0,$t0
# -----------------
#  Done, terminate program.

li $v0,1   # call code for terminate
syscall      # system call (terminate)
li $v0,10   # call code for terminate
syscall      # system call (terminate)
.end main
.text
main:
# -----------------------
li $t0,2
li $t0,3
move $a0,$t0
# -----------------
#  Done, terminate program.

li $v0,1   # call code for terminate
syscall      # system call (terminate)
li $v0,10   # call code for terminate
syscall      # system call (terminate)
.end main
.text
main:
# -----------------------
li $t0,2
li $t0,3
move $a0,$t0
# -----------------
#  Done, terminate program.

li $v0,1   # call code for terminate
syscall      # system call (terminate)
li $v0,10   # call code for terminate
syscall      # system call (terminate)
.end main
.text
main:
# -----------------------
li $t0,2
li $t0,3
move $a0,$t0
# -----------------
#  Done, terminate program.

li $v0,1   # call code for terminate
syscall      # system call (terminate)
li $v0,10   # call code for terminate
syscall      # system call (terminate)
.end main

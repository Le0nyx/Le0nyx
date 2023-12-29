.global main

main:
    li $v0, 5
    syscall
    move $t0, $v0
    li $t1, 0 #is a counter
    li $t2, 0 # remainder gets saved
    # $t0 is limit
    
loop: 
    beq $t1, $t0, end
    add $t1, $t1, 1
    rem $t2, $t1, 2
    beq $t2, 0, printer
    j loop

printer:
    # print $t1 here
    move $a0, $t1
    li $v0, 1
    syscall
    # need to add a space of the numbers or they will be right next to each other
    li $v0, 11        # System call code for printing a character
    li $a0, 32        # Load the ASCII value of the space character into $a0
    syscall
    beq $t0, $t1, end
    j loop
    
end:
    li $v0, 10
    syscall
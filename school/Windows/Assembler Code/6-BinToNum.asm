.global main

# ISSUE: number has to be read from right to left

main:
# $t0 is input
# $t1 is the rest
# $t2 is final num

# Read integer input
    li $v0, 5
    syscall
    move $t0, $v0
    
    # if the first num is 0
    rem $t1, $t0, 2
    beq $t1, 0, first_zero
    j calculation
    
first_zero:
    li $a0, 0
    li $v0, 1
    syscall
    
calculation:
    rem $t1, $t0, 2 #gives the rest as output
    divu $t0, $t0, 2
    #write into bin here
    beq $t1, 0, if_zero
    beq $t1, 1, if_one
       

end:
    move $a0, $t2
    li $v0, 1
    syscall
	
    li $v0, 10
    syscall
    
    
if_zero:
    mul $t2, $t2, 10
    beq $t0, 0, end
    j calculation

if_one:
    mul $t2, $t2, 10
    add $t2, $t2, 1
    beq $t0, 0, end
    j calculation



    
    
    

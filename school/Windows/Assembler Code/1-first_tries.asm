.data
    y: .word 10
    x: .word 5
    v: .word 3

.text
    lw $t0, y
    lw $t1, x
    lw $t2, v
    mul $t1, $t1, $t2
    div $a0, $t0, 10
    add $a0, $t1, $a0

    li $v0, 1
    syscall
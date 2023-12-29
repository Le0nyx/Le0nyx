.macro print_str %str
	.data
	print_str_message: .asciiz %str
	.text
	la	$a0, print_str_message
	li	$v0, 4
	syscall
.end_macro
.macro println_str %str
	print_str %str
	li $a0, '\n'
	li $v0, 11
	syscall
.end_macro

.data
	liste: .word 2, 7, -2, 0, 3, 1, 0, 0, 12, 2, -5, 1, 0
	n_sums: .word 4
.text
	la $t0, liste
	lw $t1, ($t0)
	li $t2, 0
	li $t3, 0
	lw $t4, n_sums # can also load singular numbers as a word although you wont be able to change address
	
	_loop:
		beqz $t1, _ifzero
		add $t2, $t2, $t1
		add $t0, $t0, 4
		lw $t1, ($t0)
		j _loop
	_ende:
		println_str "\nAnzahl der  Nullen: "
		li $v0, 1 #only calls for it to print
		move $a0, $t4 #later on gets $a0 printed so you need to move it there from $t3
		syscall
		
		li $v0, 10 #end programm
		syscall
	_ifzero:
		add $t3, $t3, 1 # ++ to the number how often a 0 was found
		
		println_str "\nNumber: "
		li $v0, 1 #this prints the added numbers until a 0
		move $a0, $t2
		syscall
		
		li $t2, 0 #reset the number to print later on
		add $t0, $t0, 4
		lw $t1, ($t0) #go to next address so it wont read in the 0 again
		beq $t3, $t4 _ende
		j _loop
	
		
		
		
		
		
	
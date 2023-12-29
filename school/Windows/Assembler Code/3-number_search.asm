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
	folge: .word 3, 2, 53 ,2 ,5 ,2 ,5 2, 543, 6356, 674537 ,2346234, 6233, 0 #this is how you make an array	
.text
	la $t0, folge #la means load address and lw means load word
	lw $t1, ($t0) #loads the number of the address on ($t0) into $t1
	li $t2, 0
	println_str "What Number are you looking for:  "
	li $v0, 5 #reads input
	syscall
	_loop:
		beq $t1, $v0, _found
		beq $t0, 0, _notFound
		add $t2, $t2, 1  #counter to where the number is (starts as zero [we studying computer science here after all])
		add $t0, $t0, 4  # add 4 to jump an integer further in the array on the 
		lw $t1, ($t0)  #always need to reload the new value into the storage path
		j _loop
		
	_found:	
	println_str "\n Number found on Index: "
	li $v0, 1 #this prints an integer
	move $a0, $t2
	syscall
	
	_notFound:
	li $v0, 10 #ends programm
	syscall
	println_str "\n Number not found"
	li $v0, 10
	syscall

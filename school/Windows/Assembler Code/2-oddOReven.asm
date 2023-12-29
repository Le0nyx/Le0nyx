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

.global main
main:

println_str "Number? "
li $v0, 5
syscall
rem $v0, $v0, 2

	bne $v0, 0, _else
	println_str "Even"
	rem $v0, $v0, 2
	j _endif
_else:
	println_str "Odd"
_endif:

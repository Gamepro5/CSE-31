.data
please_enter_number: .asciiz "Please enter a number: "
sum_of_odd_numbers: .asciiz "Sum of odd numbers is: "
sum_of_even_numbers: .asciiz "Sum of even numbers is: "
newline: .asciiz "\n"

.text
main: 
	addi $t0 $zero 0 #sum of even numbers
	addi $t1 $zero 0 #sum of odd numbers
	
	addi $t2 $zero 0 #last user input
	addi $t4 $zero 0 #lsat user input (changed from recursion)
input_loop_:
	
	li $v0, 4
	la $a0, please_enter_number
	syscall
	
	li $v0, 5 # $v0 will contain the integer read.
	syscall
	
	add $t2 $zero $v0 # puts the user input into $t2. $t2 is the latest user input.
	add $t4 $zero $v0 # puts the user input into $t4. $t4 is the latest user input. it will be recursivley changed later.
	bne $t2 $zero input_loop
	
	li $v0, 4
	la $a0, newline
	syscall
	
	
	
	li $v0, 4
	la $a0, sum_of_even_numbers
	syscall
	
	li $v0, 1
	add $a0, $zero, $t1 # prints the sum of odd numbers as an int
	syscall
	
	li $v0, 4
	la $a0, newline
	syscall
	
	
	
	
	li $v0, 4
	la $a0, sum_of_odd_numbers
	syscall
	
	li $v0, 1
	add $a0, $zero, $t0 # prints the sum of odd numbers as an int
	syscall
	
	li $v0, 4
	la $a0, newline
	syscall
	
	j end

input_loop: #will subtract or add 2 depending on if $t2 is positive or negative. thanks to simone for the idea of looping subtracting 2 to tell if it's even or odd without using bitwise and.
	bgt $t2, $zero, evenodd_loop_for_positive_numbers_
	blt $t2, $zero, evenodd_loop_for_negative_numbers_
	
evenodd_loop_for_positive_numbers_:
	bgt $t4, $zero, evenodd_loop_for_positive_numbers
	beq $t4, -1, value_is_odd
	beq $t4, $zero, value_is_even
	
evenodd_loop_for_positive_numbers:
	addi $t4, $t4, -2
	j evenodd_loop_for_positive_numbers_

evenodd_loop_for_negative_numbers_:
	blt $t4, $zero, evenodd_loop_for_negative_numbers
	beq $t4, 1, value_is_odd
	beq $t4, $zero, value_is_even
	
evenodd_loop_for_negative_numbers:
	addi $t4, $t4, 2
	j evenodd_loop_for_negative_numbers_
	
value_is_odd:
	add $t1, $t1, $t2 #adds the original input $t2 to the sum of odd numbers $t0.
	j input_loop_
value_is_even:
	add $t0, $t0, $t2 #adds the original input $t2 to the sum of even numbers $t0.
	j input_loop_

end:
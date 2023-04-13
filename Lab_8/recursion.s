.data

# TPS 2 #3 (input prompt to be displayed)
enterNumber: .asciiz "Please enter an integer: "

.text
main: 	addi $sp, $sp, -4	# Moving stack pointer to make room for storing local variables (push the stack frame)
	# TPS 2 #3 (display input prompt)
	li  $v0, 4
   	la $a0, enterNumber
    	syscall
	
	# TPS 2 #4 (read user input)
	li  $v0, 5
    	syscall
    	move $a0, $v0 # puts the read value into $a0 (the recursion function's parameter)
		
	jal recursion	# Call recursion(x)
	
	# TPS 2 #6 (print out returned value)
	move $t6, $v0
	li  $v0, 1
   	add $a0, $t6, $zero
    	syscall
	
	j end		# Jump to end of program


# Implementing recursion
recursion: addi $sp, $sp, -12	# Push stack frame for local storage

	# TPS 2 #7 
	sw $ra, 0($sp)
	
	
	addi $t0, $a0, 1
	bne $t0, $zero, not_minus_one
	
	# TPS 2 #8 (update returned value)
	addi $v0, $zero, 1  #return 1
	
	j end_recur
		
not_minus_one:	bne $a0, $zero, not_zero
	# TPS 2 #9 (update returned value)
	addi $v0, $zero, 3  #return 3
	
	j end_recur		

not_zero: sw $a0, 4($sp) 	
	# TPS 2 #11 (Prepare new input argument, i.e. m - 2)
	addi $a0, $a0, -2
	
	
	jal recursion	# Call recursion(m - 2)
	
	# TPS 2 #12 
	sw $v0, 8($sp)
	lw $a0, 4($sp)
	
	# TPS 2 #13 (Prepare new input argument, i.e. m - 1)
	addi $a0, $a0, -1
	
	jal recursion	# Call recursion(m - 1)
	
	# TPS 2 #14 (update returned value)
	lw $t0, 8($sp) # 8($sp) contains the old value of $v0 from the first recursion call.
	add $v0, $v0, $t0 # add both outputs of both recursion calls and return that.	
	
	j end_recur
		

# End of recursion function	
end_recur: # TPS 2 #15 
	lw $ra, 0($sp)
	
	addi $sp, $sp, 12	# Pop stack frame 
	jr $ra

# Terminating the program
end:	addi $sp, $sp 4	# Moving stack pointer back (pop the stack frame)
	li $v0, 10 
	syscall

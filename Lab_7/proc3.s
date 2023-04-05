					.data
additionOutputPrintTitle:		.asciiz "p + q: "
newLine:				.asciiz "\n"

		.text
MAIN:		addi $s0, $zero, 1 # x = 1
		addi $s1, $zero, 2 # y = 2
		addi $s2, $zero, 3 # z = 3
		
		addi $a0, $s0, 0
		addi $a1, $s1, 0
		addi $a2, $s2, 0
		jal FOO
		
		add $s2, $s2, $v0
		add $s2, $s1, $s2
		add $s2, $s0, $s2
		
		addi $a0, $s2, 0 
		li $v0, 1		# prints z.
		syscall
		
		addi $v0, $zero, 0 # sets the return value of main to zero.
		
		j END  # end the program.
		
		
FOO:		addi $sp, $sp, -4
		sw $ra, 0($sp)
		
		addi $sp, $sp, -4
		sw $a0, 0($sp)
		addi $sp, $sp, -4    #puts $a0, $a1, and $a2 in the stack, in that order.
		sw $a1, 0($sp)
		addi $sp, $sp, -4
		sw $a2, 0($sp)
		
		add $t0, $a0, $a2
		add $t1, $a1, $a2
		add $t2, $a0, $a1
		
		addi $a0, $t0, 0
		addi $a1, $t1, 0
		addi $a2, $t2, 0
		jal BAR
		
		addi $t3, $v0, 0  # $t3 will contain the return result value of our first call of BAR.
		
		#addi $sp, $sp, 4
		lw $a2, 0($sp)
		addi $sp, $sp, 4    #loads $a0, $a1, and $a2 from the stack, in that order.
		lw $a1, 0($sp)
		addi $sp, $sp, 4
		lw $a0, 0($sp)
		
		sub $t0, $a0, $a2
		sub $t1, $a1, $a0
		add $t2, $a1, $a1
		
		
		addi $a0, $t0, 0
		addi $a1, $t1, 0
		addi $a2, $t2, 0
		jal BAR
		
		
		
		add $t0, $t3, $v0 # sets $t0 to the return value of the first BAR call + the return value of the second BAR call.
		
		la $a0, additionOutputPrintTitle
		li $v0, 4
		syscall
		
		addi $a0, $t0, 0
		li $v0, 1		# prints $t0 
		syscall
		
		la $a0, newLine
		li $v0, 4
		syscall
		
		addi $v0, $t0, 0  # sets the return value of the function back to t0, since it had to be changed to 1 for syscall earlier.
		
		addi $sp, $sp, 4  # fetches back the original return adress we set at the start of this fuction. this points back to main.
		lw $ra, 0($sp)
		
		jr $ra # go back to main
		
		

BAR:		sub $t0, $a1, $a0
		sllv $v0, $t0, $a2  # $t0 << $a0  (left shift by a register's bits value)
		jr $ra
		

		
END:

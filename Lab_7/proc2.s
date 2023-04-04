		.data
x:		.word 5
y:		.word 10
m:		.word 15
b:		.word 2

		.text
MAIN:		la $t0, x
		lw $s0, 0($t0)		# s0 = x
		la $t0, y
		lw $s1, 0($t0)		# s1 = y
		
		# Prepare to call sum(x)
		add $a0, $zero, $s0	# Set a0 as input argument for SUM
		jal SUM
		add $t0, $s1, $s0
		add $s1, $t0, $v0
		
		addi $a0, $s1, 0 
		li $v0, 1		 
		syscall	
		j END

		
SUM: 		la $t0, m
		sw $s0, 0($sp) 		#saves the value of s0 into the first slot of the stack frame.
		lw $s0, 0($t0)		# s0 = m
		sw $a0, 4($sp) 		#saves the value of a0 into the second slot of the stack frame. That way we still have the return value of sum and it won't be overritten by SUB.
		
		add $a0, $s0, $a0	# Update a0 as new argument for SUB
		jal SUB
		add $v0, $a0, $v0
		
		lw $s0, 0($sp) #puts original value of s0 back into s0.
		lw $a0, 4($sp) #puts original value of a0 back into a0.
		jr $ra		
		
SUB:		la $t0, b
		addi $sp, $sp -4
		sw $s0, 0($sp)		# Backup s0 from SUM
		lw $s0, 0($t0)		# s0 = b
		sub $v0, $a0, $s0
		lw $s0, 0($sp)		# Restore s0 from SUM
		addi $sp, $sp 4
		jr $ra

		
END:

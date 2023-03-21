.data
n: .word 25
str1: .asciiz "Less than\n"
str2: .asciiz "Less than or equal to\n"
str3: .asciiz "Greater than\n"
str4: .asciiz "Greater than or equal to\n"

.text
#main: 	li $v0, 5 # $v0 will contain the integer read.
#	syscall
#	#la $s1 n
#	addi $a1, $zero, 25
#	blt $v0, $a1, less_than
#	bgt $v0, $a1, greater_than
#	li $v0, 4
#	la $a0, str2
#	syscall
#	li $v0, 4				# THIS CODE WILL PRINT THE RIGHT ANSWER.
#	la $a0, str4
#	syscall
#	j end
#	
#greater_than: 
#	li $v0, 4
#	la $a0, str3
#	syscall
#	j end
#less_than:
#	li $v0, 4
#	la $a0, str1
#	syscall
#	j end


	
		
			
				
main: 	li $v0, 5 # $v0 will contain the integer read.
	syscall
	la $s1 n
	addi $a1, $zero, 25
	#blt $v0, $a1, less_than
	#bge $v0, $a1, greater_than_or_equal_to
	bgt $v0, $a1, greater_than
	ble $v0, $a1, less_than_or_equal_to
	j end

less_than:
	li $v0, 4
	la $a0, str1
	syscall
	j end
	
	
less_than_or_equal_to:
	li $v0, 4
	la $a0, str2
	syscall
	j end


greater_than: 
	li $v0, 4
	la $a0, str3
	syscall
	j end
	
greater_than_or_equal_to:
	li $v0, 4
	la $a0, str4
	syscall
	j end

end:
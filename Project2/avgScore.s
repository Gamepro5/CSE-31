.data 

orig: .space 100	# In terms of bytes (25 elements * 4 bytes each)
sorted: .space 100

str0: .asciiz "Enter the number of assignments (between 1 and 25): "
str1: .asciiz "Enter score: "
str2: .asciiz "Original scores: "
str3: .asciiz "Sorted scores (in descending order): "
str4: .asciiz "Enter the number of (lowest) scores to drop: "
str5: .asciiz "Average (rounded down) with dropped scores removed: "
space: .asciiz " "
newline: .asciiz "\n"


.text 

# This is the main program.
# It first asks user to enter the number of assignments.
# It then asks user to input the scores, one at a time.
# It then calls selSort to perform selection sort.
# It then calls printArray twice to print out contents of the original and sorted scores.
# It then asks user to enter the number of (lowest) scores to drop.
# It then calls calcSum on the sorted array with the adjusted length (to account for dropped scores).
# It then prints out average score with the specified number of (lowest) scores dropped from the calculation.
main: 
	addi $sp, $sp -4
	sw $ra, 0($sp)
	li $v0, 4 
	la $a0, str0 
	syscall 
	li $v0, 5	# Read the number of scores from user
	syscall
	move $s0, $v0	# $s0 = numScores
	move $t0, $0
	la $s1, orig	# $s1 = orig
	la $s2, sorted	# $s2 = sorted
loop_in:
	li $v0, 4 
	la $a0, str1 
	syscall 
	sll $t1, $t0, 2 # sets $t1 to our current iteration of the for loop ($t0) with a bit shift of 2. so if $t0 is 1 $t1 is 4, if $t0 is 2 $t1 is 8, etc.
	add $t1, $t1, $s1 #adds that offset to $s1, which is the adress of the start of the array. $t1 is now the adress of the $t0 th element in the array.
	li $v0, 5	# Read elements from user
	syscall
	sw $v0, 0($t1)
	addi $t0, $t0, 1
	bne $t0, $s0, loop_in
	
	move $a0, $s0
	jal selSort	# Call selSort to perform selection sort in original array
	
	li $v0, 4 
	la $a0, str2 
	syscall
	move $a0, $s1	# More efficient than la $a0, orig
	move $a1, $s0
	jal printArray	# Print original scores
	li $v0, 4 
	la $a0, str3 
	syscall 
	move $a0, $s2	# More efficient than la $a0, sorted
	jal printArray	# Print sorted scores
	
	li $v0, 4 
	la $a0, str4 
	syscall 
	li $v0, 5	# Read the number of (lowest) scores to drop
	syscall
	move $a1, $v0     #a1 = drop
	sub $a1, $s0, $a1	# drop = numScores - drop
	
	move $a0, $s2     # calcsum(sorted, drop)
	jal calcSum	# Call calcSum to RECURSIVELY compute the sum of scores that are not dropped
	
	# Your code here to compute average and print it
	move $t0, $v0 #puts the output of calcsum into $t0, so we can print it.
	li  $v0, 1
    	add $a0, $t0, $zero
    	syscall
	
	
	lw $ra, 0($sp)
	addi $sp, $sp 4
	li $v0, 10 
	syscall
	
	
# printList takes in an array and its size as arguments. 
# It prints all the elements in one line with a newline at the end.
printArray:
	# Your implementation of printList here	
	move $t3, $a0 # cause a0 will get changed for syscall.
	addi $t0, $zero, 0
forcond1:	blt $t0, $a1, for1 # for loop base case. if it isn't met, it will end and proceed below.
	li $v0, 4 
	la $a0, newline 
	syscall
	jr $ra
for1:	
	move $t5, $a0 # we will change a0 for printing, so put the array's pointer into $t5.
	
	sll $t6, $t0, 2 
	add $t6, $t6, $t5 # $t6 is the adress of the $t0 th element in the array $t5
	lw $t1, 0($t6)
	
	li  $v0, 1
    	add $a0, $t1, $zero
    	syscall
    	
    	li $v0, 4 
	la $a0, space 
	syscall
	
	addi $t0, $t0, 1  # i++
	j forcond1
	
	
# selSort takes in the number of scores as argument. 
# It performs SELECTION sort in descending order and populates the sorted array
selSort:
	# Your implementation of selSort here
	
	jr $ra
	
	
# calcSum takes in an array and its size as arguments.
# It RECURSIVELY computes and returns the sum of elements in the array.
# Note: you MUST NOT use iterative approach in this function.
calcSum: # $a0 is the array, and $a1 is the length of the array.
	# Your implementation of calcSum here
	bgt $a1, $zero, calcsumconditional
	addi $a1, $a1, -1
	jal calcSum
	add $v0, $v0, $a1
	jr $ra
calcsumconditional:
	addi $ra, $zero, 0 #return 0
	jr $ra

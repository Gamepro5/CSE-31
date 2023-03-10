main: 	addi     $t0, $s0, 0
	addi	$t1, $t0, -7
	add	$t2, $t1, $t0
	addi	$t3, $t2, 2
	add	$t4, $t3, $t2
	addi	$t5, $t4, -28
	sub	$t6, $t4, $t5
	addi	$t7, $t6, 12
	j finish
	

finish: addi    $a0, $t0, 0
	li      $v0, 1	#You will be asked about what is the purpose of this line for syscall 
	syscall			
	li      $v0, 10		
	syscall			

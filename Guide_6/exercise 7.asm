; 7) Make a subroutine (COUNT_EVEN_NUMBERS) that counts how many even numbers are in an array received by the BX register and its length in CL. Use the functions of rotate or shift functions. Return the value of the counter in CH.

JMP start 

array: 
db 31
db 40


start:
mov c, 2
mov a, array
mov d, [a]
	
.loop: 
 and d, 1 
 JNZ .count 
 inc b

.count:
inc a
mov d, [a]
dec c
cmp c, 0
je .stopLoop
jmp .loop

.stopLoop:
hlt
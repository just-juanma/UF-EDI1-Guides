; 9) Calculate the average of an array (AVERAGE routine) in an array received in the register BX and its length in CL. Return the value of the average in AX.

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

; 5) Make a subroutine (SEARCH_SPACES) that searches for the number of spaces in an alphanumeric array, and loads them into a variable called SPACES. The array ends in $.
; ARRAY DB "This is a test array","$"
; SPACES DB 0

JMP start 

array: 
db "This is a test array", "$"


start:
mov b, 0
mov c, 26
mov a, array ; 
mov d, [a]
	
.loop: 
 cmp d, 32
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

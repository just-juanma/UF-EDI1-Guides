call start 

array: 
db 31
db 40
db 23
db 22
db 54


start:
mov c, 4
mov a, array
mov b, [a]
mov d, 0
	
.loop: 
 and b, 1 
 JNZ .count 
 inc d

.count:
inc a
mov b, [a]
dec c
cmp c, 0
je .stopLoop
call .loop

.stopLoop:
hlt

; 2. b. Recorre el array y guarda en el registro a el ultimo elemento del registro b (0x67)
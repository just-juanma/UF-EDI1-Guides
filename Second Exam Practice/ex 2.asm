; 2. a.
JMP start

array: ; array definition
db 15
db 1
db 54
db 52
db 45
db 8
db 32
db 68
db 35

start:
mov b, 0 ; counter over 16
mov c, 0 ; counter up to 9 (limit)
mov a, array ; array index
mov d, [a] ; save position 0 in register d

.loop:
cmp d,16 
jbe .count ; d < 16
inc b

.count:
inc c ; c++
inc a ; *(a++)
mov d, [a] ; save position in register d
cmp c, 9 ; if..
je .stopLoop ; c == 9, then stop loop
jmp .loop ; reset loop

.stopLoop:
hlt ; stop loop

; 2. b.
; What it does is to go through the array, with the difference that instead of going from 0 to 3, it goes from 3 to 0 (but it is the same thing).
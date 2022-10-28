; Make a subroutine (SEARCH_MAX) to find the maximum value from an 
; array containing 10 integers. The definition of the variables will 
; be as follows:
; ARRAY DB -4, 3, 5, 5, 12, -5, 8, 8, 8, 6, 0, 1
; MAXIMUM DB 0 2.

jmp start ; go to start

array: ; array definition
db 15
db 110
db 54
db 52
db 45
db 89
db 32
db 68
db 35

start:
mov c, 0 ; c = 0 
mov a, array ; temp = array
mov d, [a] ; d = array[0]

.loop:
inc a ; *(a++)
mov b, [a] ; b = a[+1]
cmp b,d ; if..
jb .count ; b < d
mov d, b ; then d = b

.count:
inc c ; c++
cmp c, 9 ; if..
je .stopLoop ; c == 9, then stop loop
jmp .loop ; reset loop

.stopLoop:
hlt ; stop loop
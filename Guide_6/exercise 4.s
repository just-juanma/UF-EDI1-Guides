; Implement a routine that loads into an array the codes of a counter ring of
; module 8 using the shift instructions:
; 00000001-00000001-00000010-000001000...up to 10000000.

JMP start ; jump to start

start:

MOV A, 1 ; inicialize A by 1
	
.loop: // inicialize loop

	SHL A, 0x1 ; shift right 1 in the register 
	CMP A, 0x80 ; if it reaches 0b1000 0000 
  JNZ .loop ; then stops

; Ejercicio 4

JMP start ; jump to start

start:

MOV A, 1 ; inicialize A by 1
	
.loop: // inicialize loop

	SHL A, 0x1 ; shift right 1 in the register 
	CMP A, 0x80 ; if it reaches 0b1000 0000 
  JNZ .loop ; then stops
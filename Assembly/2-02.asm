DATA SEGMENT
	X DB -78,127,-128,-125,88
	Y DB 32,-43,76,95,1
	S DB 5 DUP(?)
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE,DS:DATA
	START: MOV AX,DATA
		   MOV DS,AX
		   MOV CX,5
		   MOV BX,0
	LOOP1: MOV AL,X[BX]
		   MOV DL,Y[BX]
		   ADD AL,DL
		   MOV S[BX],AL
		   INC BX
	LOOP LOOP1
	ELOOP: JMP ELOOP
CODE ENDS
	END START
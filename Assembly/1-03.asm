DATA SEGMENT
	X DB 10H;数据段X单元存放10H，占一个字节
	Y DB 00H;数据段Y单元存放00H，占一个字节，分配存储空间方式之一
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE,DS:DATA
	START: MOV AX,DATA
	       MOV DS,AX
		   MOV CL,04H;CL存放移位次数04H，即4次
		   MOV AL,X;将数据段X单元值复制到AL中
		   ROL AL,CL;左移4次
		   MOV Y,AL;将移位后的AL值复制到数据段单元Y，查看数据段值
	ELOOP: JMP ELOOP
CODE ENDS
	END START

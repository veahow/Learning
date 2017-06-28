DATA SEGMENT
	X DB 42;数据段X单元存放42，占一个字节
	Y DB -43;数据段Y单元存放-43，占一个字节
	S DB 0;数据段S单元存放0，占一个字节，分配存储空间方式之一
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE,DS:DATA;CODE自动分配进CS，DS、SS、ES需通过AX分配
	START: MOV AX,DATA
	       MOV DS,AX
		   MOV AL,X;将数据段单元X的值复制进AL中
		   ADD AL,Y;将AL的值与数据段单元Y的值相加，结果存放在AL
		   MOV S,AL;将AL的值复制进数据段单元S中，查看数据段
	ELOOP: JMP ELOOP;
CODE ENDS
	END START

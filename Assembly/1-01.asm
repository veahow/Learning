CODE SEGMENT
ASSUME CS:CODE
	START: MOV AX,1234H;AX���1234H
	       MOV BX,4321H;BX���4321H
		   ADD AX,BX;1234H��4321H��ӣ���������AX
		   MOV CX,AX;��AX��ֵ���Ƶ�CX�У�AX��CXֵ��ͬ
		   PUSH CX;��CX��ֵѹ���ջ
		   POP DX;��֮ǰѹ���ջ��CXֵ������DX��
	ELOOP: JMP ELOOP;��ѭ������֤������ֹ
CODE ENDS
	END START

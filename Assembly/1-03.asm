DATA SEGMENT
	X DB 10H;���ݶ�X��Ԫ���10H��ռһ���ֽ�
	Y DB 00H;���ݶ�Y��Ԫ���00H��ռһ���ֽڣ�����洢�ռ䷽ʽ֮һ
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE,DS:DATA
	START: MOV AX,DATA
		 MOV DS,AX
		 MOV CL,04H;CL�����λ����04H����4��
		 MOV AL,X;�����ݶ�X��Ԫֵ���Ƶ�AL��
		 ROL AL,CL;����4��
		 MOV Y,AL;����λ���ALֵ���Ƶ����ݶε�ԪY���鿴���ݶ�ֵ
	ELOOP: JMP ELOOP
CODE ENDS
	END START

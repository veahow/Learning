DATA SEGMENT
	X DB 42;���ݶ�X��Ԫ���42��ռһ���ֽ�
	Y DB -43;���ݶ�Y��Ԫ���-43��ռһ���ֽ�
	S DB 0;���ݶ�S��Ԫ���0��ռһ���ֽڣ�����洢�ռ䷽ʽ֮һ
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE,DS:DATA;CODE�Զ������CS��DS��SS��ES��ͨ��AX����
	START: MOV AX,DATA
	       MOV DS,AX
		   MOV AL,X;�����ݶε�ԪX��ֵ���ƽ�AL��
		   ADD AL,Y;��AL��ֵ�����ݶε�ԪY��ֵ��ӣ���������AL
		   MOV S,AL;��AL��ֵ���ƽ����ݶε�ԪS�У��鿴���ݶ�
	ELOOP: JMP ELOOP;
CODE ENDS
	END START

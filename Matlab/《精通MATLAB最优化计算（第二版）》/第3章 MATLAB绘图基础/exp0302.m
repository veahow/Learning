clc;
clear all;

x = 0:0.4*pi:2*pi;    % ����x�����᷶Χ���̶�

y1 = sin(x);    % ����y1��x������ϵ
y2 = cos(x);    % ����y2��x������ϵ
y3 = sin(x-0.1*pi);    % ����y3��x������ϵ
y4 = cos(x+0.1*pi);    % ����y4��x������ϵ

plot(y1)    % ����y1��x������ͼ��
figure;
plot(x, y1, x, y2, x, y3, x, y4)    % �������ݻ�ͼ
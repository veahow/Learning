clc;
clear all;

% ֱ�������Ԫ��������
A1 = [sqrt(2)*exp((pi/4)*i) 1+2i 1+3i; sqrt(2)*exp((-pi/4)*i) 1-2i 1-3i]

% ��ʵ������
A2re = [1 1 1; 1 1 1];
A2im = [1 2 3; -1 -2 -3];
A2 = A2re+A2im*i
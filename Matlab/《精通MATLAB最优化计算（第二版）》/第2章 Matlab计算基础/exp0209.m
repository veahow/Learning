clc;
clear all;

% ֱ�������ʾ
t = 0:0.01:2*pi;
y = t+i*t.*sin(t);

% �������ʾ
r = abs(y);
delta = angle(y);

subplot(2, 1, 1)
plot(y)    % ����ֱ������ͼ
title('ֱ������ͼ');

subplot(2, 1, 2)
polar(delta, r)    % ���Ƽ�����ͼ
title('������ͼ')
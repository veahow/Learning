clc;
clear all;

x = -8:0.5:8;    % ����x�����᷶Χ���̶�

y = x;    % ����y��x֮��ĺ�����ϵ
[X, Y] = meshgrid(x, y);    % ͨ��meshgrid���þ�������
R = sqrt(X.^2+Y.^2)+eps;    % ������ϵ
Z = sin(R)./R;    % ������ϵ
mesh(X, Y, Z)    % ������������
grid on    % ��������

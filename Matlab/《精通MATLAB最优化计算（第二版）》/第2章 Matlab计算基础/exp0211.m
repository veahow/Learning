clc;
clear all;

syms x a n    % ������ű���a��x

y1 = 1/(x*(log(x)^2))-1/(x-1)^2;
f1 = limit(y1, x, 1, 'right')    % ����
y2 = a*n^3+(a-1)*n^2;
f2 = symsum(y2, n, 0, 50)    % �������
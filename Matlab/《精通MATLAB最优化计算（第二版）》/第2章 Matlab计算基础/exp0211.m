clc;
clear all;

syms x a n    % 定义符号变量a和x

y1 = 1/(x*(log(x)^2))-1/(x-1)^2;
f1 = limit(y1, x, 1, 'right')    % 求极限
y2 = a*n^3+(a-1)*n^2;
f2 = symsum(y2, n, 0, 50)    % 级数求和
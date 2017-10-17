clc;
clear all;

t = 0:pi/50:8*pi;    % 产生数据t

% 定义x、y、z与t之间的函数关系
x = sin(t);
y = cos(t);
z = t;

plot3(x, y, z);    % 绘制x、y、z三维图形
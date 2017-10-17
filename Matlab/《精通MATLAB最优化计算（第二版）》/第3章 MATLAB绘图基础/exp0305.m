clc;
clear all;

x = -8:0.5:8;    % 定义x坐标轴范围及参数

y = x;    % 定义y与x之间的函数关系
[X, Y] = meshgrid(x, y);    % 设置矩形网格
R = sqrt(X.^2+Y.^2)+eps;    % 设置函数关系
Z = 2*sin(R)./R;    % 设置函数关系
surf(X, Y, Z)    % 绘制阴影曲面图
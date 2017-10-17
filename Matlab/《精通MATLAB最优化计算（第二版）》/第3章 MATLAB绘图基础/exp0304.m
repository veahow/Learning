clc;
clear all;

x = -8:0.5:8;    % 定义x坐标轴范围及刻度

y = x;    % 设置y与x之间的函数关系
[X, Y] = meshgrid(x, y);    % 通过meshgrid设置矩形网格
R = sqrt(X.^2+Y.^2)+eps;    % 函数关系
Z = sin(R)./R;    % 函数关系
mesh(X, Y, Z)    % 绘制网格曲面
grid on    % 绘制网格

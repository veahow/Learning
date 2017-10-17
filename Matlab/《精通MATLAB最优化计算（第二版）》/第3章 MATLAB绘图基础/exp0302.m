clc;
clear all;

x = 0:0.4*pi:2*pi;    % 定义x坐标轴范围及刻度

y1 = sin(x);    % 定义y1与x函数关系
y2 = cos(x);    % 定义y2与x函数关系
y3 = sin(x-0.1*pi);    % 定义y3与x函数关系
y4 = cos(x+0.1*pi);    % 定义y4与x函数关系

plot(y1)    % 绘制y1与x函数的图形
figure;
plot(x, y1, x, y2, x, y3, x, y4)    % 多组数据绘图
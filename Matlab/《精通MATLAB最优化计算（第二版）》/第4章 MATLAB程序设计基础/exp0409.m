% 函数句柄创建和调用实例
clc;
clear all;

fhd = @sin
x = 0:0.25*pi:2*pi;
fhd(x)
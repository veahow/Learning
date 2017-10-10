clc;
clear all;

% 直接输入各元素来构造
A1 = [sqrt(2)*exp((pi/4)*i) 1+2i 1+3i; sqrt(2)*exp((-pi/4)*i) 1-2i 1-3i]

% 由实矩阵构造
A2re = [1 1 1; 1 1 1];
A2im = [1 2 3; -1 -2 -3];
A2 = A2re+A2im*i
clc;
clear all;

x1 = -1+i    % 直接法构造，实部虚部形式

x2 = sqrt(2)*exp(i*(3*pi/4))    % 直接法构造，复指数形式

% 符号函数法构造，实部虚部形式
syms a b real;    % 声明a，b为实数型
x3 = a+b*i;    % 实部虚部形式复数的符号表达
x3 = subs(x3, {a, b}, {-1, 1}) % 代入具体值

% 符号函数法构造，复指数形式
syms r ct real;    % 声明r，ct为实数型
x4 = r*exp(ct*i);    % 复指数形式复数的符号表达
x4 = subs(x4, {r, ct}, {sqrt(2), 3*pi/4})    % 代入具体值
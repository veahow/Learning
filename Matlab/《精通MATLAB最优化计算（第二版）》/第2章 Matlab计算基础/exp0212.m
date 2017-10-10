clc;
clear all;

syms a x    % 定义符号变量a、x
f = sin(a*x);    % 创建函数f
dfx = diff(f, x)    % 对x求导
dfa = diff(f, a)    % 对a求导
f1 = x*log(1+x);    % 创建函数f1
int1 = int(f1, x)    % 对x积分
int2 = int(f1, x, 0, 1)    % 求[0,1]区间上的积分

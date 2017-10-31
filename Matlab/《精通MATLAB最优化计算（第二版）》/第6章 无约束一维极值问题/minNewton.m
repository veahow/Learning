function [x, minf] = minNewton(f, x0, eps)
% 目标函数:f
% 初始点:x0
% 精度:eps
% 目标函数取最小值时的自变量值:x
% 目标函数的最小值:minf

format long;
if nargin == 2
    eps = 1.0e-6;
end

df = diff(f);    % 一阶导数
d2f = diff(df);    % 二阶导数
k = 0;
tol = 1;

while tol>eps
    dfx = subs(df, findsym(df), x0);    % 一阶导数值
    d2fx = subs(d2f, findsym(d2f), x0);    % 二阶导数值
    x1 = x0 - dfx/d2fx;    % 迭代公式
    k = k + 1;
    tol = abs(dfx);
    x0 = x1;
end

x = x1;
minf = subs(f, findsym(f), x);
format short;
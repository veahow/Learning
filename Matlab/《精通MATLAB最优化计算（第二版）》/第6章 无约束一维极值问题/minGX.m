function [x, minf] = minGX(f, x0, x1, eps)
% 目标函数:f
% 初始点:x0
% 初始点:x1
% 精度:eps
% 目标函数取最小值时的自变量值:x
% 目标函数的最小值:minf

format long;
if nargin == 3
    eps = 1.0e-6;
end

df = diff(f);    % 一阶导数
k = 0;
tol = 1;
while tol>eps
    dfx1 = subs(df, findsym(df), x1);    % 一阶导数值
    dfx0 = subs(df, findsym(df), x0);    % 一阶导数值
    x2 = x1 - (x1 - x0)*dfx1/(dfx1 - dfx0);    % 割线法的迭代公式
    k = k + 1;
    tol = abs(dfx1);
    x0 = x1;    % 更新迭代点
    x1 = x2;    % 更新迭代点
end
x = x2;
minf = subs(f, findsym(f), x);
format short;
function [x, minf] = minPWX(f, a, b, eps)
% 目标函数:f
% 初始搜索区间左端点:a
% 初始搜索区间右端点:b
% 精度:eps
% 目标函数取最小值时的自变量值:x
% 目标函数的最小值:minf

format long;
if nargin == 3
    eps = 1.0e-6;
end

t0 = (a+b)/2;
k = 0;
tol = 1;

while tol>eps
    fa = subs(f, findsym(f), a);    % 区间左端点函数值
    fb = subs(f, findsym(f), b);    % 区间右端点函数值
    ft0 = subs(f, findsym(f), t0);    % 内插点函数值
    tu = fa*(b^2 - t0^2)+fb*(t0^2 - a^2)+ft0*(a^2 - b^2);
    td = fa*(b - t0)+fb*(t0 - a)+ft0*(a-b);
    t1 = tu/2/td;    % 插值多项式的极小点
    
    ft1 = subs(f, findsym(f), t1);    % 插值多项式的极小值
    tol = abs(t1 - t0);
    if ft1 <= ft0
        if t1<=t0
            b = t0;
            t0 = t1;
        else
            a = t0;
            t0 = t1;
        end
        k = k+1;
    else
        if t1<=t0
            a = t1;
        else
            b = t1;
        end
        k = k+1;
    end
end

x = t1;
minf = subs(f, findsym(f), x);
format short;
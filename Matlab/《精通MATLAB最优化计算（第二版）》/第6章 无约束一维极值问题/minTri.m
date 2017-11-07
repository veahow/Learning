function [x, minf] = minTri(f, a, b, eps)
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

df = diff(f);
df2 = diff(f, 2);
t0 = (a+b)/2;
k = 0;
tol = 1;

while tol>eps
    fa = subs(f, findsym(f), a);    % 区间左端点函数值
    fb = subs(f, findsym(f), b);    % 区间右端点函数值
    dfa = subs(df, findsym(df), a);    % 区间左端点函数导数值
    dfb = subs(df, findsym(df), b);    % 区间右端点函数导数值
    
    w = 3*(fb - fa)/(b-a) - dfa - dfb;
    z = sqrt(w^2 - dfa*dfb);
    t1 = a + (z - dfa - w)*(b-a)/(2*z - dfa + dfb);    % 插值多项式的极小点
    
    dft1 = subs(df, findsym(df2), t1);    % 插值多项式在极小点处的二阶导数
    tol = abs(dft1);
    if dft1 < 0    % 二阶导数小于0，更新区间左端点
        a = t1;
    else    % 二阶导数大于0，更新区间右端点
        b = t1;
    end
    k = k+1;
    t0 = t1;
end

x = t1;
minf = subs(f, findsym(f), x);
format short;
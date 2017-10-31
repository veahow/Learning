function [x, minf] = minNewton(f, x0, eps)
% Ŀ�꺯��:f
% ��ʼ��:x0
% ����:eps
% Ŀ�꺯��ȡ��Сֵʱ���Ա���ֵ:x
% Ŀ�꺯������Сֵ:minf

format long;
if nargin == 2
    eps = 1.0e-6;
end

df = diff(f);    % һ�׵���
d2f = diff(df);    % ���׵���
k = 0;
tol = 1;

while tol>eps
    dfx = subs(df, findsym(df), x0);    % һ�׵���ֵ
    d2fx = subs(d2f, findsym(d2f), x0);    % ���׵���ֵ
    x1 = x0 - dfx/d2fx;    % ������ʽ
    k = k + 1;
    tol = abs(dfx);
    x0 = x1;
end

x = x1;
minf = subs(f, findsym(f), x);
format short;
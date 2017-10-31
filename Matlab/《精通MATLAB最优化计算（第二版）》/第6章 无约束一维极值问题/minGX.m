function [x, minf] = minGX(f, x0, x1, eps)
% Ŀ�꺯��:f
% ��ʼ��:x0
% ��ʼ��:x1
% ����:eps
% Ŀ�꺯��ȡ��Сֵʱ���Ա���ֵ:x
% Ŀ�꺯������Сֵ:minf

format long;
if nargin == 3
    eps = 1.0e-6;
end

df = diff(f);    % һ�׵���
k = 0;
tol = 1;
while tol>eps
    dfx1 = subs(df, findsym(df), x1);    % һ�׵���ֵ
    dfx0 = subs(df, findsym(df), x0);    % һ�׵���ֵ
    x2 = x1 - (x1 - x0)*dfx1/(dfx1 - dfx0);    % ���߷��ĵ�����ʽ
    k = k + 1;
    tol = abs(dfx1);
    x0 = x1;    % ���µ�����
    x1 = x2;    % ���µ�����
end
x = x2;
minf = subs(f, findsym(f), x);
format short;
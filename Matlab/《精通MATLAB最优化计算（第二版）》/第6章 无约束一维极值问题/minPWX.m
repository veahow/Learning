function [x, minf] = minPWX(f, a, b, eps)
% Ŀ�꺯��:f
% ��ʼ����������˵�:a
% ��ʼ���������Ҷ˵�:b
% ����:eps
% Ŀ�꺯��ȡ��Сֵʱ���Ա���ֵ:x
% Ŀ�꺯������Сֵ:minf

format long;
if nargin == 3
    eps = 1.0e-6;
end

t0 = (a+b)/2;
k = 0;
tol = 1;

while tol>eps
    fa = subs(f, findsym(f), a);    % ������˵㺯��ֵ
    fb = subs(f, findsym(f), b);    % �����Ҷ˵㺯��ֵ
    ft0 = subs(f, findsym(f), t0);    % �ڲ�㺯��ֵ
    tu = fa*(b^2 - t0^2)+fb*(t0^2 - a^2)+ft0*(a^2 - b^2);
    td = fa*(b - t0)+fb*(t0 - a)+ft0*(a-b);
    t1 = tu/2/td;    % ��ֵ����ʽ�ļ�С��
    
    ft1 = subs(f, findsym(f), t1);    % ��ֵ����ʽ�ļ�Сֵ
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
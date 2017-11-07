function [x, minf] = minTri(f, a, b, eps)
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

df = diff(f);
df2 = diff(f, 2);
t0 = (a+b)/2;
k = 0;
tol = 1;

while tol>eps
    fa = subs(f, findsym(f), a);    % ������˵㺯��ֵ
    fb = subs(f, findsym(f), b);    % �����Ҷ˵㺯��ֵ
    dfa = subs(df, findsym(df), a);    % ������˵㺯������ֵ
    dfb = subs(df, findsym(df), b);    % �����Ҷ˵㺯������ֵ
    
    w = 3*(fb - fa)/(b-a) - dfa - dfb;
    z = sqrt(w^2 - dfa*dfb);
    t1 = a + (z - dfa - w)*(b-a)/(2*z - dfa + dfb);    % ��ֵ����ʽ�ļ�С��
    
    dft1 = subs(df, findsym(df2), t1);    % ��ֵ����ʽ�ڼ�С�㴦�Ķ��׵���
    tol = abs(dft1);
    if dft1 < 0    % ���׵���С��0������������˵�
        a = t1;
    else    % ���׵�������0�����������Ҷ˵�
        b = t1;
    end
    k = k+1;
    t0 = t1;
end

x = t1;
minf = subs(f, findsym(f), x);
format short;
function [x, minf] = minFBNQ(f, a, b, delta, eps)
% Ŀ�꺯����f
% ��ֵ������˵㣺a
% ��ֵ�����Ҷ˵㣺b
% �㷨����������delta
% ���ȣ�eps
% Ŀ�꺯��ȡ��Сֵʱ���Ա���ֵ��x
% Ŀ�꺯������Сֵ��minf

format long;
if nargin == 4
    eps = 1.0e-6;
end

F = ones(2, 1);
N = (b-a)/eps;
c = F(2)-N;
n = 2;

while c<0    % ���n
    n = n + 1;
    F(n) = F(n-1) + F(n-2);
    c = F(n) - N;
end

l = a + F(n-2)*(b-a)/F(n);    % ��̽��
u = a + F(n-1)*(b-a)/F(n);    % ��̽��
k = 1;

while 1
    f1 = subs(f, findsym(f), l);    % ��̽�㺯��ֵ
    fu = subs(f, findsym(f), u);    % ��̽�㺯��ֵ
    if f1>fu
        a = l;    % �ı�������˵�
        l = u;
        u = a + F(n-k-1)*(b-a)/F(n-k);    % ������������
        if(k == n-3)
            break;
        else
            k = k + 1;
        end
    else
        b = u;
        u = l;
        l = a + F(n-k-2)*(b-a)/F(n-k);    % ������������
        if(k == n-3)
            break;
        else
            k = k + 1;
        end
    end
end

if k == 100000
    disp('�Ҳ�����Сֵ��');
    x = NaN;
    minf = NaN;
    return ;
end
u = l + delta;
fl = subs(f, findsym(f), l);
fu = subs(f, findsym(f), u);
if fl > fu
    a = l;
else
    b = l;
end
x = (a+b)/2;
minf = subs(f, findsym(f), x);
format short;
function exp0412()
clc;
clear all;
r = 80;
M = 160;
p = exp(-r);
S1 = 0;
for k = 1:M
    p = p*r/k;    % Ƕ��ʽ���ؾ����㷨��
    S1 = S1+p;
end
S1
S2 = 0;
for k = 1:M
    p = r^k/factorial(k);    % ��Ƕ��ʽ
    S2 = S2+p;
end
S2*exp(-r);
S2
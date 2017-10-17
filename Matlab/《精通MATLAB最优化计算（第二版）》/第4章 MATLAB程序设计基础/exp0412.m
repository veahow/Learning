function exp0412()
clc;
clear all;
r = 80;
M = 160;
p = exp(-r);
S1 = 0;
for k = 1:M
    p = p*r/k;    % 嵌套式（秦九韶算法）
    S1 = S1+p;
end
S1
S2 = 0;
for k = 1:M
    p = r^k/factorial(k);    % 非嵌套式
    S2 = S2+p;
end
S2*exp(-r);
S2
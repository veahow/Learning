function exp0411()
clc;
clear all;
N = 100000;
a = [1:N];
x = 1;
tic
p1 = sum(a.*x.^[N-1:-1:0]);
p1
toc

tic
p2 = a(1);
for i = 2:N
    p2 = p2*x + a(i);
end
p2
toc

tic
p3 = polyval(a, x)
toc
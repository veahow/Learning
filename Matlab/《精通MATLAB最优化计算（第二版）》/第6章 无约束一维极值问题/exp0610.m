clc;
clear all;

syms t;
f = t^2-2*t+7;
x1 = minWP(f, 8, 0.1, 0.65, 2)
x2 = minWP(f, 9, 0.1, 0.65, 2)
x3 = minWP(f, 10, 0.1, 0.65, 2)
clc;
clear all;

syms t;
f = t^2-2*t+7;
[x, mf] = minGS(f, 8, 0.4, 0.75, 2)
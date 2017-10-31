clc;
clear all;

syms t;
f = t^3 - 3*t + 2;
x = minGlbNewton(f, 5)
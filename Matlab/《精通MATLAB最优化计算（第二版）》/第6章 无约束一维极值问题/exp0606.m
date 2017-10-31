clc;
clear all;

syms t;
f = t^3 - 3*t + 2;
x = minGX(f, 5, 8)
xv = minGX(f, -2, 0)
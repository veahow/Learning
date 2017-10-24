clc;
clear all;

syms t;
f = t^4-t^2-2*t+5;
[x, fx] = minHJ(f, -10, 10)
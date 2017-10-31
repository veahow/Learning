clc;
clear all;

syms t;
f = t^2 - log(t) - 5;
x = minPWX(f, 0.5, 4)
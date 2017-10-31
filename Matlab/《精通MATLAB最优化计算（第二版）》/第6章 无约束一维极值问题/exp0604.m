clc;
clear all;

syms t;
f = t^2 - log(t) - 5;
x = minNewton(f, 2)
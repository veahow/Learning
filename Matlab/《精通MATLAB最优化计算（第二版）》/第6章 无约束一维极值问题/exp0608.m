clc;
clear all;

syms t;
f = t^4 - t^2 + t - 1;
[x1, x2] = minJT(f, 0, 0.1)
[x, mf] = minTri(f, x1, x2)
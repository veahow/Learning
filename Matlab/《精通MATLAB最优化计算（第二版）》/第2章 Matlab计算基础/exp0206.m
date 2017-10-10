clc;
clear all;

A = [6 2 1; 2 3 1; 1 1 1];
[L, U, P] = lu(A)    % 对矩阵进行LU分解
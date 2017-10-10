clc;
clear all;

A = [1 3 5; 2 4 6; 7 9 13];
[b, c] = eig(A)    % 求取矩阵的特征值和特征向量
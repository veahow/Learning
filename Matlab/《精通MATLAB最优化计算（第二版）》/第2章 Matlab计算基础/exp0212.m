clc;
clear all;

syms a x    % ������ű���a��x
f = sin(a*x);    % ��������f
dfx = diff(f, x)    % ��x��
dfa = diff(f, a)    % ��a��
f1 = x*log(1+x);    % ��������f1
int1 = int(f1, x)    % ��x����
int2 = int(f1, x, 0, 1)    % ��[0,1]�����ϵĻ���

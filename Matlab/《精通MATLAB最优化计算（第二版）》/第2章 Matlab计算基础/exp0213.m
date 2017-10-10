clc;
clear all;

f1 = dsolve('Dy+3*x*y=x*exp(-x^2)', 'x')
f2 = dsolve('x*Dy+2*y-exp(x)=0', 'y(1)=2*exp(1)', 'x')
f3 = dsolve('D2y+2*Dy+exp(x)=0', 'x')


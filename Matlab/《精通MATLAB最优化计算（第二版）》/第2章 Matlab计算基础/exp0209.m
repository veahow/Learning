clc;
clear all;

% 直角坐标表示
t = 0:0.01:2*pi;
y = t+i*t.*sin(t);

% 极坐标表示
r = abs(y);
delta = angle(y);

subplot(2, 1, 1)
plot(y)    % 绘制直角坐标图
title('直角坐标图');

subplot(2, 1, 2)
polar(delta, r)    % 绘制极坐标图
title('极坐标图')
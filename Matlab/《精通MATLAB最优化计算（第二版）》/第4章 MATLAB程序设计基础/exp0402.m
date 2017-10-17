clc;
clear all;

n = -2;
if n < 0
    disp('negative number!');
    return;    % 不去掉return与去掉return的时候分别运行一次查看结果
end
disp('condon after return')
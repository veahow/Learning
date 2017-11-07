function [x, minf] = minWP(f, XMAX, sigma1, sigma2, alpha, eps)
% 目标函数:f
% 搜索最大值:XMAX
% 可接受系数1:sigma1
% 可接受系数2:sigma2
% 增大探索点系数:alpha
% 精度:eps
% 目标函数取最小值时的自变量值:x
% 目标函数的最小值:minf

format long;
if nargin == 5
    eps = 1.0e-6;
end

if sigma1<=0 || sigma1>1    % 输入参数检测
    disp('sigma1参数不对！');
    x = NaN;
    minf = NaN;
    return;
else
    if sigma2 <= sigma1
        disp('sigma2参数不对！');
        x = NaN;
        minf = NaN;
        return;
    else
        if alpha <= 1
            disp('alpha参数不对！');
            x = NaN;
            minf = NaN;
            return;
        end
    end
end

df = diff(f);
f0 = subs(f, findsym(f), 0);
df0 = subs(df, findsym(df), 0);
a = 0;
b = XMAX;
k = 0;
t = (a+b)/2;    % 初始探测点

while 1
    ft = subs(f, findsym(f), t);    % 探测点的函数值
    f1 = f0 + sigma1*t*df0;    % 可接受函数值上限
    if ft <= f1
        f2 = sigma2*t*df0;    % 可接受函数值下限
        if ft >= f2
            x = t;
            break;
        else
            a = t;
            if b < XMAX
                t = (a+b)/2;
            else
                t = alpha*t;
            end
        end
    else
        b = t;
        t = (a+b)/2;
    end
    k = k+1;
end

minf = subs(f, findsym(f), x);
format short;
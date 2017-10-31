function [x, minf] = minGlbNewton(f, x0, eps)
% 目标函数:f
% 初始点:x0
% 精度:eps
% 目标函数取最小值时的自变量值:x
% 目标函数的最小值:minf

format long;
if nargin == 2
    eps = 1.0e-6;
end

var = findsym(f);
df = diff(f);    % 一阶导数
d2f = diff(df);    % 二阶导数
bConti = 1;

while bConti
    fx0 = Funval(f, sym(var(1)), x0);    % 函数值
    dfx = Funval(df, sym(var(1)), x0);    % 一阶导数值
    d2fx = Funval(d2f, sym(var(1)), x0);    % 二阶导数值
    if dfx == 0    % 一阶导数值为0
        if d2fx >= 0
            x = x0;
            bConti = 0;
        end
        delta = eps;
        while 1
            fd = Funval(f, sym(var(1)), x0+delta);    % 向前搜索
            if fd >= fx0
                delta = delta*2;    % 增大步长
                continue;
            else
                x0 = x0 + delta;    % 更新搜索点
                break;
            end
        end
    else
        beta = d2fx;
        if beta <= 0
            beta = 1;
        end
        alpha = 1;
        while 1
            x1 = x0 - alpha*dfx/beta;    % 判断新的点是否可以接受
            fx1 = Funval(f, sym(var(1)), x1);
            tol = fx1 - fx0 + (dfx).^2*alpha/4/beta;
            if tol <= 0
                if abs(x1 - x0)<=eps
                    bConti = 0;
                    x = x1;
                    break;
                else
                    x0 = x1;
                    break;
                end
            else
                alpha = alpha / 2;    % 缩短步长
                continue;
            end
        end
    end
end
minf = subs(f, findsym(f), x);
format short;
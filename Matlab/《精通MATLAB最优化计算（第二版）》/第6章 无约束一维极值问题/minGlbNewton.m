function [x, minf] = minGlbNewton(f, x0, eps)
% Ŀ�꺯��:f
% ��ʼ��:x0
% ����:eps
% Ŀ�꺯��ȡ��Сֵʱ���Ա���ֵ:x
% Ŀ�꺯������Сֵ:minf

format long;
if nargin == 2
    eps = 1.0e-6;
end

var = findsym(f);
df = diff(f);    % һ�׵���
d2f = diff(df);    % ���׵���
bConti = 1;

while bConti
    fx0 = Funval(f, sym(var(1)), x0);    % ����ֵ
    dfx = Funval(df, sym(var(1)), x0);    % һ�׵���ֵ
    d2fx = Funval(d2f, sym(var(1)), x0);    % ���׵���ֵ
    if dfx == 0    % һ�׵���ֵΪ0
        if d2fx >= 0
            x = x0;
            bConti = 0;
        end
        delta = eps;
        while 1
            fd = Funval(f, sym(var(1)), x0+delta);    % ��ǰ����
            if fd >= fx0
                delta = delta*2;    % ���󲽳�
                continue;
            else
                x0 = x0 + delta;    % ����������
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
            x1 = x0 - alpha*dfx/beta;    % �ж��µĵ��Ƿ���Խ���
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
                alpha = alpha / 2;    % ���̲���
                continue;
            end
        end
    end
end
minf = subs(f, findsym(f), x);
format short;
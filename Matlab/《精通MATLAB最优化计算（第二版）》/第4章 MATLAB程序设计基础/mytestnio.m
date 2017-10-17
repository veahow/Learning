function [y1, y2] = mytestnio(x1, x2)
if nargin == 1
    y1 = x1;
    if nargout == 2
        y2 = x1;
    end
else
    if nargout == 1
        y1 = x1+x2;
    else
        y1 = x1;
        y2 = x2;
    end
end
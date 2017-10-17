function y = mytestvario(varargin)
temp = 0;
for i = 1:length(varargin)
    temp = temp + mean(varargin{i}(:));
end
y = temp/length(varargin);
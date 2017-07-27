#!/usr/bin/python
# Filename : Func_para.py

# 默认参数
def say(message, times = 1):
    print(message * times)

say('Hello')
say('World', 5)
# 只有在形参表末尾的那些参数可以有默认参数值，不能先声明有默认值的形参再声明没有默认值的形参

# 关键参数
def func(a, b=5, c=10):
    print('a is', a, 'and b is', b, 'and c is', c)

func(3, 7)
func(25, c=24)
func(c=50, a=100)
# 不必担心参数的顺序

# return语句
def maximum(x, y):
    if x > y:
        return x
    else:
        return y

print(maximum(2, 3))

def someFunction():
    pass
# pass相当于语句块占位符，不实现任何功能



#!/usr/bin/python
# Filename : Function.py

def sayHello():
    print('Hello World!')
    # Block belonging to the function

sayHello() # Call the function

# 函数形参
def printMax(a, b):
    if a > b:
        print(a, 'is maximum')
    else:
        print(b, 'is maximum')

printMax(3, 4) # Directly give literal values

x = 5
y = 7

printMax(x, y) # Give variables as arguments

# 局部变量
def func(x):
    print('x is', x)
    x = 2
    print('Changed local x to', x)

x = 50
func(x)
print('x is still', x)

# 使用global语句声明全局变量
def func():
    global x
    print('x is', x)
    x = 2
    print('Changed local x to', x)

x = 50
func()
print('Value of x is', x)

#!/usr/bin/python
# Filename : VarAndExpression.py
i = 5
print(i)
i = i + 1
print(i)

s = '''This is a multi-line
This is the second line.'''
print(s)
# 在Python编写过程中尽量使每个物理行对应一个逻辑行
# Python对缩进有强烈的要求，我坚持以四个空格为一个缩进
length = 5
breadth = 2
area = length * breadth
print('Area is', area)
print('Perimeter is', 2 * (length + breadth))

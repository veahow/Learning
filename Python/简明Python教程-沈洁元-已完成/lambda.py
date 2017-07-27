#!/usr/bin/python
# Filename : lambda.py

def make_repeater(n):
    return lambda s: s*n

twice = make_repeater(2)

print(twice('word'))
print(twice(5))

# lambda语句用于创建函数对象

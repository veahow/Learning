#!/usr/bin/python
# Filename : Using_tuple.py

zoo = ('wolf', 'elephant', 'penguin')
print('Number of animals in the zoo is', len(zoo))

new_zoo = ('monkey', 'dolphin', zoo)
print('Number of animals in the new zoo is', len(new_zoo))
print('All animals in new zoo are', new_zoo)
print('Animals brought from old zoo are', new_zoo[2])
print('Last animal brought form old zoo is', new_zoo[2][2])

# 元组最常用的用法就是在打印语句中
age = 22
name = 'Swaroop'

print('%s is %d years old' % (name, age))
print('Why is %s playing with that python?' % name)

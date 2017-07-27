#!/usr/bin/python
# Filename : For.py

for i in range(1, 5):
    print(i)
else:
    print('The for loop is over')

# range为Python的内建函数，第三个参数称为步长，第一个参数和第二个参数为区间范围
for i in range(1, 5, 2):
    print(i)
else:
    print('The for loop is over')

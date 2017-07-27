#!/usr/bin/python
# Filename : Using_sys.py

import sys

print('The command line arguments are:')
for i in sys.argv:
    print(i)
print('\n\nThe PYTHONPATH is', sys.path, '\n')

# 字节编译的.pyc文件导入速度更快
# from...import语句，尽量减少这个语句的使用，避免名称冲突

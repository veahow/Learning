#!/usr/bin/python
# Filename : Using_init.py

class Person:
    def __init__(self, name):
        self.name = name
    def sayHi(self):
        print('Hello, my name is', self.name)

p = Person('Eahow')
p.sayHi()

# This short example can also be written as Person('Eahow').sayHi()
# __init__()方法相当于C/C++中的构造器Constructor

#!/usr/bin/python
# Filename : CreateClass.py

class Person:
    pass # An empty block

p = Person()
print(p)

class People:
    def sayHi(self):
        print('Hello, how are you?')

pe = People()
pe.sayHi()

# This short example can also be written as People().sayHi()
People().sayHi()

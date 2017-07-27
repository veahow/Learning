#!/usr/bin/python
# Filename : ObjVar.py

class Person:
    '''Represents a person.'''
    population = 0

    def __init__(self, name):
        '''Initializes the person's data.'''
        self.name = name
        print('(Initializing %s)' % self.name)

        # When this person is created, he/she
        # adds to the population
        Person.population += 1

    def __del__(self):
        '''I am dying.'''
        print('%s says bye.' % self.name)

        Person.population -= 1

        if Person.population == 0:
            print('I am the last one.')
        else:
            print('There are still %d people left.' % Person.population)

    def sayHi(self):
        '''Greeting by the person.

        Really, that's all it does.'''
        print('Hi, my name is %s.' % self.name)

    def howMany(self):
        '''Prints the current population.'''
        if Person.population == 1:
            print('I am the only person here.')
        else:
            print('We have %d persons here.' % Person.population)

eahow = Person('Eahow')
eahow.sayHi()
eahow.howMany()

ranc = Person('Ranc')
ranc.sayHi()
ranc.howMany()

eahow.sayHi()
eahow.howMany()

# Python惯例：如果变量名以双下划线为前缀，则称其为私有变量。
# 若是其他的变量名称，则其为公共变量

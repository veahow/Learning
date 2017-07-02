# 面向对象编程/继承和多态
# 继承 Inheritance
class Animal(object):
    def run(self):
	    print('Animal is running...')
		
class Dog(Animal):
    pass
	
class Cat(Animal):
    pass
	
dog = Dog()
dog.run()
cat = Cat()
cat.run()

class Dog(Animal):
    def run(self):
	    print('Dog is running...')
	def eat(self):
	    print('Eating meat...')
		
class Cat(Animal):
    def run(self):
	    print('Dog is running...')
	def eat(self):
	    print('Eating meat...')
		
dog = Dog()
dog.run()
cat = Cat()
cat.run()

# 多态 Polymorphism
a = list()
b = Animal()
c = Dog()
print('%s' % isinstance(a, list))
print('%s' % isinstance(b, Animal))
print('%s' % isinstance(b, Dog))
print('%s' % isinstance(b, Cat)) 
print('%s' % isinstance(c, Dog))
print('%s' % isinstance(c, Cat))
print('%s' % isinstance(c, Animal)) 
	

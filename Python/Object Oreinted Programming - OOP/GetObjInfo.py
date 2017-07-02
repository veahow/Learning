# 面向对象编程/实例属性和类属性

# 使用type()
print(type(123)) # <class 'int'>
print(type('str')) # <class 'str'>
print(type(None)) # <type(None) 'NoneType'>

print(type(abs)) # class 'builtin_function_or_method'>

print(type(123) == type(456)) # True
print(type(123) == int) # True
print(type('abc') == type('123')) # True
print(type('abc') == str) # True
print(type('abc') == type(123)) # False

import types
def fn():
     pass
	 
print(type(fn) == types.FunctionType) # True
print(type(abs) == types.BuiltinFunctionType) # True
print(type(lambda x: x) == types.LambdaType) # True
print(type((x for x in range(10))) == types.GeneratorType) # True

# 使用instance() 
# 使用dir() - getattr()、setattr()、hasattr()


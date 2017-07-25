# 面向对象编程/访问限制

class Student(object):
    def __init__(self, name, score):
	    self.__name = name
		self.__score = score
	def print_score(self):
	    print('%s: %s' % (self.__name, self.__score))
	def get_name(self):
	    return self.__name
	def get_score(self):
	    return self.__score
	def set_name(self, name):
	    self.__name = name
	def set_score(self, score):
	    if 0 <= score <= 100:
		    self.__score = score
	    else:
		    raise ValueError('Bad Score')

	
# 其中许多思想和C++一致，但是Python还是太随意了
# 在变量前加两个下划线表示私有不可访问，但实际还是可以通过特别的方法访问
# 例如定义私有变量__name后，并不是不能再访问相应存储单元，这是因为Python解释器把__name改名了
# 所以你不能够直接访问__name，假如__name为Student类的属性
# 那么Python解释器可能把__name改成了_Student_name
# 至于为什么说是可能，是因为不同Python解释器改变__name后的结果不一样
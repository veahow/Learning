# 面向对象编程/类和实例

# 类的定义及实例对象的创建
class Student(object):
    pass
	
eahow = Student()
eahow.name = 'Eahow Chen'

# 模板方法绑定
class Student(object):
    # init前后下划线的个数是两个 为__init__而不是_init_
    def __init__(self, name, score):
	    self.name = name
		self.score = score

eahow = Student('Eahow Chen', 91)

def print_score(std):
    print('%s: %s' % (std.name, std.score))
print_score(eahow)

# 数据封装
class Student(object):
    def __init__(self, name, score):
	    self.name = name
		self.score = score
	def print_score(self):
	    print('%s: %s' % (self.name, self.score))
	def get_grade(self):
	    if self.score >= 90:
		    return 'A'
		elif self.score >= 60:
		    return 'B'
		else:
		    return 'C'

eahow = Student('Eahow Chen', 91)
eahow.print_score()
eahow.get_grade()
		
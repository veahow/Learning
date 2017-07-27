# Filename : String.py
# 字符串可以使用单引号和双引号来表示
print('Quote me on this')
print("What's your name?")
# 使用三引号可以指示一个多行的字符串
print('''This is a multi-line string. This is the first line.
This is the second line.
"What's your name?" I asked.
He said "Bond, James Bond."''')
# 使用转义字符\可以指示特别的字符
print('What\'s your name?')
# 在一个字符串中，行末的单独一个反斜杠表示字符串在下一行继续
print("This is the first sentence.\
This is the second sentence.")
# 想要不加转义字符来表示字符串，使用自然字符串，给字符串加上前缀r或R
print(r"New lines are indicated by \n")
# 给字符串加上前缀u或U，可以让Python处理Unicode文本。在处理文本文件的时候使用Unicode字符串，特别是这个文件含有非英语语言的文本
print(u"This is a Unicode string.")

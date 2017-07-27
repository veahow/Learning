#!/usr/bin/python
# Filename : Pickling.py

import pickle as p
# cPickle模块使用C语言编写，因此运行速度比pickle模块更快，在Python3统一为pickle模块

shoplistfile = 'shoplist.data'
# the name of the file where we will store the object

shoplist = ['apple', 'mango', 'carrot']

# Write to the file
f = open(shoplistfile, 'wb')
p.dump(shoplist, f) # dump the object to a file
f.close()

del(shoplist)# remove the shoplist

# Read back from the storage
f = open(shoplistfile, 'rb')
storedlist = p.load(f)
print(storedlist)

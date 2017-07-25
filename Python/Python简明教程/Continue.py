#!/usr/bin/python
# Filename : Continue.py

while True:
    s = input('Enter something : ')
    if s == 'quit':
        break
    if len(s) < 3:
        continue
    print('Input is of sufficient length')
    # Do other kinds of processing here

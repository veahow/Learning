#!/usr/bin/python
# Filename : If.py

number = 23
guess = int(input('Enter an integer : '))

if guess == number:
    print('Congratulations, you guessed it.')
    # New block starts here
    print('But you do not win any prizes!')
    # New block ends here
elif guess < number:
    print('No, it is a little higher than that')
    # Another block
    # You can do whatever you want in a block ...
else:
    print('No, it is a little lower than that')
    # You must have guess > number to reach here
print('Done')
# This last statement is always executed, after the if statement is executed

import sys

def digit(x):
    if x == 0:
        return 0
    elif x < 10:
        return 1
    else:
        return digit(x//10) + 1

def digit_iterative(x):
    digitCount =0
    while x > 0:
        digitCount += 1
        x = x//10
    return digitCount

input = int(sys.argv[1])

iterativeTotal = digit_iterative(input)
recursiveTotal = digit(input)
print ("The number of digit(s) calculated by recursive is %d and by iterative is %d."%(recursiveTotal,iterativeTotal))

import sys

def sum_recursive(x):
    if x == 0:
        return 0
    else:
        return sum_recursive(x-1) + x

def sum_iterative(x):
    total = 0
    for i in range (x+1):
        total += i
    return total

input = int(sys.argv[1])

iterativeTotal = sum_iterative(input)
recursiveTotal = sum_recursive(input)

print ("The SUM value calculated by recursive is %d and by iterative is %d."%(recursiveTotal,iterativeTotal))

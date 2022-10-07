import sys

def double(x):
    return (2*x)

def square(x):
    return (x**2)

def cube(x):
    return (x**3)

def doTwice(func,x):
    if func == 1:
        msg = double(double(x))
    elif func == 2:
        msg = square(square(x))
    elif func == 3:
        msg = cube(cube(x))
    else:
        msg = "It cannot be supported"
    return msg

x = int(sys.argv[1])
func = int(sys.argv[2])

msg = doTwice(func,x)
print(msg)

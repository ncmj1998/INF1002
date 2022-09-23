# # Develop your own math module (myMath) including eight basic functions.
# # Function 1: add(x, y)  return the summation of x and y
def add(x,y):
  return x+y

# # Function 2: subtraction(x, y) return the subtraction between x and y
def subtraction(x,y):
  return x-y

# # Function 3: evenNum(x) return the number of even numbers in the given list
def evenNum(x):
  even_count = 0
  for number in x:
    if number%2==0:
      even_count += 1
  return even_count

# # Function 4:  maximum(x) return the maximum value from the given list x
def maximum(x):
  max_number =0
  for y in x:
    if y>max_number:
      max_number=y
  return max_number

# # Function 5: minimum(x) return the minimum value from the given list x
def minimum(x):
  min_number=x[0]
  for y in x:
    if y<min_number:
      min_number=y
  return min_number

# # Function 6: absolute(x) return the absolute value of one number x
def absolute(x):
  return abs(x)

# # Function 7: sumTotal(x) return the summation of all the elements for a given list x
def sumTotal(x):
  total_sum = 0
  for number in x:
    total_sum += number
  return total_sum


# # Function 8: clear(x) this function sets all the elements into 0 for a given list x
def clear(x):
  index=0
  for number in x:
    x[index]=0
    index+=1
  return x

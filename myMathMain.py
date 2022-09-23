import sys
import myMath

# Step 1: Input: allows users to input multiple numbers. Assuming all input numbers are integers.
int_string = sys.argv[1]

# Step 2: using forloop to change str to int and store all the numbers into one list
int_list = [int(x) for x in int_string.split(',')]

# Step 3:
# a. calculate and print out the difference between the biggest and the smallest number in the list
max_num = myMath.maximum(int_list)
min_num = myMath.minimum(int_list)

# b. calculate and print out the summation between the biggest and the smallest numbers in the list
big_small_sum= myMath.add(max_num,min_num)

# c. calculate and print out the summation of all the input numbers in the list
total_sum = myMath.sumTotal(int_list)

# d. calculate and print out the number of even numbers in the list
even_count = myMath.evenNum(int_list)

# e. If the smallest number in the list is smaller than 5, set all the value to 0.
if min_num<5:
  int_list=myMath.clear(int_list)
# Otherwise, remain the same. Print all the values in the list in the end.


print (f"The difference is:{myMath.subtraction(max_num,min_num)} The summation is: {myMath.add(max_num,min_num)} The summation of all input is: {total_sum} The number of even numbers is: {even_count} The values in the list are:{int_list} ")


import sys

# inputs = []
# for i in range(1,len(sys.argv)):
#     input = sys.argv[i]
#     if input.isdigit():
#         inputs.append(int(sys.argv[i]))
#     else:
#         print("Invalid input")
#         exit()

inputs = sys.argv[1]
inputs = inputs.split(",")
for i in range(len(inputs)):
    if inputs[i].isdigit():
        inputs[i] = int(inputs[i])
    else:
        print("Invalid input")
        exit()

inputs.sort() ##sort input in ascending order

even_count = 0
odd_count = 0
even_total = 0
odd_total = 0
biggest_number = inputs[-1]
smallest_number = inputs[0]
total = 0

for input in inputs:
    total += input
    if (input%2) == 0:
        even_count+=1
        even_total+=input
    else:
        odd_count+=1
        odd_total+=input
centered_avg = (total - biggest_number - smallest_number) / (len(inputs)-2)

output = f"The sum of all even numbers is {even_total}, the sum of all odd numbers is {odd_total}," \
         f"the difference between the biggest and smallest number is {biggest_number-smallest_number}, the " \
         f"total number of even numbers is {even_count}, the total number of odd numbers is " \
         f"{odd_count}, the centered average is {centered_avg:0.0f}."

print(output)
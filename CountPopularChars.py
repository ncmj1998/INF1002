import sys

if len(sys.argv) < 2:
    print("Invalid input")
    exit()

input = sys.argv[1] #get user input
input = input.lower()#convert input to lower case

letters_dict = {}
for letter in input: #if letter in dictionary, add count
    if letter in letters_dict:
        letters_dict[letter] = letters_dict[letter] +1
    else: #else create new pair
        letters_dict[letter] = 1

#sort dictionary in descending order by value
letters_dict = dict(sorted(letters_dict.items(), key=lambda x: (-x[1], x[0])))
count = 0
output = ""
for pair in letters_dict:
    if count < 5:
        output += f"{pair}:{letters_dict[pair]}"
        count +=1
        output += ","

print(output[:-1]) #exclude last char
import sys

#converting the input to tuple for the purpose of various_count function
words_list = tuple(sys.argv[1].split(','))

def letter_count(string, destination={}):
  for letter in string:
    if letter in destination:
      destination[letter]+=1
    else:
      destination[letter]=1

def double_count(str1,str2):
  letter_dict={}
  letter_count(str1,letter_dict)
  letter_count(str2,letter_dict)
  return letter_dict

def various_count(*str):
  letter_dict={}
  x=list(*str)
  for string in x:
    letter_count(string, letter_dict)
  return letter_dict

sorted_total = sorted(various_count(words_list).items(),key=lambda x:x[0],reverse=True)
output_str=''
for item in sorted_total:
  output_str+=('%s:%d ' % (item[0], item[1]))

print(output_str)
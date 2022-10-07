from sys import argv

input_list = argv[1].split(',')
scale_number= int(argv[2])
int_list = [int(y) for y in input_list]

def function(list1, scale):
  result_list =[]
  for i in list1:
    result_list.append(i*scale)
  return result_list

def sort(list1):
  sorted_list=sorted(list1, key=lambda x: x[-1])
  sorted_list=[int(y) for y in sorted_list]
  return sorted_list

def goodSales(list1):
  avg = sum(list1)/len(list1)
  goodList = []
  for x in list1:
    if (x>avg):
      goodList.append(x)
  return goodList


if __name__== "__main__":
  scaled_number = function(int_list,scale_number)
  sorted_number = sort(input_list)
  sales_number = goodSales(int_list)
  print(f'The scaled number is: {scaled_number} The sorted sales numbers are: {sorted_number} The good sales numbers are: {sales_number}')
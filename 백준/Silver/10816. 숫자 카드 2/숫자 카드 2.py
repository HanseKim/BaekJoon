a = input()
numbers = input()
numbers_list = numbers.split()

my_dict = {}
for num in numbers_list:
    num = int(num)
    if num in my_dict:
        my_dict[num] += 1
    else:
        my_dict[num] = 1
b = input()
number = input()
find_list = number.split()

for num in find_list:
    num = int(num)
    if(num in my_dict):
        print(my_dict[num],end=" ")
    else:
        print("0",end=" ")
import sys
input = sys.stdin.readline

n = int(input().strip())

def flip(left, right, fish):
    while left <= right and left < n and right >=0 :
        fish[left], fish[right] = -fish[right], -fish[left]
        left += 1
        right -= 1

def check(fish):
    checkList = [i+1 for i in range(n)]
    for i in range(n):
        if fish[i] != checkList[i]:
            return False
    return True

for _ in range(5):
    arr = []
    fish = list(map(int, input().strip().split())) 
    left, right = 0, len(fish) - 1

    while left < n and fish[left] == left + 1:
        left += 1
    while right >= 0 and fish[right] == right + 1:
        right -= 1

    fish2 = fish[:]
    flip(left, right, fish2)
    if check(fish2) :
        print('one')
        continue
    
    index = 0
    while index < n - 1:
        if fish[index+1] != fish[index] + 1:
            arr.append(index)
        index+=1
    # print(arr)
    # print(len(arr))
    if len(arr) > 4:
        print('over')
    else :
        print('two')
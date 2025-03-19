# 13305번 주유소

# sys.stdin.readline 괄호 없이 써야함
# 파이썬에서 index 랑 같이 저장하기 힘듦. c++로 생각하지 말기

import sys

input = sys.stdin.readline

n = int(input())

road = list(map(int, input().split())) 
cost = list(map(int, input().split()))

res = 0
min = cost[0]

for i in range(n-1):
    if min > cost[i]:
        min = cost[i]
    res += min * road[i]

print(res)
# 11279 최대 힙

import sys, heapq 
input = sys.stdin.readline
n = int(input())
num = []
for _ in range(n):
    x = int(input().strip()) 

    if x == 0:
        if num:
            print(-heapq.heappop(num)) 
        else:
            print(0)
    else:
        heapq.heappush(num, -x)  

# 시간 초과 -> readline 함수로 변경
# 앞으로 백준 파이썬으로 풀 때 sys.stdin.readline 사용하기

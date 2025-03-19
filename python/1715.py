# 1715 카드 정렬하기

import heapq

n = int(input())
card = [int(input()) for _ in range(n)]

res = 0
heapq.heapify(card) 

while len(card) > 1:
    f = heapq.heappop(card)
    s = heapq.heappop(card)
    res += f+ s
    heapq.heappush(card, f+s)

print(res)

# heapq 사용 
# 선언 : heapq.heapify( 배열 이름 )
#   ㄴ> 자동으로 힙으로 변환
# pop : heapq.heappop( 배열 이름 )
# push : heapq.heappush( 배열 이름, 넣을 값)
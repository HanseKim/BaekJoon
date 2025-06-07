import sys
import heapq
input = sys.stdin.readline
from collections import defaultdict

k = int(input())
least = list(map(int, input().split()))
minimum = [list(map(int, input().split())) for _ in range(k)]

dp = dict()
start = (0, 0, 0, 0)
dp[start] = (0, 0, [])

for idx, ing in enumerate(minimum):
    ndp = dict(dp) 
    for state, (cost, nsum, indices) in dp.items():
        nstate = tuple(min(state[j] + ing[j], least[j]) for j in range(4))
        ncost = cost + ing[4]
        nnsum = nsum + sum(ing[:4])
        nindices = indices + [idx+1]
        if nstate not in ndp:
            ndp[nstate] = (ncost, nnsum, nindices)
        else:
            prev_cost, prev_nsum, prev_indices = ndp[nstate]
            if (ncost < prev_cost or
                (ncost == prev_cost and nnsum > prev_nsum) or
                (ncost == prev_cost and nnsum == prev_nsum and nindices < prev_indices)):
                ndp[nstate] = (ncost, nnsum, nindices)
    dp = ndp

target = tuple(least)
if target in dp:
    print(*dp[target][2])
else:
    print(0)
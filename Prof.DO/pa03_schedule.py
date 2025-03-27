import sys
input = sys.stdin.readline

study, time = map(int, input().split())
N = int(input().strip())

arr = [study for _ in range(time)]

for _ in range(N):
    n = int(input().strip())
    for _ in range(n):
        a,b,c, = map(int, input().split())
        for i in range(a,b):
            arr[i] += c

answer = 0
max = 0
for i in range(time):
    if arr[i] < 0 and max > answer:
        answer = max
    max += arr[i]
    if max < 0:
        max = 0

if max > answer:
    answer = max

print(answer)

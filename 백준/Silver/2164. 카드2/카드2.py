from collections import deque

a = int(input())
dq = deque(list(range(1,a+1)))
while len(dq) != 1:
    dq.popleft()
    n = dq.popleft()
    dq.append(n)

print(dq.popleft())
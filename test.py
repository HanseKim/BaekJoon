import sys
from collections import deque
input = sys.stdin.readline

k = int(input().strip())

for _ in range(k):
    v, e = map(int,input().split())
    q = deque()
    connect = [[] for _ in range(v+1)]
    visited = [0 for _ in range(v+1)]
    for _ in range(e):
        a,b = map(int,input().split())
        connect[a].append(b)
        connect[b].append(a)
    flag = "YES"
    for i in range(1, v+1):
        if visited[i] == 0:
            q.append(i)
            visited[i] = 1
            while q:
                cur = q.popleft()
                for neighbor in connect[cur]:
                    if visited[neighbor] == 0:
                        q.append(neighbor)
                        visited[neighbor] = -visited[cur]
                    elif visited[neighbor] == visited[cur]:
                        flag = "NO"
                        break
                if flag == "NO":
                    break
        if flag == "NO":
            break
    print(flag)

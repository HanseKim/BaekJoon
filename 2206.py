# 2206 벽 부수고 이동하기

import sys 
from collections import deque

input = sys.stdin.readline
n, m = map(int,input().split())

graph = [ list(map(int, input().rstrip())) for _ in range(n) ]
visited = [ [[0]*2 for _ in range(m)] for _ in range(n)]

q = deque([(0,0,0)])
visited[0][0][0] = 1

dx = [0,0,1,-1]
dy = [1,-1,0,0]

while q:
    y, x, b = q.popleft()

    if x == m-1 and y == n-1:
        print(visited[y][x][b])
        exit()

    for i in range(4):
        nx,ny = x + dx[i], y + dy[i]
        if 0 <= nx < m and 0 <= ny < n:
            if graph[ny][nx] == 1 and b == 0:
                visited[ny][nx][1] = visited[y][x][0] + 1
                q.append((ny,nx,1))
            elif graph[ny][nx] == 0 and visited[ny][nx][b] == 0:
                visited[ny][nx][b] = visited[y][x][b] + 1
                q.append((ny,nx,b))
print(-1)


# deque 사용
# from collections import deque

# 3차원 배열 
# visited = [ [[0]*2 for _ in range(m)] for _ in range(n)]

# 2차원으로 숫자 받아와서 나누기
# graph = [ list(map(int, input().rstrip())) for _ in range(n) ]

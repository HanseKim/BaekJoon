import sys, heapq
input = sys.stdin.readline

def h(curX, curY, goalX, goalY):
    return abs(curX - goalX) + abs(curY - goalY)

def g(Gscore, x, y):
    return Gscore.get((x, y), float('inf'))

def f(Gscore, x, y, goalX, goalY):
    return g(Gscore, x, y) + h(x, y, goalX, goalY)

def a_star(startX, startY, goalX, goalY, M, m, n):
    dx = [0, 0, 1, -1]
    dy = [1, -1, 0, 0]

    openList = []
    heapq.heappush(openList, (0, (startX, startY)))
    cameFrom = {}
    Gscore = {(startX, startY): 0}

    while openList:
        _, (x, y) = heapq.heappop(openList)

        if (x, y) == (goalX, goalY):
            path = []
            while (x, y) in cameFrom:
                path.append((x, y))
                x, y = cameFrom[(x, y)]
            path.append((startX, startY))
            path.reverse()
            return path

        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if 0 <= nx < m and 0 <= ny < n and M[nx][ny] != 0:
                tentative_g = Gscore[(x, y)] + 1
                if (nx, ny) not in Gscore or tentative_g < Gscore[(nx, ny)]:
                    cameFrom[(nx, ny)] = (x, y)
                    Gscore[(nx, ny)] = tentative_g
                    f_score = tentative_g + h(nx, ny, goalX, goalY)
                    heapq.heappush(openList, (f_score, (nx, ny)))

    return None

m,n = map(int, input().split())

M = [[1] * n for _ in range(m)]

zero = int(input().strip())
for _ in range(zero):
    z, x, y = map(int, input().split())
    M[x][y] = 0 

start, startX, startY = input().split()
startX, startY = int(startX), int(startY)
M[startX][startY] = 2

g, goalX, goalY = input().split()
goalX, goalY = int(goalX), int(goalY)
M[goalX][goalY] = 3

ob, obCnt = input().split()
obCnt = int(obCnt)
obList = []
for _ in range(obCnt):
    lx, ly, rx, ry = map(int,input().split())
    for i in range(lx,rx+1):
        for j in range(ly,ry+1):
            M[i][j] = 0

path = a_star(startX, startY, goalX, goalY, M, m, n)
if path:
    print(3*(len(path)-1))
else:
    print("경로 없음")

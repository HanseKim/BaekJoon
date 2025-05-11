import sys
input = sys.stdin.readline

INF = int(1e9)

n = int(input().strip())

P = [[0] * n for _ in range(n)]  # 중간 노드 기록

def floyd(n, D, start, last):
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if D[i][k] + D[k][j] < D[i][j]:
                    P[i][j] = k
                    D[i][j] = D[i][k] + D[k][j]
    return D[start][last]

def way(start, last):
    middle = P[start][last]
    if middle == 0:
        return []
    return way(start, middle) + [middle] + way(middle, last)

# 입력 및 그래프 구성
W = [[INF if x == -1 else x for x in map(int, input().split())] for _ in range(n)]

# 깊은 복사
D = [row[:] for row in W]

start, last = map(int, input().split())

print(f"Shortest cost from {start} to {last}: {floyd(n, D, start, last)}")
print(f"Path from {start} to {last}: {[start, *way(start, last), last]}")

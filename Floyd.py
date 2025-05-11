import sys
input = sys.stdin.readline

n = int(input().strip())

# 지나온 v중 제일 큰 v : P
P = [[0] * n for _ in range(n)]

def floyd(n, D, start, last):
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if D[i][k] + D[k][j] < D[i][j]:
                    P[i][j] = k
                    D[i][j] = D[i][k] + D[k][j]
    return D[start][last]

def way(start, last):
    wayList = []
    middle = P[start][last]
    if middle != 0:
        wayList.append(middle)
        if len(way(start, middle)) > 0: 
            wayList.append(way(start, middle))
        if len(way(middle, last)) > 0:
            wayList.append(way(middle, last))

    return wayList

# 간선의 여부 : W
W = [[int(1e9)] * n for _ in range(n)]

for i in range(n):
    connect = list(map(int, input().split()))
    for index in range(len(connect)):
        if connect[index] == -1:
            connect[index] = int(1e9)
    W[i] = connect

# 최적의 비용 : D
D = W[:]

start, last = map(int, input().split())

print("Shortest const from %d to %d: %d" %(start,last,floyd(n, D, start, last)))
print("Path from %d to %d: %s" %(start, last, str([start, *way(start, last), last])))
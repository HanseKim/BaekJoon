import sys
sys.setrecursionlimit(10000)
input = sys.stdin.readline

def dfs(start, graph, visited, dist, acc_time):
    visited[start] = True
    dist[start] = acc_time
    for neighbor, weight in graph[start]:
        if not visited[neighbor]:
            dfs(neighbor, graph, visited, dist, acc_time + weight)

n, c1, c2 = map(int, input().split())
graph = [[] for _ in range(n + 1)]

for _ in range(n - 1):
    a, b, l = map(int, input().split())
    graph[a].append((b, l))
    graph[b].append((a, l))

dist_c1 = [0] * (n + 1)
dist_c2 = [0] * (n + 1)

visited = [False] * (n + 1)
dfs(c1, graph, visited, dist_c1, 0)

visited = [False] * (n + 1)
dfs(c2, graph, visited, dist_c2, 0)

result = []
for i in range(1, n + 1):
    if i == c1 or i == c2:
        continue
    min_time = min(dist_c1[i], dist_c2[i])
    result.append((min_time, i))

result.sort()

for _, node in result:
    print(node)

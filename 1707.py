# 이분 그래프

import sys
from collections import deque
input = sys.stdin.readline

k = int(input().strip())

for _ in range(k):
    v, e = map(int,input().split())
    q = deque()
    connect = [[] for _ in range(v+1)] # 인접 리스트 사용
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

# connect = [[0 for _ in range(v+1)] for _ in range(v+1)]
# 이 방식은 모든 정점 간의 관계를 저장하기 때문에, 정점 개수 v가 커질 경우 v^2 만큼 메모리를 사용하게 됨.

# 인접 리스트에서 인접 행렬 방식으로 접근
# for i in range(len(connect[visit])):
#     if connect[visit][i] == 1:  # ❌ 인접 리스트에서는 이 조건은 의미 없음
# connect[visit]은 정점 visit에 연결된 정점들의 리스트
# connect[visit][i]는 연결된 노드 번호이고, 1인지 아닌지를 판단할 수 없음
# => 
# for neighbor in connect[visit]:  # ✅ 연결된 정점 직접 접근

#  모든 컴포넌트를 탐색하지 않음
#  for i in range(1, v+1):
#     if visited[i] == 0:
#         # 새로운 컴포넌트에서 BFS 시작
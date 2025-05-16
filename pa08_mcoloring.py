import sys
input = sys.stdin.readline

def dfs(depth):
    if depth == n:
        global cnt1
        cnt1+=1
        return
    for col in range(1, m+1):
        global cnt2
        cnt2 += 1
        same = True
        for i in range(n):
            if connect[depth][i] == 1 and color[i] == col:
                same = False
                break
        if same:
            color[depth] = col
            dfs(depth+1)
            color[depth] = 0

n, m = map(int, input().split())
connect = [list((map(int, input().split()))) for _ in range(n)]
color = [0] * n

cnt1, cnt2 = 0,0

dfs(0)

if cnt1 == 0:
    print('no')
else :
    print(cnt1)
    print(cnt2)
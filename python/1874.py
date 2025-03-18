# 1874 스택 수열

n = int(input())
stack = [int(input()) for i in range(n)]
l = []
idx = 0

res = []

for s in stack:
    while idx < s:
        idx+=1
        res.append("+")
        l.append(idx)
    if l and l[-1] == s:
        res.append("-")
        l.pop()
    else :
        print("NO")
        exit() # 출력후 바로 종료
print("\n".join(res))
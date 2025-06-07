import sys
input = sys.stdin.readline

k = int(input().strip())
least = list(map(int, input().split()))
minimum = [list(map(int, input().split())) for _ in range(k)]

result = [25001, -1, []] 

def dfs(index, selected, total, cost):
    global result
    if all(total[i] >= least[i] for i in range(4)):
        nsum = sum(total)
        candidate = [cost, -nsum, selected[:]]
        if candidate < result:
            result = candidate
    if index == k:
        return
    ing = minimum[index]
    dfs(index + 1,
        selected + [index + 1], 
        [total[i] + ing[i] for i in range(4)],
        cost + ing[4])
    dfs(index + 1,
        selected,
        total,
        cost)

dfs(0, [], [0, 0, 0, 0], 0)

if result[0] == 25001:
    print(0)
else:
    print(*sorted(result[2]))
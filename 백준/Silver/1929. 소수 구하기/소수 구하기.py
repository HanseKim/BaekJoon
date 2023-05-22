import math

a, b = map(int, input().split())
for i in range(a, b+1):
    check = True
    if i == 1:
        check = False
    for j in range(2, math.isqrt(i)+1):
        if i % j == 0:
            check = False
            break
    if check:
        print(i)

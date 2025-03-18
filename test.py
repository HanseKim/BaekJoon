# 11650번
import sys

n = int(input())

points = [tuple(map(int, sys.stdin.readline().split())) for _ in range(n)]

points.sort()

for p in points:
    print(f"{p[0]} {p[1]}")
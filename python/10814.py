# 10814 나이순 정렬

import sys

n = int(sys.stdin.readline())  # 빠른 입력
join = [(int(age), i, name) for i, (age, name) in enumerate(input().split() for _ in range(n))]

join.sort(key=lambda x: (x[0], x[1]))  # 나이 기준 정렬, 가입 순서 유지

for age, _, name in join:
    print(age, name)  # 가입 순서 정보는 출력하지 않음

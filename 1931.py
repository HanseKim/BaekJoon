# 1931 회의실 배정

n = int(input())
room = [tuple(map(int, input().split())) for _ in range(n)]

room.sort(key=lambda p: (p[1], p[0]))

endTime=0
cnt=0
for start, end in room:
    if start >= endTime:  # 현재 회의의 시작 시간이 마지막 종료 시간보다 크거나 같으면 선택
        cnt += 1
        endTime = end  # 종료 시간을 현재 회의의 종료 시간으로 업데이트


print(cnt)
# 1월 31일
# 2월 29일
# 3월 31일
# 4월 30일
# 5월 31일
# 6월 30일
# 7월 31일
# 8월 31일
# 9월 30일
# 10월 31일
# 11월 30일
# 12월 31일

def solution(a, b):
    answer = ''
    month = [30,29,31,30,31,30,31,31,30,31,30,31]
    arr = ["FRI","SAT","SUN","MON","TUE","WED","THU"]
    day = 0
    if a == 1:
        day = b
        answer = arr[(day-1)%7]
    else :
        for i in range(0,a-1):
            day += month[i]
        day+=b
        print(day)
        answer = arr[(day)%7]
    return answer


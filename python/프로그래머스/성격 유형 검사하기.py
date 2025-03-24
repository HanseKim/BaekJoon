# 1번 지표	라이언형(R), 튜브형(T)
# 2번 지표	콘형(C), 프로도형(F)
# 3번 지표	제이지형(J), 무지형(M)
# 4번 지표	어피치형(A), 네오형(N)

def solution(survey, choices):
    cnt = {"R":0,"T":0,"C":0,"F":0,"J":0,"M":0,"A":0,"N":0}
    
    for i in range(len(survey)):
        left, right = survey[i]
        if choices[i] < 4:
            cnt[left] += 4 - choices[i]
        elif choices[i] > 4:
            cnt[right] += choices[i] - 4

    answer = ''
    for a, b in [["R","T"],["C","F"],["J","M"],["A","N"]]:
        if cnt[a] < cnt[b]:
            answer += b
        else :
            answer+=a
    return answer

print(solution(["AN", "CF", "MJ", "RT", "NA"], [5, 3, 2, 7, 5]))
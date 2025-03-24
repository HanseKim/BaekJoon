from collections import deque

def solution(dartResult):
    answer = 0
    dart = deque(dartResult)
    scores = []
    
    while dart:
        n = int(dart.popleft())
        if n == 1 and dart and dart[0] == "0":
            dart.popleft()
            n = 10
        b = dart.popleft()
        score = 0
        
        if b == "S":
            score = n
        elif b == "D":
            score = n ** 2
        elif b == "T":
            score = n ** 3
        
        if dart and (dart[0] == "*" or dart[0] == "#"):
            o = dart.popleft()
            if o == "*":
                score *= 2
                if scores:
                    scores[-1] *= 2
            elif o == "#":
                score = -score
        
        scores.append(score)
        print(scores)
    answer = sum(scores)
    return answer

print(solution("1D2S#10S"))

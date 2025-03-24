def solution(progresses, speeds):
    answer = []
    from collections import deque;
    from math import ceil
    p = deque(progresses)
    s = deque(speeds)
    while p:

        cnt = 0
        fp = p.popleft(); fs = s.popleft()
        n = ceil((100 - fp) / fs); cnt += 1
        for i in range(len(p)):
            p[i] += n*s[i]

        while p and p[0] >= 100:
            p.popleft()
            s.popleft()
            cnt+= 1
            
        answer.append(cnt)
        
    return answer


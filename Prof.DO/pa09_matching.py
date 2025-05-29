import sys
input = sys.stdin.readline

def RK(text, pattern, t, p):
    d = 5
    q = 113
    p_hash = 0
    t_hash = 0
    for i in range(p):
        p_hash = (d * p_hash + ord(pattern[i])) % q
        t_hash = (d * t_hash + ord(text[i])) % q
    h = pow(d, p - 1, q)
    compareCnt = 0
    for i in range(t - p + 1):
        compareCnt += 1
        if p_hash == t_hash:
            match = True
            for j in range(p):
                compareCnt += 1
                if text[i + j] != pattern[j]:
                    match = False
                    break
            if match:
                break
        if i < t - p:
            t_hash = (d * (t_hash - ord(text[i]) * h) + ord(text[i + p])) % q
            if t_hash < 0:
                t_hash += q
    return compareCnt

def preprocessing(pattern, p):
    sp = [-1] * p
    k = -1
    for j in range(1, p):
        while k >= 0 and pattern[j] != pattern[k+1]:
            k = sp[k]
        if pattern[j] == pattern[k+1]:
            k += 1
        sp[j] = k
    return sp

def KMP(text, pattern, t, p):
    sp = preprocessing(pattern, p)
    j = -1
    compare_cnt = 0
    i = 0
    while i < t:
        while j >= 0 and text[i] != pattern[j+1]:
            compare_cnt += 1
            j = sp[j]
        compare_cnt += 1
        if text[i] == pattern[j+1]:
            j += 1
        if j == p - 1:
            break 
        i += 1
    return compare_cnt

def computeSkip(pattern):
    jump = [-1] * 256
    for i in range(len(pattern)):
        jump[ord(pattern[i])] = i
    return jump

def BM(text, pattern, t, p):
    jump = computeSkip(pattern)
    compare_cnt = 0
    i = 0
    while i <= t - p:
        j = p - 1
        while j >= 0:
            compare_cnt += 1
            if pattern[j] != text[i + j]:
                break
            j -= 1
        if j < 0:
            break
        else:
            skip = max(1, j - jump[ord(text[i + j])])
            i += skip
    return compare_cnt

p = int(input().strip())
pattern = ""
for _ in range(p):
    pattern += input().strip()

t = int(input().strip())
txt = ""
for _ in range(t):
    txt += input().strip()

rk = RK(txt, pattern, len(txt), len(pattern))
kmp = KMP(txt, pattern, len(txt), len(pattern))
bm = BM(txt, pattern, len(txt), len(pattern))

algos = [('RK', rk), ('KMP', kmp), ('BM', bm)]
order = sorted(range(3), key=lambda i: (algos[i][1], i))
from collections import Counter
cnts = Counter([c for _, c in algos])
tokens = []
for idx in order:
    name, cnt = algos[idx]
    if cnts[cnt] > 1:
        tokens.append('0')
    else:
        tokens.append(name)

print(' '.join(tokens))

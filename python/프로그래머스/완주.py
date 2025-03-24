def solution(participant, completion):
    cnt = {}
    for p in participant:
        if p in cnt:  # or: if p in cnt.keys()
            cnt[p] += 1
        else:
            cnt[p] = 1

    for c in completion:
        if c in cnt:
            cnt[c] -= 1

    for k, v in cnt.items():
        if v > 0:
            return k

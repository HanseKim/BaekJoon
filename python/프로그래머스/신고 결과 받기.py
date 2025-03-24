def solution(id_list, report, k):
    answer = []
    dict = {} # { 이름 , [정지 신고한 사람] }
    out = [] # 정지된 사람
    for i in id_list:
        dict[i] = []

    for cmd in report:
        user, name = cmd.split()
        
        if user not in dict[name]:
            dict[name].append(user)
        if dict[name] == []:
            dict[name].append(user)

    for d in dict:
        if len(dict[d]) >= k:
            out.append(d)

    res = {}
    for o in out:
        for d in dict.keys():
            if o == d:
                for mm in dict[d]:
                    if mm in res.keys():
                        res[mm] += 1
                    else : res[mm] = 1

    for d in dict.keys():
        if d in res:
            dict[d] = res[d]
        else : dict[d] = 0
    answer = [i for i in dict.values()]
    return answer

print(solution(["muzi", "frodo", "apeach", "neo"], ["muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"]	,2))
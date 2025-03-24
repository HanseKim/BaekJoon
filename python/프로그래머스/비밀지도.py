def bin (n, t):
    res =[]
    result = []
    while t:
        res.append(t%2)
        t=int(t/2)
    for i in range(n - len(res)):
        result.append(0)
    new = res[::-1]
    for n in new:
        result.append(n)

    return result

def solution(n, arr1, arr2):
    answer = []
    res1 = []
    res2 = []
    for i in range(n):
        res1.append(bin(n,arr1[i]))
        res2.append(bin(n,arr2[i]))
    print(res1)
    print(res2)
    for i in range(n):
        result = ""
        for j in range(n):
            if res1[i][j] == 1 or res2[i][j] == 1:
                result+="#"
            else : result+=" "
        answer.append(result)
    return answer


print(solution(6,[46, 33, 33 ,22, 31, 50] , [27 ,56, 19, 14, 14, 10]))
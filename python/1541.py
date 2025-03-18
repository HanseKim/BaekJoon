# 1541 잃어버린 괄호

exp = input().split("-")

res = sum(map(int, exp[0].split("+"))) 

for e in exp[1:]:  
    res -= sum(map(int, e.split("+"))) 

print(res)

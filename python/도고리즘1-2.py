user_input = input()

parts = user_input.split(']')


part1 = parts[0].replace('[', '').strip()
part2 = parts[1].replace('[', '').strip()
part3 = parts[2].replace('[', '').strip()

cmd = part3.split(', ')

totalmin, totalsec = part1.split(":")
totalmin = int(totalmin)
totalsec = int(totalsec)

min, sec = part2.split(":")
min = int(min)
sec = int(sec)

for cmd_ in cmd:
    if cmd_ == "next":
        if sec >= 50:
            min=min+1
            sec = 60 - sec
        else : 
            sec+=10
    elif cmd_ == "prev":
        if sec < 10 :
            min = min -1 
            sec = 60 - sec

    if min > totalmin: 
        min = totalmin
        sec = totalsec
    if (min == totalmin or min > totalmin) and sec > totalsec:
        sec = totalsec
    if min < 0:
        min = 0 
        sec = 0

if min < totalmin and min >=0:
    print(f"[{min:02d}:{sec:02d}]")
elif min == totalmin :
    if sec <= totalsec:
        print(f"[{min:02d}:{sec:02d}]")
    else :
        print(f"[{totalmin:02d}:{totalsec:02d}]")
elif min < 0 :
    print("[00:00]")
elif min>totalmin:
    print(f"[{totalmin:02d}:{totalsec:02d}]")
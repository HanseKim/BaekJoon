user_input = input()

parts = user_input.split(']')

part1 = parts[0].replace('[', '').strip()
part2 = parts[1].replace('[', '').strip()
part3 = parts[2].replace('[', '').strip()

cmd = part3.split(', ')

totalmin, totalsec = map(int, part1.split(":"))
min, sec = map(int, part2.split(":"))

for cmd_ in cmd:
    if cmd_ == "next":
        sec += 10
        if sec >= 60: 
            min += 1
            sec -= 60
    elif cmd_ == "prev":
        sec -= 10
        if sec < 0: 
            min -= 1
            sec += 60

    if min > totalmin:
        min, sec = totalmin, totalsec
    if min == totalmin and sec > totalsec:
        sec = totalsec
    if min < 0:
        min, sec = 0, 0

print(f"[{min:02d}:{sec:02d}]")

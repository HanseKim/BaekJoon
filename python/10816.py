# 10816 숫자 카드 2

# 숫자 카드 개수 입력
n = int(input().strip())
cards = list(map(int, input().split()))

# 숫자를 찾을 개수 입력
m = int(input().strip())
wants = list(map(int, input().split()))

# 숫자 카드 개수를 저장할 딕셔너리
card_count = {}

# 카드 개수 세기
for card in cards:
    if card in card_count:
        card_count[card] += 1
    else:
        card_count[card] = 1

# 결과 출력 (각 숫자의 개수를 공백으로 구분하여 출력)
result = []
for w in wants:
    result.append(str(card_count.get(w, 0)))

print(" ".join(result))

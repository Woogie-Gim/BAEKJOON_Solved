arr = list(input())

digits = [0] * 10  # 각 숫자의 개수를 카운트하는 리스트

for digit in arr:
    digits[int(digit)] += 1

# 6과 9는 서로 뒤집어서 사용 가능하므로, 합쳐서 세트의 개수 계산
set_count = (digits[6] + digits[9] + 1) // 2

# 6과 9를 제외한 다른 숫자를 사용할 때에도 세트의 개수 계산
for i in range(10):
    if i != 6 and i != 9:
        set_count = max(set_count, digits[i])

print(set_count)
n = int(input())

s = 1  # 시작 값
e = 1  # 끝 값

cnt = 0  # 합이 n인 경우들의 개수
Sum = 0

while s <= n:  # s가 n 이하인 동안에만 반복
    if Sum == n:
        cnt += 1
        Sum -= s  # 합이 n이 되었을 때 s 값을 빼주고 s를 오른쪽으로 이동
        s += 1
    elif Sum > n:
        Sum -= s  # 합이 n보다 크면 s 값을 빼주고 s를 오른쪽으로 이동
        s += 1
    else:
        if e > n:  # e가 n보다 크면 더 이상 조건을 만족하는 경우가 없으므로 루프 종료
            break
        Sum += e
        e += 1

print(cnt)
n = int(input())
n2 = map(int, input().split())

cnt = 0
for num in n2:
    error = 0
    if num > 1 :
        for i in range(2, num):  # 2부터 n-1까지
            if num % i == 0:
                error += 1  # 2부터 n-1까지 나눈 몫이 0이면 error가 증가
        if error == 0:
            cnt += 1  # error가 없으면 소수.
print(cnt)
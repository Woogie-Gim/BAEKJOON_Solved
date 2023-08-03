# 1940 주몽

n = int(input())
m = int(input())

arr = list(map(int, input().split()))

arr.sort() # 투포인터 검색 시작 전에 리스트를 오름차순으로 정렬

s = 0  # 시작 값
e = n - 1  # 끝 값을 리스트 끝에서 시작

cnt = 0  # 합이 m인 경우들의 개수

while s < e: # 포인터가 양 끝에서 움직이고 겹치는 경우는 실행하지 않음
    if arr[s] + arr[e] < m:
        s += 1  # m보다 합이 작기 때문에 오름차순 정렬된 리스트에서 작은 값을 증가시켜야함
    elif arr[s] + arr[e] > m:
        e -= 1  # m보다 합이 작기 때문에 오름차순 정렬된 리스트에서 큰 값을 감소시켜야함
    else:
        cnt += 1
        s += 1
        e -= 1
    # 합이 m인 값을 구했으면 두개의 포인터를 동시에 이동시키고 다시 탐색 시작

print(cnt)
T = int(input())

for test_case in range(1, T + 1):
    arr = list(map(int, input().split()))
    arr.remove(test_case)
    cnt = 0
    for i in range(len(arr)-1, 0, -1):
        for j in range(0, i):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                cnt += 1

    print(f'{test_case} {cnt}')
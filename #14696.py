n = int(input())

for i in range(n):
    arr1 = list(map(int, input().split()))
    arr2 = list(map(int, input().split()))

    bucket1 = [0] * 5
    bucket2 = [0] * 5

    for j in range(len(arr1)):
        if j == 0:
            continue
        bucket1[arr1[j]] += 1

    for k in range(len(arr2)):
        if k == 0:
            continue
        bucket2[arr2[k]] += 1

    result = 0
    for l in range(4, 0, -1):
        if bucket1[l] == bucket2[l]:
            result += 1
            continue
        if bucket1[l] > bucket2[l]:
            print('A')
            break
        else:
            print('B')
            break

    if result == 4:
        print('D')
n = int(input())

arr = list(map(int, input().split()))
Min = 21e8
s = 0
e = n - 1
while s < e:
    sum = arr[s] + arr[e]
    if abs(sum) < abs(Min):
        Min = sum
    if sum < 0:
        s += 1
    else:
        e -= 1

print(Min)
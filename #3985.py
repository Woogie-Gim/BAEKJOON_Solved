n = int(input())

k = int(input())
arr = [0] * n
Max = []
Real = []
for i in range(1, k + 1):
    a, b = map(int, input().split())
    for j in range(a - 1, b):
        if arr[j] != 0:
            continue
        arr[j] = i
    Max.append((i, (b - a) + 1))


for i in range(1, k + 1):
    cnt = 0
    for j in range(len(arr)):
        if arr[j] == i:
            cnt += 1
    Real.append((i, cnt))

Maxx = -21e8
Index = 0
for i in range(k):
    if Max[i][1] > Maxx:
        Maxx = Max[i][1]
        Index = Max[i][0]

Real_Max = -21e8
Real_Index = 0
for i in range(k):
    if Real[i][1] > Real_Max:
        Real_Max = Real[i][1]
        Real_Index = Real[i][0]

print(Index)
print(Real_Index)

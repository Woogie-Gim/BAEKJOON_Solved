n = int(input())

arr = []
for _ in range(n):
    people = int(input())
    arr.append(people)

cnt = 0

while(max(arr)) != arr[0]:
    arr[arr.index(max(arr))] -= 1
    arr[0] += 1
    cnt += 1

if arr.count(max(arr)) >= 2:
    print(cnt + 1)
else:
    print(cnt)
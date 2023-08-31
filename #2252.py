from collections import deque
N, M = map(int,input().split())

students = [[] for _ in range(N + 1)]
arr = [0 for _ in range(N + 1)]
q = deque()

for i in range(M):
    x, y = map(int,input().split())
    students[x].append(y)
    arr[y] += 1

for i in range(1,N + 1):
    if arr[i] == 0:
        q.append(i)

while q:
    now = q.popleft()
    print(now, end=' ')
    for student in students[now]:
        arr[student] -= 1
        if arr[student] == 0:
            q.append(student)
print()
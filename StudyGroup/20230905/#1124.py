def abc(x):
    cnt = 0
    for i in range(2, int(x ** 0.5) + 1):
        while x % i == 0:
            cnt += 1
            x = x / i
    if x != 1:
        cnt += 1
    return cnt

a, b = map(int, input().split())

arr = [True for i in range(b + 1)]
arr[1] = False

for i in range(2, int(b ** 0.5) + 1):
    if arr[i] == True:
        j = 2
        while i * j <= b:
            arr[i * j] = False
            j += 1
            
cnt = 0
for i in range(a, b + 1):
    l = abc(i)
    if arr[l] == True:
        cnt += 1
print(cnt)

N , k = map(int, input().split())

arr = [[0,0,0,0,0,0],[0,0,0,0,0,0]]
result = 0
for i in range(N):
    S , Y = map(int, input().split())
    arr[S][Y - 1] += 1

for i in arr :
    for j in i:
        if j % k == 0:
            result += j // k
        else:
            result += (j // k) + 1
            
print(result)
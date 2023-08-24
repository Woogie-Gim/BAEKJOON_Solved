n, m = map(int, input().split())
arr = list(map(int, input().split()))

Sum = sum(arr[:m])
ans = Sum

for i in range(m, n):
    Sum += arr[i] - arr[i - m]
    ans = max(ans, Sum)

print(ans)
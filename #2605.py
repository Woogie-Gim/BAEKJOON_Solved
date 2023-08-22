n = int(input())
arr = list(map(int, input().split()))

ans = []
for i in range(len(arr)):
    ans.insert(len(ans) - arr[i], i + 1)

print(*ans)
N = int(input())
A = list(map(int, input().split()))
B, C = map(int, input().split())

ans = 0

for i in range(N):
    A[i] -= B
    ans += 1

    if A[i] > 0:
        if A[i] % C == 0:
            ans += (A[i] // C)
        else:
            ans += (A[i] // C + 1)

print(ans)
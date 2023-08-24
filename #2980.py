N, L = map(int, input().split())
car = 0
ans = 0

for i in range(N):
    D, R, G = map(int, input().split())

    ans += (D - car)
    car = D

    if ans % (R + G) <= R:
        ans += (R - (ans % (R + G)))

ans += (L - car)
print(ans)
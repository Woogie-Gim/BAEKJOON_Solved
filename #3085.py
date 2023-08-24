def eating():
    Max = 1

    for i in range(N):
        cnt = 1
        for j in range(1, N):
            if candy[i][j] == candy[i][j - 1]:
                cnt += 1
            else:
                cnt = 1

            if cnt > Max:
                Max = cnt

        cnt = 1
        for j in range(1, N):
            if candy[j][i] == candy[j - 1][i]:
                cnt += 1
            else:
                cnt = 1

            if cnt > Max:
                Max = cnt

    return Max

N = int(input())
candy = [list(input()) for _ in range(N)]
ans = 0

for i in range(N):
    for j in range(N):
        if j + 1 < N:
            candy[i][j], candy[i][j + 1] = candy[i][j + 1], candy[i][j]
            rtn = eating()
            ans = max(rtn, ans)
            candy[i][j], candy[i][j + 1] = candy[i][j + 1], candy[i][j]

        if i + 1 < N:
            candy[i][j], candy[i + 1][j] = candy[i + 1][j], candy[i][j]
            rtn = eating()
            ans = max(rtn, ans)
            candy[i][j], candy[i + 1][j] = candy[i + 1][j], candy[i][j]

print(ans)
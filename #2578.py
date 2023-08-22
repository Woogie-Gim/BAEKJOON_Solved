def bingo(num):
    global ans
    result = 0
    for i in range(5):
        for j in range(5):
            if arr[i][j] == num:
                arr[i][j] = 0

    for i in range(5):
        cnt = 0
        for j in range(5):
            if arr[j][i] == 0:
                cnt += 1
            if cnt == 5:
                result += 1


    for i in range(5):
        cnt = 0
        for j in range(5):
            if arr[i][j] == 0:
                cnt += 1
            if cnt == 5:
                result += 1

    cnt = 0
    for i in range(5):
        if arr[i][i] == 0:
            cnt += 1
        if cnt == 5:
            result += 1

    cnt = 0
    for i in range(5):
        if arr[i][4 - i] == 0:
            cnt += 1
        if cnt == 5:
            result += 1

    ans += 1
    return result


arr = [list(map(int, input().split())) for _ in range(5)]
mc = [list(map(int, input().split())) for _ in range(5)]
ans = 0
flag = 0

for i in range(5):
    if flag:
        break
    for j in range(5):
        rtn = bingo(mc[i][j])
        if rtn >= 3:
            flag = 1
            break


print(ans)
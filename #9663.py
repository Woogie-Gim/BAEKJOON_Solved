def check(x):
    for i in range(x):
        if board[x] == board[i] or abs(board[x] - board[i]) == x - i:
            return False
    return True


def dfs(x):
    global result

    if x == n:
        result += 1
    else:
        for i in range(n):
            board[x] = i
            if check(x):
                dfs(x + 1)


n = int(input())
board = [0] * n
result = 0
dfs(0)
print(result)
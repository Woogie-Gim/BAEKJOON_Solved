n = int(input())
Sum = 0
result = 0
for i in range(1, n + 1):
    Sum += i
    result += 1
    if Sum > n:
        result -= 1
        break

print(result)
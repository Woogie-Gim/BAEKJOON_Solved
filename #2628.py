n, m = map(int, input().split())
k = int(input())

row, column = [0, n], [0, m]
for i in range(k):
    a, b = map(int,input().split())
    if a == 0:
        column.append(b)
    else:
        row.append(b)
row.sort()
column.sort()

result = []
for i in range(len(row) - 1):
    for k in range(len(column) - 1):
        area = abs(row[i] - row[i + 1]) * abs(column[k] - column[k + 1])
        result.append(area)
print(max(result))
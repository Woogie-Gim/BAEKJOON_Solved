def findboss(group, x):

    if group[x] != x:
        group[x] = findboss(group, group[x])
    return group[x]


def union(group, a, b):
    a = findboss(group, a)
    b = findboss(group, b)

    if a < b:
        group[b] = a
    else:
        group[a] = b


n = int(input())
m = int(input())

group = [0] * (n + 1)

for i in range(1, n+1):
    group[i] = i

edges = []
result = 0

for _ in range(m):
    a,b,c = map(int, input().split())
    edges.append((a,b,c))

edges = sorted(edges, key=lambda x:x[2])

for e in edges:
    a, b, c = e
    if findboss(group, a) != findboss(group, b):
        union(group, a, b)
        result += c

print(result)
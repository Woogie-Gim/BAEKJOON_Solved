import sys
from collections import deque

input = sys.stdin.readline

def bfs(start):
    queue = deque([start])
    visited = [False for _ in range(n+1)]
    visited[start] = True
    count = 1

    while queue:
        v = queue.popleft()
        for i in graph[v]:
            if visited[i] == False:
                visited[i] = True
                queue.append(i)
                count += 1
    return count  

n, m = map(int, input().split())
graph = [[]for _ in range(n+1)]

for _ in range(m):
    x, y = map(int, input().split())
    graph[y].append(x) # 단방향

hack = [0 for _ in range(n+1)]  

for i in range(1, n+1):
    hack[i] = bfs(i)

max_count = max(hack)
for i in range(1, n+1):
    if max_count == hack[i]:
        print(i, end = ' ')
# 백준 16562 친구비
import sys

input = sys.stdin.readline
sys.setrecursionlimit(10000)

n, m, k = map(int, input().split()) # k는 총 예산

arr = [0] + list(map(int, input().split()))
v = [[] for i in range(n + 1)]

for i in range(m):
    a, b = map(int, input().split())

    v[a].append(b)
    v[b].append(a)

visited = [False for i in range(n + 1)]

def dfs(cur):
    ret = arr[cur] # 내가 얼마 인지
    visited[cur] = True

    for nxt in v[cur]:
        if visited[nxt]:
            continue

        ret = min(ret, dfs(nxt)) # 최소값을 출력

    return ret

ans = 0
for i in range(1, n + 1):
    if visited[i]:
        continue

    ans += dfs(i) # 연결 노드를 돌고 최소 값을 답에 더해줌

if ans <= k: # 만약 모든 예산 안에 친구를 사귄다면 ans 출력
    print(ans)
else:
    print('Oh no') # 예산에 벗어난다면 Oh no
# 2606 바이러스
n = int(input())
m = int(input())

v = [[] for i in range(n + 1)]

for i in range(m):
    s, e = map(int, input().split()) # 노드끼리의 연결을 표시

    v[s].append(e)
    v[e].append(s) # 양방향 연결이기 때문에 노드끼리의 연결을 인접리스트에 서로 표시

visited = [False for i in range(n + 1)] # 방문 표시
def dfs(now):
    visited[now] = True

    for i in v[now]:
        if visited[i]:
            continue # 방문이 되어 있다면 컨티뉴

        dfs(i)


dfs(1)

cnt = 0
for i in range(n + 1):
    if visited[i]:
        cnt += 1

print(cnt - 1) # 1번 노드를 제외하고 카운트
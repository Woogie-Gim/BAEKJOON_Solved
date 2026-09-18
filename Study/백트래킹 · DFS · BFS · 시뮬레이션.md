# 백트래킹 · DFS · BFS · 시뮬레이션 — C++

> 코딩테스트 출제 비중 최상위 4종. 이 넷을 잡으면 변별 구간이 열린다.
> 넷 다 **같은 뿌리(재귀 + 격자)** 에서 갈라진다.

---

# PART 0. 넷의 관계

```
                    재귀
                     │
        ┌────────────┼────────────┐
        │                         │
    백트래킹                    DFS
  (경우의 수 생성)          (도달 가능 확인)
        │                         │
        │                       BFS
        │                   (최단거리)
        │                         │
        └────────┬────────────────┘
                 │
             시뮬레이션
        (조건을 그대로 옮기기)
```

| 주제 | 목적 | 핵심 도구 | 복구 |
|---|---|---|---|
| 백트래킹 | 모든 경우 만들기 | 재귀 + `visited` | **함** |
| DFS | 도달 가능한 곳 전부 | 재귀 + `visited` | **안 함** |
| BFS | 최단거리 | 큐 + `visited` | 안 함 |
| 시뮬레이션 | 규칙 그대로 실행 | 격자 + 방향 배열 | — |

> **백트래킹과 DFS의 유일한 차이는 복구 여부.**
> 목적이 다르기 때문이다. 아래에서 상세히 다룸.

---

# PART 1. 백트래킹

## 1-1. 왜 재귀인가

자리 수가 고정이면 for문으로 가능하다.

```cpp
// 2자리 3진수
for (int i = 0; i < 3; i++)
{
    for (int j = 0; j < 3; j++)
    {
        cout << i << " " << j << "\n";
    }
}
```

**N자리라면 for문 N개가 필요한데, N이 입력값이면 불가능.**

> **재귀함수의 목적 = 개수를 모르는 중첩 반복문 구현**

## 1-2. 공통 뼈대

모든 백트래킹이 이 모양이다.

```cpp
void rec(int cur)
{
    if (종료 조건)
    {
        // 답 처리
        return;
    }

    for (int i = 0; i < 선택지 개수; i++)
    {
        if (가지치기 조건)
        {
            continue;
        }

        선택;
        rec(cur + 1);
        복구;               // ★ 되돌리기
    }
}
```

**템플릿 3종은 `가지치기`와 `복구` 부분만 다르다.**

## 1-3. 템플릿 #1 — 중복순열 (M^N)

같은 값을 여러 번 써도 된다. 제약 없음.

```cpp
#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> arr;

void rec(int cur)
{
    if (cur == n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= m; i++)
    {
        arr[cur] = i;
        rec(cur + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    arr.resize(n);
    rec(0);
    return 0;
}
```

n=2, m=3 → `11 12 13 21 22 23 31 32 33` (9가지)

**가지치기 없음, 복구 없음.** `arr[cur]`는 어차피 덮어써진다.

## 1-4. 템플릿 #2 — 순열 (같은 값 재사용 금지)

```cpp
int n, m;
vector<int> arr;
vector<bool> visited;

void rec(int cur)
{
    if (cur == n)
    {
        // 출력
        return;
    }

    for (int i = 1; i <= m; i++)
    {
        if (visited[i] == true)
        {
            continue;           // ← 가지치기
        }

        visited[i] = true;      // 선택
        arr[cur] = i;
        rec(cur + 1);
        visited[i] = false;     // ★ 복구
    }
}
```

n=2, m=3 → `12 13 21 23 31 32` (6가지)

### ★ 복구를 빼면 어떻게 되나

```
rec(0)에서 1 선택 → visited[1] = true
  rec(1)에서 2,3 시도하고 돌아옴
  (복구 안 함 → visited[1]은 여전히 true)
rec(0)에서 2 선택
  rec(1)에서 1을 쓰려는데 visited[1]이 true → 막힘!
```

**1은 이미 다 쓰고 돌아왔는데 흔적이 남아 영영 못 쓴다.**

> **답이 적게 나오면 복구 누락을 먼저 의심할 것.**

## 1-5. 템플릿 #3 — 조합 (순서 무시)

`1 2`와 `2 1`을 같은 것으로 본다.

```cpp
void rec(int cur, int start)
{
    if (cur == n)
    {
        // 출력
        return;
    }

    for (int i = start; i <= m; i++)    // ← 가지치기가 시작점에
    {
        arr[cur] = i;
        rec(cur + 1, i + 1);            // 다음은 i보다 큰 것만
    }
}
```

n=2, m=3 → `12 13 23` (3가지)

`visited`가 필요 없는 이유 → **항상 커지는 방향으로만 가서** 같은 값을 다시 쓸 일이 없다.

| 다음 인자 | 의미 | 결과 |
|---|---|---|
| `rec(cur+1, i+1)` | 중복 불가 (조합) | 012, 013, 023 |
| `rec(cur+1, i)` | 중복 허용 (중복조합) | 000, 001, 011, 111 |

## 1-6. 템플릿 비교표 ★

| | 가지치기 | 복구 | n=2, m=3 결과 |
|---|---|---|---|
| #1 중복순열 | 없음 | 없음 | 9가지 |
| #2 순열 | `visited[i]` | `visited[i]=false` | 6가지 |
| #3 조합 | `i = start`부터 | 없음 | 3가지 |

## 1-7. 가지치기의 정체

> **`for`가 갈림길을 펼치고, 가지치기가 그중 못 가는 길을 잘라낸다.**

두 종류가 있다.

**① 안 넣으면 답이 틀리는 것 (규칙) — 대부분 이것**

```cpp
if (visited[i] == true) { continue; }           // 같은 값 재사용 금지
if (inRange(nx, ny) == false) { continue; }     // 격자 밖
```

**문제 조건 그 자체.** 효율이 아니라 정확성의 문제.

**② 안 넣어도 답은 맞는데 느린 것 (최적화)**

```cpp
if (sum > target) { return; }       // 이미 넘었으니 볼 필요 없음
```

> **가지치기 = 탐색 공간을 정확히 정의하는 일.** 효율은 부수 효과.

가지치기 조건은 **종료 조건보다 먼저** 검사한다.

## 1-8. 2차원 백트래킹 (스도쿠 등)

**2차원이라고 재귀를 2중으로 만들지 말 것.** 1차원 인덱스로 펴면 템플릿 #1과 같아진다.

```cpp
void rec(int idx)
{
    if (idx == n * m)
    {
        // 완성
        return;
    }

    int x = idx / m;        // 행
    int y = idx % m;        // 열

    for (int val = 1; val <= 9; val++)
    {
        if (isValid(x, y, val) == false)
        {
            continue;
        }

        board[x][y] = val;
        rec(idx + 1);
        board[x][y] = 0;    // 복구
    }
}
```

## 1-9. C++ 전용 — `next_permutation`

순열이 필요하면 재귀 없이 가능.

```cpp
#include <algorithm>

sort(v.begin(), v.end());       // 반드시 정렬 후 시작

do
{
    // v를 사용
} while (next_permutation(v.begin(), v.end()));
```

| 항목 | 주의 |
|---|---|
| 정렬 | 안 하면 일부 순열 누락 |
| 반복문 | `do-while` (첫 순열도 처리해야 함) |
| 가지치기 | **불가.** 전부 생성함 |

**가지치기가 필요하면 재귀로.**

## 1-10. 설계 예시 — 프로그래머스 Lv.2 「소수 찾기」

> 숫자 조각을 붙여 만들 수 있는 모든 수 중 소수의 개수

### 4칸

```
[제약] numbers 길이 1~7 → 최대 7자리(999만). int OK
       중복 숫자 가능("011") → 같은 수 중복 생성 주의
[상태] cur(만든 자릿수), num(만든 수)
[전이] 안 쓴 조각을 뒤에 붙임 → num * 10 + digit
[가지치기] visited[i] 인 조각은 건너뜀
[종료] 매 단계마다 num 기록. cur == 길이면 반환
```

**설계에서 발견되는 것 2가지**
- 종료 조건이 특이 — 1자리도 답이 될 수 있으니 **매 단계마다 검사**
- 중복 제거 필요 — `"011"`이면 같은 수가 두 번 만들어짐 → `set` 사용

### 전체 코드 — 예시) 프로그래머스 Lv.2 소수 찾기

```cpp
#include <string>
#include <vector>
#include <set>

using namespace std;

set<int> made;
vector<bool> visited;
string paper;

// 소수 판정. 제곱근까지만
bool isPrime(int n)
{
    if (n < 2)
    {
        return false;
    }

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

void rec(int cur, int num)
{
    if (cur > 0)
    {
        made.insert(num);       // 기록을 먼저
    }

    if (cur == (int)paper.size())
    {
        return;                 // 종료 검사를 나중에
    }

    for (int i = 0; i < (int)paper.size(); i++)
    {
        if (visited[i] == true)
        {
            continue;
        }

        visited[i] = true;
        rec(cur + 1, num * 10 + (paper[i] - '0'));
        visited[i] = false;     // 복구
    }
}

int solution(string numbers)
{
    paper = numbers;
    made.clear();
    visited.assign(numbers.size(), false);

    rec(0, 0);

    int answer = 0;
    for (set<int>::iterator it = made.begin(); it != made.end(); it++)
    {
        if (isPrime(*it) == true)
        {
            answer++;
        }
    }
    return answer;
}
```

**`num * 10 + digit`** — 수를 뒤에 붙이는 관용구. 문자열 변환 불필요.

---

# PART 2. DFS

## 2-1. 정체

> **한 방향으로 끝까지 파고들었다가 막히면 돌아온다**

## 2-2. 백트래킹과의 결정적 차이

```cpp
// 백트래킹: 복구함
visited[i] = true;
rec(cur + 1);
visited[i] = false;     // ← 되돌림

// DFS: 복구 안 함
visited[x][y] = true;
dfs(nx, ny);
// 복구 없음
```

| | 목적 | 복구 |
|---|---|---|
| 백트래킹 | 모든 경우를 **만들어야** 함 → 다음 경우를 위해 되돌림 | **함** |
| DFS | 한 번 간 곳은 **다시 갈 필요 없음** | 안 함 |

## 2-3. 격자 DFS 뼈대

```cpp
#include <iostream>

using namespace std;

int n, m;
int board[105][105];
bool visited[105][105];

int dx[4] = {-1, 1, 0, 0};      // 상 하 좌 우
int dy[4] = {0, 0, -1, 1};

bool inRange(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < m);
}

void dfs(int x, int y)
{
    visited[x][y] = true;

    for (int d = 0; d < 4; d++)
    {
        int nx = x + dx[d];
        int ny = y + dy[d];

        if (inRange(nx, ny) == false) { continue; }     // 격자 밖
        if (visited[nx][ny] == true) { continue; }      // 이미 감
        if (board[nx][ny] == 0) { continue; }           // 갈 수 없는 칸

        dfs(nx, ny);
    }
}
```

### 세 줄 가지치기의 정체

| 줄 | 정체 | 언제 바뀌나 |
|---|---|---|
| `inRange` | 격자 경계 | 거의 안 바뀜 |
| `visited` | **탐색 공간 정의** | **상태가 늘면 차원도 늘어남** |
| `board == 0` | 문제 규칙 | 문제마다 다름 |

**두 번째 줄이 핵심.** PART 4에서 다룸.

## 2-4. ★ 핵심 패턴 — 덩어리 세기

```cpp
int cnt = 0;

for (int i = 0; i < n; i++)
{
    for (int j = 0; j < m; j++)
    {
        if (board[i][j] == 1 && visited[i][j] == false)
        {
            cnt++;              // 새 덩어리 발견
            dfs(i, j);          // 이 덩어리 전부 방문 처리
        }
    }
}
```

**바깥 루프가 새 덩어리를 찾고, DFS가 그 덩어리를 통째로 지운다.**

섬 개수, 단지 번호, 유기농 배추, 네트워크 전부 이 패턴.

### 덩어리 크기까지 세려면

```cpp
int dfs(int x, int y)
{
    visited[x][y] = true;
    int size = 1;               // 자기 자신

    for (int d = 0; d < 4; d++)
    {
        int nx = x + dx[d];
        int ny = y + dy[d];

        if (inRange(nx, ny) == false) { continue; }
        if (visited[nx][ny] == true) { continue; }
        if (board[nx][ny] == 0) { continue; }

        size = size + dfs(nx, ny);      // 하위 결과를 누적
    }

    return size;
}
```

## 2-5. 설계 예시 — 프로그래머스 Lv.3 「네트워크」

### 4칸

```
[제약] n은 1~200. computers는 n×n 인접 행렬
[상태] 현재 컴퓨터 번호 (좌표 아님)
[전이] computers[now][i] == 1 인 i로 이동
[가지치기] 이미 방문한 컴퓨터
[종료] 연결된 곳 다 돌면 자동 종료
```

**격자가 아니라 인접 행렬.** `dx`, `dy`가 필요 없다.

### 전체 코드 — 예시) 프로그래머스 Lv.3 네트워크

```cpp
#include <vector>

using namespace std;

vector<bool> visited;

void dfs(int now, vector<vector<int>>& computers)
{
    visited[now] = true;

    for (int i = 0; i < (int)computers.size(); i++)
    {
        if (visited[i] == true) { continue; }
        if (computers[now][i] == 0) { continue; }

        dfs(i, computers);
    }
}

int solution(int n, vector<vector<int>> computers)
{
    visited.assign(n, false);
    int answer = 0;

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            answer++;
            dfs(i, computers);
        }
    }

    return answer;
}
```

`&`(참조)로 넘기는 이유 → 복사 비용 절약. 200×200이면 복사가 무겁다.

## 2-6. 주의 — 스택 오버플로우

재귀 깊이가 만 단위로 가면 위험하다. 격자 1000×1000이면 최악의 경우 100만 깊이.

**그런 경우 BFS로 바꾸거나 반복문 DFS(스택)를 쓴다.**

---

# PART 3. BFS

## 3-1. 정체

> **가까운 곳부터 차례로 퍼져나간다**

## 3-2. 왜 최단거리인가

가까운 곳부터 퍼지므로 **어떤 칸에 처음 도달한 순간이 곧 최단거리.** 나중에 다른 경로로 와도 더 길 수밖에 없다.

DFS는 한 방향으로 끝까지 가버려서 **먼 길로 먼저 도착할 수 있다.**

> **최단거리 · 최소 횟수 = 무조건 BFS**

## 3-3. 뼈대

```cpp
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int bfs(int sx, int sy)
{
    queue<pair<int, int>> q;

    q.push({sx, sy});
    dist[sx][sy] = 1;               // 방문 표시 겸 거리

    while (q.empty() == false)
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int d = 0; d < 4; d++)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (inRange(nx, ny) == false) { continue; }
            if (dist[nx][ny] != -1) { continue; }       // 이미 방문
            if (board[nx][ny] == 0) { continue; }

            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});                            // ★ 넣을 때 표시
        }
    }

    return dist[n - 1][m - 1];
}
```

## 3-4. ★ 방문 표시 시점

```cpp
// 맞음: 큐에 넣을 때
dist[nx][ny] = dist[x][y] + 1;
q.push({nx, ny});

// 틀림: 꺼낼 때
q.pop();
dist[x][y] = ...;
```

꺼낼 때 표시하면 어떤 칸이 큐에 들어간 뒤 처리되기 전에 **다른 경로에서 또 들어온다.** 큐가 폭발한다.

## 3-5. `dist` 하나로 두 역할

```cpp
vector<vector<int>> dist(n, vector<int>(m, -1));
```

`-1`이면 미방문, 아니면 방문 + 그 거리. **`visited` 배열을 따로 안 만들어도 된다.**

도달 못 하면 `-1`이 그대로 남아 자동으로 실패 처리된다.

## 3-6. 설계 예시 — 프로그래머스 Lv.2 「게임 맵 최단거리」

### 4칸

```
[제약] n, m은 1~100. 벽(0)과 길(1)
       최단거리 → BFS 확정
[상태] (x, y) 좌표만. 추가 조건 없음 → visited 2차원
[전이] 사방 이동
[가지치기] 격자 밖 / 이미 방문 / 벽
[종료] 큐 빌 때까지. dist[n-1][m-1] 반환 (못 갔으면 -1)
```

### 전체 코드 — 예시) 프로그래머스 Lv.2 게임 맵 최단거리

```cpp
#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> maps)
{
    int n = (int)maps.size();
    int m = (int)maps[0].size();

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int, int>> q;

    q.push({0, 0});
    dist[0][0] = 1;                 // 시작 칸도 1칸으로 셈

    while (q.empty() == false)
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int d = 0; d < 4; d++)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) { continue; }
            if (dist[nx][ny] != -1) { continue; }
            if (maps[nx][ny] == 0) { continue; }

            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }

    return dist[n - 1][m - 1];
}
```

## 3-7. 다중 시작점 BFS

시작점이 여러 개면 **전부 큐에 먼저 넣고** 시작한다.

```cpp
queue<pair<int, int>> q;

for (int i = 0; i < n; i++)
{
    for (int j = 0; j < m; j++)
    {
        if (board[i][j] == 1)       // 시작점 조건
        {
            q.push({i, j});
            dist[i][j] = 0;
        }
    }
}

// 이후는 평소 BFS와 동일
```

**동시에 퍼지는 효과.** 각 칸은 가장 가까운 시작점으로부터의 거리를 갖는다.

한 번에 하나씩 BFS를 돌리면 틀린다. 순서대로가 아니라 동시이기 때문.

토마토, 불과 탈출, 인구 이동 등에 쓰인다.

## 3-8. DFS vs BFS 선택 기준 ★

| | DFS | BFS |
|---|---|---|
| 구현 | 재귀 | 큐 |
| 최단거리 | **못 씀** | **필수** |
| 덩어리 세기 | 편함 | 가능 |
| 모든 경로 탐색 | 편함 | 불편 |
| 깊이 문제 | 스택 오버플로우 위험 | 안전 |

> **"최단" · "최소 횟수" · "몇 번 만에" → BFS**
> **"몇 개" · "가능한가" · "모든 경로" → DFS**

---

# PART 4. 상태 설계 ★ 가장 중요

## 4-1. 오늘의 질문

> **같은 칸에 다른 조건으로 다시 올 수 있는가?**

올 수 있으면 그 조건을 **상태에 넣고** `visited` 차원을 늘린다.

## 4-2. 왜 2차원으로 부족한가

**벽을 한 번 부술 수 있는 최단거리** 문제.

```
경로 A: 벽 0개 부수고 (3,3) 도착 → visited[3][3] = true
경로 B: 벽 1개 부수고 (3,3) 도착 → 이미 방문! → 막힘
```

**A는 앞으로 벽을 부술 기회가 남아 있고 B는 없다.** 완전히 다른 상황인데 같은 칸이라고 막아버린다.

> **좌표만으로는 상태를 구분할 수 없다.**

## 4-3. 해결 — 차원 추가

```cpp
int dist[105][105][2];
//        x    y   b
//                 └─ 벽 부순 횟수 (0 또는 1)
```

`dist[3][3][0]`과 `dist[3][3][1]`이 따로 관리된다. **벽 상태가 다르면 다른 칸 취급.**

## 4-4. 전체 코드 — 예시) 벽 부수고 이동하기

```cpp
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
int board[105][105];
int dist[105][105][2];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// [상태]     (x, y, b) — b는 벽 부순 횟수 0 또는 1
// [전이]     사방 이동. 벽이면 b+1 층으로 이동
// [가지치기] 격자 밖 / 같은 b 상태로 이미 방문 / b가 1인데 또 벽
// [종료]     도착 시 거리 반환 / 큐 비면 -1

int bfs()
{
    queue<vector<int>> q;       // {x, y, b}

    q.push({0, 0, 0});
    dist[0][0][0] = 1;

    while (q.empty() == false)
    {
        int x = q.front()[0];
        int y = q.front()[1];
        int b = q.front()[2];
        q.pop();

        if (x == n - 1 && y == m - 1)
        {
            return dist[x][y][b];
        }

        for (int d = 0; d < 4; d++)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) { continue; }

            if (board[nx][ny] == 0)         // 빈 칸
            {
                if (dist[nx][ny][b] != 0) { continue; }
                dist[nx][ny][b] = dist[x][y][b] + 1;
                q.push({nx, ny, b});
            }
            else                             // 벽
            {
                if (b == 1) { continue; }    // 이미 한 번 부숨
                if (dist[nx][ny][1] != 0) { continue; }
                dist[nx][ny][1] = dist[x][y][b] + 1;
                q.push({nx, ny, 1});
            }
        }
    }

    return -1;
}
```

**벽을 만나면 `b`가 1로 바뀌며 다른 층으로 넘어간다.** `b=0` 층에서 `b=1` 층으로.

## 4-5. 상태 판단표 ★

| 문제 상황 | 상태 | visited |
|---|---|---|
| 그냥 최단거리 | (x, y) | 2차원 |
| 벽 1번 부수기 | (x, y, 부순 횟수) | **3차원 [2]** |
| 열쇠 모으기 (6종) | (x, y, 열쇠 비트마스크) | **3차원 [64]** |
| 낮/밤 구분 이동 | (x, y, 시간 홀짝) | **3차원 [2]** |
| 방향에 따라 비용 다름 | (x, y, 방향) | **3차원 [4]** |
| 말과 도보 이동 | (x, y, 말 사용 횟수) | **3차원** |

**패턴: "좌표 말고 뭐가 더 변하는가"**

## 4-6. 상태가 좌표가 아닌 경우

BFS는 격자 전용이 아니다.

| 문제 | 상태 |
|---|---|
| 단어 변환 | **단어 문자열** |
| 숫자 변환 (연산으로 목표 만들기) | **현재 숫자** |
| 그래프 최단 경로 | **정점 번호** |

**"한 상태에서 다른 상태로 한 번에 갈 수 있는가"** 만 정의되면 BFS를 쓸 수 있다.

---

# PART 5. 시뮬레이션

## 5-1. 정체

> **알고리즘이 아니라 받아쓰기.**
> 문제에 적힌 규칙을 빠짐없이 코드로 옮기는 것.

어려운 이유는 기법이 아니라 **조건이 여러 겹 쌓이기 때문.**

## 5-2. ★ 필승법 — 조건 목록화

코드 치기 전 주석으로 조건을 **전부** 나열한다.

```cpp
// [조건 목록]
// 1. 현재 칸이 청소 안 됐으면 청소
// 2. 주변 4칸 중 청소 안 된 빈 칸이 없으면
//    2-1. 뒤로 후진 가능하면 후진 후 1번으로
//    2-2. 후진 불가(벽)면 종료
// 3. 주변에 청소 안 된 빈 칸이 있으면
//    3-1. 반시계 90도 회전
//    3-2. 앞이 청소 안 된 빈 칸이면 전진
//    3-3. 1번으로
```

> **막히는 이유는 조건을 코딩하면서 발견하기 때문.**
> 먼저 다 꺼내놓으면 막힐 일이 없다.

**조건 하나 = 함수 하나** 로 쪼개면 디버깅이 쉬워진다.

## 5-3. 격자 뼈대 (재확인)

```cpp
int n, m;
int board[105][105];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool inRange(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < m);
}
```

## 5-4. 방향 전환 ★

**회전이 있는 문제면 `dx`, `dy`를 시계 순서로 배치한다.**

```cpp
// 북 동 남 서 (시계 순서)
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

dir = (dir + 1) % 4;        // 시계 90도
dir = (dir + 3) % 4;        // 반시계 90도
dir = (dir + 2) % 4;        // 180도 반전
```

### ★ `dir - 1` 쓰면 안 되는 이유

```cpp
(0 - 1) % 4 == -1           // C++의 % 는 음수를 반환
```

배열 인덱스로 쓰면 즉시 범위 초과. **반드시 `+3`을 쓸 것.**

## 5-5. 전체 코드 — 예시) 로봇 청소기형 시뮬레이션

```cpp
#include <iostream>

using namespace std;

int n, m;
int room[55][55];           // 0=빈칸, 1=벽, 2=청소함

// 북 동 남 서 (시계 순서)
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool inRange(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < m);
}

int clean(int sx, int sy, int sd)
{
    int cnt = 0;
    int x = sx;
    int y = sy;
    int d = sd;

    while (true)
    {
        // 조건 1. 현재 칸 청소
        if (room[x][y] == 0)
        {
            room[x][y] = 2;
            cnt++;
        }

        // 조건 3. 반시계로 돌며 청소 가능한 칸 찾기
        bool moved = false;
        for (int k = 0; k < 4; k++)
        {
            d = (d + 3) % 4;

            int nx = x + dx[d];
            int ny = y + dy[d];

            if (inRange(nx, ny) == false) { continue; }
            if (room[nx][ny] != 0) { continue; }

            x = nx;
            y = ny;
            moved = true;
            break;
        }

        // 조건 2. 못 찾으면 후진
        if (moved == false)
        {
            int bx = x - dx[d];
            int by = y - dy[d];

            if (inRange(bx, by) == false) { break; }
            if (room[bx][by] == 1) { break; }       // 벽이면 종료

            x = bx;
            y = by;
        }
    }

    return cnt;
}
```

**4바퀴 다 돌면 `d`가 원위치로 돌아온다** (`(d+3)%4`를 4번 = 360도). 그래서 후진할 때 원래 방향 기준이 유지된다.

## 5-6. 격자 회전 (90도)

```cpp
// 원본 board(n×m) → 결과 rotated(m×n)
for (int i = 0; i < n; i++)
{
    for (int j = 0; j < m; j++)
    {
        rotated[j][n - 1 - i] = board[i][j];
    }
}
```

**행과 열 크기가 뒤바뀐다.** n×m → m×n

## 5-7. 원형 배열

```cpp
// 방법 1. 뒤에 이어붙이기 (권장. 실수 적음)
for (int i = 0; i < k - 1; i++)
{
    belt.push_back(belt[i]);
}

// 방법 2. 모듈러 (메모리 절약)
int idx = (i + j) % n;
```

**시험장에서는 방법 1.** 인덱스 계산 실수가 안 나온다.

## 5-8. 동시 변화 — 상태 복사 ★

```cpp
// 틀림. 앞에서 바꾼 값이 뒤 계산에 영향
for (int i = 0; i < n; i++)
{
    for (int j = 0; j < m; j++)
    {
        board[i][j] = calc(i, j);
    }
}

// 맞음. 새 배열에 쓰고 마지막에 교체
int next[105][105];
for (int i = 0; i < n; i++)
{
    for (int j = 0; j < m; j++)
    {
        next[i][j] = calc(i, j);
    }
}
// board = next 로 복사
```

**생명 게임, 확산, 인구 이동처럼 동시에 변하는 문제는 무조건 새 배열 사용.**

---

# PART 6. 설계 4칸

```cpp
// [제약]     입력 크기와 값의 범위. 자료형 확인
// [상태]     무엇을 들고 다니는가?
// [전이]     다음으로 어떻게 가는가?
// [가지치기] 언제 안 가는가?
// [종료]     언제 끝나고 무엇을 하는가?
```

## 칸별 핵심 질문

| 칸 | 질문 |
|---|---|
| [제약] | N이 몇까지? 경우의 수가 1억 넘는가? 오버플로우? |
| [상태] | **같은 위치에 다른 조건으로 다시 올 수 있는가?** |
| [전이] | 사방 이동? 값 선택? 규칙 적용? |
| [가지치기] | 범위 밖 / 이미 방문 / 조건 초과 / 벽 |
| [종료] | 성공 조건과 **실패 조건 둘 다** |

> **4칸이 안 채워지면 코드 한 줄도 치지 말 것.**
> 안 채워진다 = 문제를 덜 이해했다는 신호.

## 틀렸을 때

**코드를 노려보지 말고 4칸으로 돌아간다.** 대개 조건 하나를 안 적어둔 게 원인.

---

# PART 7. C++ 체크리스트

## 공통

- [ ] **배열 초기화** — 지역 배열은 `= {0}`. 전역은 자동 0
- [ ] **범위 초과** — C++는 에러를 안 냄. `inRange` 먼저 호출
- [ ] **`size()` 캐스팅** — 부호 없는 정수. `(int)` 붙일 것
- [ ] **오버플로우** — N × 최대값 > 21억이면 `long long`

## 백트래킹

- [ ] **`visited[i] = false` 복구** — 빠뜨리면 답이 적게 나옴
- [ ] **가지치기를 종료 조건보다 먼저**
- [ ] **`next_permutation`은 정렬 후 `do-while`**

## DFS / BFS

- [ ] **BFS 방문 표시는 큐에 넣을 때**
- [ ] **최단거리는 무조건 BFS**
- [ ] **상태가 늘면 `visited` 차원도 늘림**
- [ ] **재귀 깊이 만 단위면 DFS 대신 BFS**

## 시뮬레이션

- [ ] **`(dir + 3) % 4`** — `dir - 1`은 음수
- [ ] **회전 문제면 `dx`, `dy`를 시계 순서로**
- [ ] **동시 변화면 새 배열에 쓰고 교체**
- [ ] **조건 목록을 주석으로 먼저 나열**

---

# PART 8. 예시 문제 (난이도 순)

## STEP 1 — 백트래킹 기초

| 문제 | 출처 | 템플릿 |
|---|---|---|
| 모의고사 | 프로그래머스 Lv.1 | 완전탐색 몸풀기 |
| 카펫 | 프로그래머스 Lv.2 | 완전탐색 |
| 소수 찾기 | 프로그래머스 Lv.2 | #2 순열 + `set` |
| 피로도 | 프로그래머스 Lv.2 | #2 순열 |
| 타겟 넘버 | 프로그래머스 Lv.2 | 이진 선택 (DFS 다리) |

## STEP 2 — DFS 기초

| 문제 | 출처 | 포인트 |
|---|---|---|
| 네트워크 | 프로그래머스 Lv.3 | 덩어리 세기 |
| 여행경로 | 프로그래머스 Lv.3 | DFS + 정렬 |
| 단어 변환 | 프로그래머스 Lv.3 | **상태가 문자열** |

## STEP 3 — BFS 기초

| 문제 | 출처 | 포인트 |
|---|---|---|
| 게임 맵 최단거리 | 프로그래머스 Lv.2 | 격자 최단거리 기본형 |
| 미로 탈출 | 프로그래머스 Lv.2 | 구간 나눠 BFS 두 번 |
| 아이템 줍기 | 프로그래머스 Lv.3 | 좌표 2배 확대 트릭 |

## STEP 4 — 상태 설계 ★

| 문제 | 출처 | 상태 |
|---|---|---|
| 경주로 건설 | 프로그래머스 Lv.3 | **(x, y, 방향)** |
| 등굣길 | 프로그래머스 Lv.3 | DP + 격자 |

## STEP 5 — 시뮬레이션 (조건 겹침)

| 문제 | 출처 | 겹친 조건 |
|---|---|---|
| 방문 길이 | 프로그래머스 Lv.2 | 좌표 + 중복 경로 판정 |
| 자물쇠와 열쇠 | 프로그래머스 Lv.3 | 격자 회전 + 이동 |
| 신규 아이디 추천 | 프로그래머스 Lv.1 | **7단계 규칙 순차 적용** |
| 오픈채팅방 | 프로그래머스 Lv.2 | `map` + 최종 상태 반영 |
| 괄호 변환 | 프로그래머스 Lv.2 | 재귀 + 문자열 규칙 |

---

# PART 9. 세 줄 요약

1. **백트래킹과 DFS의 차이는 복구뿐.** 목적이 다르기 때문
2. **최단거리는 무조건 BFS.** 방문 표시는 큐에 넣을 때
3. **상태 설계가 전부.** "같은 칸에 다른 조건으로 올 수 있는가"를 먼저 물을 것
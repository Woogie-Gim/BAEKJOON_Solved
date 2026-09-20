# 우선순위 큐 · DP 웰노운 — C++

> **PQ는 필수** — 출제 이력 확인됨. 30분이면 습득 가능
> **DP는 여유분** — 출제 근거 약함. 정의 세우기 훈련 위주로

---

# PART 1. 우선순위 큐 (Priority Queue)

## 1-1. 정체

> **항상 "최우선" 원소가 맨 위에 있는 자료구조**

내부는 힙(heap). 넣고 빼는 게 O(log N), 최우선 원소 확인은 O(1).

## 1-2. 왜 필요한가 — 구현으로 우회 불가

"매번 최댓값 꺼내고 다시 넣기"를 배열로 하면

| 방법 | 복잡도 |
|---|---|
| 매번 정렬 | O(N² log N) |
| 매번 최댓값 탐색 | O(N²) |
| **우선순위 큐** | **O(N log N)** |

**기법이 아니라 자료구조라 구현력으로 대체가 안 된다.** 모르면 시간 초과.

## 1-3. 선언 — 두 가지만 외울 것

```cpp
#include <queue>
#include <vector>

using namespace std;

priority_queue<int> maxHeap;                            // 최대힙 (기본)
priority_queue<int, vector<int>, greater<int>> minHeap; // 최소힙
```

> **기본이 최대힙이다.** 최소힙이 필요하면 긴 선언을 쓸 것.

최소힙 선언이 길어서 헷갈리면 순서로 외운다. **타입 → 담을 컨테이너 → 비교자**

## 1-4. 함수

| 함수 | 동작 | 복잡도 |
|---|---|---|
| `pq.push(x)` | 넣기 | O(log N) |
| `pq.pop()` | 최우선 제거 (**값 반환 안 함**) | O(log N) |
| `pq.top()` | 최우선 값 확인 | O(1) |
| `pq.size()` | 개수 | O(1) |
| `pq.empty()` | 비었는가 | O(1) |

### ★ 주의

```cpp
int x = pq.top();       // 값을 먼저 읽고
pq.pop();               // 그 다음 제거
```

`pop()`은 값을 돌려주지 않는다. **빈 큐에 `top()` 호출하면 런타임 에러.**

## 1-5. pair 넣기

```cpp
priority_queue<pair<int, int>> pq;                  // first 기준 최대힙

priority_queue<pair<int, int>,
               vector<pair<int, int>>,
               greater<pair<int, int>>> pq;         // first 기준 최소힙
```

**`first` 기준으로 먼저, 같으면 `second` 기준으로** 정렬된다. 정렬 기준이 될 값을 `first`에 넣는 게 관용구.

```cpp
pq.push({비용, 번호});      // 비용 기준 정렬
```

## 1-6. 구조체 넣기 (람다 없이)

```cpp
#include <queue>
#include <vector>

using namespace std;

struct Job
{
    int start;
    int len;
};

// 비교 함수 구조체
struct JobCmp
{
    bool operator()(const Job& a, const Job& b)
    {
        return a.len > b.len;       // len 작은 것이 먼저
    }
};

priority_queue<Job, vector<Job>, JobCmp> pq;
```

### ★ 부등호 방향이 `sort`와 반대

| | `sort` 비교 함수 | `priority_queue` 비교자 |
|---|---|---|
| 오름차순 (작은 것 먼저) | `a < b` | **`a > b`** |
| 내림차순 (큰 것 먼저) | `a > b` | **`a < b`** |

**헷갈리면 이렇게 기억:** `priority_queue`의 비교자는 "우선순위가 **낮은** 것"을 판별한다. `sort`와 반대로 쓰면 된다.

## 1-7. 전체 코드 — 예시) 프로그래머스 Lv.2 더 맵게

> 모든 음식의 스코빌 지수를 K 이상으로 만들려면 최소 몇 번 섞어야 하나
> 섞기 = 가장 안 매운 것 + 두 번째로 안 매운 것 × 2

```cpp
#include <vector>
#include <queue>

using namespace std;

// [제약] scoville 길이 2~1,000,000 → O(N log N) 필요
//        값이 0~1,000,000 이고 섞으면 커짐 → 오버플로우 주의
// [처리] 최소힙에서 두 개 꺼내 섞고 다시 넣기를 반복
// [반환] 섞은 횟수. 불가능하면 -1

int solution(vector<int> scoville, int K)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < (int)scoville.size(); i++)
    {
        pq.push(scoville[i]);
    }

    int cnt = 0;

    // 가장 안 매운 것이 K 미만인 동안 계속
    while (pq.size() >= 2 && pq.top() < K)
    {
        int a = pq.top();
        pq.pop();

        int b = pq.top();
        pq.pop();

        pq.push(a + b * 2);
        cnt++;
    }

    if (pq.top() >= K)
    {
        return cnt;
    }
    return -1;
}
```

### 설계 포인트

**`while` 조건이 두 개**다. 개수가 2개 이상이면서 최솟값이 K 미만일 때만 섞는다. 하나라도 빠지면 틀린다.

- 개수 조건 없으면 → 1개 남았을 때 `top()` 두 번 호출해서 터짐
- 최솟값 조건 없으면 → 이미 다 K 이상인데 계속 섞음

**최소힙을 쓰는 이유** — 가장 안 매운 것부터 섞어야 최소 횟수가 나온다.

## 1-8. 언제 쓰나 — 신호

- "가장 큰/작은 것을 반복해서 꺼낸다"
- "매번 최우선 작업을 처리한다"
- "상위 K개를 구한다"
- **다익스트라** (최단 경로)

## 1-9. 대표 문제

| 문제 | 출처 | 포인트 |
|---|---|---|
| 더 맵게 | 프로그래머스 Lv.2 | 최소힙 기본형 |
| 이중우선순위큐 | 프로그래머스 Lv.3 | 최대·최소 둘 다 필요 |
| 디스크 컨트롤러 | 프로그래머스 Lv.3 | 시간 순 + 작업 길이 |

**이중우선순위큐 팁** — 최대힙과 최소힙을 동시에 유지하거나 `multiset`을 쓴다.

---

# PART 2. DP

## 2-1. 핵심은 하나

> **`dp[i]`가 무엇을 의미하는지 한 문장으로 정의하기**

이게 되면 점화식은 대개 따라 나온다. 안 되면 아무것도 안 된다.

**점화식을 외우는 게 아니라 정의에서 유도하는 것.**

## 2-2. 설계 3단계

```
1. dp[i] 정의     ← "dp[i]는 ___이다"
2. 점화식 도출     ← 정의에서 자동으로 나옴
3. 구현 방식 선택   ← 상향식(반복문) or 하향식(재귀+메모)
```

**1번이 8할.** 2번은 따라오고, 3번은 상향식 하나만 알아도 된다.

## 2-3. 상향식 vs 하향식

| | 상향식 (반복문) | 하향식 (재귀 + 메모) |
|---|---|---|
| 방향 | 작은 것부터 채움 | 큰 것에서 쪼갬 |
| 장점 | 빠름. 스택 안전 | 필요한 것만 계산 |
| 단점 | 전부 계산 | 깊이 크면 스택 오버플로우 |
| 코테 | **기본** | 재귀가 자연스러울 때 |

**같은 점화식의 다른 구현.** 결과는 동일.

```cpp
// 하향식
memo[n] = fibo(n-1) + fibo(n-2);

// 상향식
dp[i] = dp[i-1] + dp[i-2];
```

> **재귀 깊이가 만 단위로 갈 것 같으면 상향식.**

---

# PART 3. DP 웰노운 5종

## 3-1. 계단형 — 경우의 수 세기

### 정의
> `dp[i]` = i번째 칸에 도달하는 **경우의 수**

### 유도
i에 오는 방법은 i-1에서 한 칸, i-2에서 두 칸. 그래서 둘을 더한다.

```
dp[i] = dp[i-1] + dp[i-2]
```

### 전체 코드 — 예시) 2×n 타일링

```cpp
#include <vector>

using namespace std;

// [제약] n 1~60,000 → long long 또는 모듈러
// [정의] dp[i] = 2×i 크기를 채우는 방법의 수
// [점화] dp[i] = dp[i-1] + dp[i-2]
//        (세로 1개 추가) 또는 (가로 2개 추가)
// [초기] dp[1] = 1, dp[2] = 2

int solution(int n)
{
    const int MOD = 1000000007;

    vector<int> dp(n + 2, 0);
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }

    return dp[n];
}
```

n=1~6 → `1 2 3 5 8 13` (피보나치)

**같은 계열:** 계단 오르기, 2×n 타일링, 1·2·3 더하기, 이친수

## 3-2. 동전형 — 최소 개수

### 정의
> `dp[i]` = 금액 i를 만드는 **최소 동전 개수**

### 유도
i를 만들려면 마지막에 어떤 동전을 놓았는지 따진다. 그 동전을 빼기 전 상태가 `dp[i - 동전]`.

```
dp[i] = min(dp[i - coin]) + 1
```

### 전체 코드

```cpp
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// [정의] dp[i] = 금액 i를 만드는 최소 동전 개수
// [점화] dp[i] = min(dp[i - coin] + 1) for all coin
// [초기] dp[0] = 0, 나머지는 INT_MAX (불가능 표시)

int solution(int target, vector<int> coins)
{
    vector<int> dp(target + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= target; i++)
    {
        for (int j = 0; j < (int)coins.size(); j++)
        {
            if (i < coins[j]) { continue; }             // 동전이 더 큼
            if (dp[i - coins[j]] == INT_MAX) { continue; }  // ★ 불가능한 상태

            dp[i] = min(dp[i], dp[i - coins[j]] + 1);
        }
    }

    if (dp[target] == INT_MAX)
    {
        return -1;
    }
    return dp[target];
}
```

### ★ 두 가지 함정

**1. `INT_MAX + 1` 오버플로우**

```cpp
if (dp[i - coins[j]] == INT_MAX) { continue; }
```

이 줄이 없으면 `INT_MAX + 1`이 되어 **음수로 뒤집힌다.** 그러면 `min`이 엉뚱한 값을 고른다.

**2. 그리디로 풀면 반례가 나온다**

동전 `{1, 5, 6, 8}`로 11을 만들 때
- 그리디 (큰 것부터): 8 + 1 + 1 + 1 = **4개**
- 정답 (DP): 5 + 6 = **2개**

큰 동전을 먼저 쓰는 게 항상 최적이 아니다. **동전 단위가 배수 관계가 아니면 그리디 불가.**

**같은 계열:** 설탕 배달(3kg, 5kg), 1로 만들기, 정수 삼각형 변형

## 3-3. 배낭 (0/1 Knapsack)

### 정의
> `dp[i][c]` = i번째 물건까지 고려하고 용량이 c일 때 **최대 가치**

### 유도
각 물건마다 **넣거나 안 넣거나** 두 선택지.

```
안 넣음: dp[i-1][c]
넣음:   dp[i-1][c - 무게] + 가치
→ 둘 중 큰 값
```

### 전체 코드

```cpp
#include <vector>
#include <algorithm>

using namespace std;

// [정의] dp[i][c] = i번째까지 고려, 용량 c일 때 최대 가치
// [점화] dp[i][c] = max(안 넣음, 넣음)
// [초기] dp[0][*] = 0

int solution(int cap, vector<int> w, vector<int> v)
{
    int n = (int)w.size();
    vector<vector<int>> dp(n + 1, vector<int>(cap + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int c = 0; c <= cap; c++)
        {
            dp[i][c] = dp[i - 1][c];            // 안 넣음

            if (c >= w[i - 1])                   // 넣을 수 있으면
            {
                dp[i][c] = max(dp[i][c], dp[i - 1][c - w[i - 1]] + v[i - 1]);
            }
        }
    }

    return dp[n][cap];
}
```

**인덱스 주의:** `dp`는 1부터, 배열 `w`, `v`는 0부터. 그래서 `w[i-1]`.

## 3-4. LIS — 가장 긴 증가 부분 수열

### 정의
> `dp[i]` = i번째 원소로 **끝나는** 증가 수열의 최대 길이

**"끝나는"이 핵심.** "i번째까지의 최대"로 정의하면 점화식이 안 나온다.

### 유도
앞의 모든 j 중 `a[j] < a[i]`인 것들의 `dp[j]` 최댓값 + 1.

### 전체 코드

```cpp
#include <vector>
#include <algorithm>

using namespace std;

// [제약] O(N²). N이 10만 넘으면 이분탐색 버전 필요
// [정의] dp[i] = i번째로 끝나는 증가 수열의 최대 길이
// [점화] dp[i] = max(dp[j]) + 1  where j < i and a[j] < a[i]
// [초기] 전부 1 (자기 자신만)

int solution(vector<int> a)
{
    int n = (int)a.size();
    vector<int> dp(n, 1);
    int best = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        best = max(best, dp[i]);
    }

    return best;
}
```

**답은 `dp[n-1]`이 아니라 `dp` 전체의 최댓값.** 마지막 원소로 끝나는 게 가장 길다는 보장이 없다.

## 3-5. 격자 경로

### 정의
> `dp[i][j]` = (0,0)에서 (i,j)까지 가는 **경우의 수**

### 유도
(i,j)에 오는 방법은 위에서 내려오거나 왼쪽에서 오거나.

```
dp[i][j] = dp[i-1][j] + dp[i][j-1]
```

### 전체 코드

```cpp
#include <vector>

using namespace std;

// [정의] dp[i][j] = (0,0)에서 (i,j)까지 경우의 수
// [점화] dp[i][j] = dp[i-1][j] + dp[i][j-1]
// [초기] 첫 행과 첫 열은 전부 1 (한 방향으로만 갈 수 있음)

int solution(int n, int m)
{
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 1;
                continue;
            }

            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    return dp[n - 1][m - 1];
}
```

**장애물이 있으면** 그 칸을 0으로 두고 건너뛴다.

```cpp
if (board[i][j] == 1) { dp[i][j] = 0; continue; }   // 장애물
```

**같은 계열:** 등굣길, 정수 삼각형, 내려가기

---

# PART 4. DP 웰노운 요약표

| 패턴 | 정의 | 점화식 | 대표 문제 |
|---|---|---|---|
| 계단형 | 경우의 수 | `dp[i] = dp[i-1] + dp[i-2]` | 타일링, 계단 오르기 |
| 동전형 | 최소 개수 | `dp[i] = min(dp[i-c]) + 1` | 설탕 배달, 1로 만들기 |
| 배낭 | 최대 가치 | `dp[i][c] = max(안넣음, 넣음)` | 평범한 배낭 |
| LIS | **끝나는** 최대 길이 | `dp[i] = max(dp[j]) + 1` | 가장 긴 증가 수열 |
| 격자 | 경우의 수 | `dp[i][j] = 위 + 왼쪽` | 등굣길, 정수 삼각형 |

## 두 갈래로 기억

| 묻는 것 | 초기값 | 연산 |
|---|---|---|
| **세기** (경우의 수) | 0 (또는 1) | `+` |
| **최적화** (최소/최대) | `INT_MAX` / 0 | `min` / `max` |

---

# PART 5. C++ 체크리스트

## PQ

- [ ] **기본이 최대힙** — 최소힙은 `greater<int>` 명시
- [ ] **`pop()`은 값을 반환 안 함** — `top()` 먼저
- [ ] **빈 큐에 `top()`** → 런타임 에러. `empty()` 확인
- [ ] **비교자 부등호가 `sort`와 반대**
- [ ] **`while` 조건에 개수 검사** 포함 (`size() >= 2`)

## DP

- [ ] **`dp[i]` 정의를 한 문장으로** 먼저 적기
- [ ] **초기값** — 세기는 0/1, 최소화는 `INT_MAX`
- [ ] **`INT_MAX + 1` 오버플로우** — 불가능 상태 검사 추가
- [ ] **배열 크기** — `n + 1` 또는 `n + 2` 여유
- [ ] **답의 위치** — `dp[n]`인지 `dp` 전체 최댓값인지
- [ ] **모듈러** — 매 단계마다 적용
- [ ] **재귀 깊이 만 단위** → 상향식으로

---

# PART 6. 세 줄 요약

1. **PQ는 자료구조라 우회 불가.** 선언 두 개와 `push`/`top`/`pop`만 외우면 끝
2. **DP는 `dp[i]` 정의가 8할.** 점화식은 정의에서 유도된다
3. **웰노운 5종은 암기용이 아니라 정의 세우기가 되는지 확인하는 검증용**
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Meeting
{
    long long s, e; // 시작, 종료
    long long w;    // 인원
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    if (!(cin >> N))
    {
        return 0;
    }

    vector<Meeting> a(N + 1); // 1-index
    for (int i = 1; i <= N; i++)
    {
        cin >> a[i].s >> a[i].e >> a[i].w;
    }

    // 끝나는 시간 기준 정렬
    sort(a.begin() + 1, a.end(), [](const Meeting &x, const Meeting &y)
    {
        if (x.e != y.e) return x.e < y.e;
        return x.s < y.s;
    });

    // 끝시간 배열 (이진 탐색용)
    vector<long long> ends(N + 1, 0);
    for (int i = 1; i <= N; i++)
    {
        ends[i] = a[i].e;
    }

    // p[i]: i번째 회의 직전(겹치지 않는) 회의 인덱스
    vector<int> p(N + 1, 0);
    for (int i = 1; i <= N; i++)
    {
        // ends[idx] <= a[i].s 를 만족하는 가장 큰 idx
        int idx = (int)(upper_bound(ends.begin() + 1, ends.end(), a[i].s) - ends.begin()) - 1;
        p[i] = max(0, idx);
    }

    // DP
    vector<long long> dp(N + 1, 0);
    for (int i = 1; i <= N; i++)
    {
        dp[i] = max(dp[i - 1], dp[p[i]] + a[i].w);
    }

    cout << dp[N] << "\n";
    return 0;
}

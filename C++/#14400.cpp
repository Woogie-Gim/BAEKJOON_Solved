#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int, int>> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int a, b;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }

    // x 좌표, y좌표 모두 중앙값으로 정렬

    sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) { return a.first < b.first; });
    int mid_x = v[n / 2].first;

    sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) { return a.second < b.second; });
    int mid_y = v[n / 2].second;

    // 고객들의 위치가 -100만에서 +100만이므로 long long 사용
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += (abs(v[i].first - mid_x) + abs(v[i].second - mid_y));
    }

    cout << ans;

    return 0;
}
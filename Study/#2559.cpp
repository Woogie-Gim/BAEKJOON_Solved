#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> prefix(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        prefix[i] = prefix[i - 1] + x;
    }

    // 첫 구간으로 초기화. 0으로 두면 음수 답에서 틀림
    int ans = prefix[k] - prefix[0];

    for (int i = k + 1; i <= n; i++)
    {
        int cur = prefix[i] - prefix[i - k];
        if (cur > ans)
        {
            ans = cur;
        }
    }

    cout << ans << "\n";
    return 0;
}
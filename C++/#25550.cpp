#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<vector<long long>> a(N + 2, vector<long long>(M + 2, 0));
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> a[i][j];
        }
    }

    long long ans = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            long long t = min(
                a[i][j] - 1,
                min(
                    min(a[i - 1][j], a[i + 1][j]),
                    min(a[i][j - 1], a[i][j + 1])
                )
            );
            if (t > 0)
            {
                ans += t;
            }
        }
    }
    
    cout << ans << "\n";
    
    return 0;
}
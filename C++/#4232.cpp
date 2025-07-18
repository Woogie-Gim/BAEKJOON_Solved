#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (true)
    {
        int N;
        cin >> N;

        if (N == 0)
        {
            break;
        }

        map<vector<int>, int> m;
        vector<vector<int>> v(N, vector<int>(5));

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cin >> v[i][j];
            }

            sort(v[i].begin(), v[i].end());
            m[v[i]]++;
        }

        int Max = 0;

        for (int i = 0; i < N; i++)
        {
            Max = max(Max, m[v[i]]);
        }

        int ans = 0;

        for (int i = 0; i < N; i++)
        {
            if (m[v[i]] == Max)
            {
                ans++;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}

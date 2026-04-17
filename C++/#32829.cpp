#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    if (!(cin >> n >> m))
    {
        return 0;
    }

    vector<vector<long long>> times(n, vector<long long>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> times[i][j];
        }
    }

    for (int j = 0; j < m; j++)
    {
        vector<pair<long long, int>> events;
        for (int i = 0; i < n; i++)
        {
            long long entry_t = 0;
            for (int k = 0; k < j; k++)
            {
                entry_t += times[i][k];
            }
            long long exit_t = entry_t + times[i][j];

            events.push_back({entry_t, 1});
            events.push_back({exit_t, -1});
        }

        sort(events.begin(), events.end());

        int max_r = 0;
        int curr = 0;
        for (int i = 0; i < events.size(); i++)
        {
            curr += events[i].second;
            if (curr > max_r)
            {
                max_r = curr;
            }
        }

        cout << max_r << (j == m - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    if (!(cin >> N >> M))
    {
        return 0;
    }

    vector<vector<int>> pref(N, vector<int>(M));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> pref[i][j];
        }
    }

    int max_sum = 0;

    for (int i = 0; i < M - 2; i++)
    {
        for (int j = i + 1; j < M - 1; j++)
        {
            for (int k = j + 1; k < M; k++)
            {
                int current_sum = 0;
                for (int p = 0; p < N; p++)
                {
                    current_sum += max({pref[p][i], pref[p][j], pref[p][k]});
                }
                max_sum = max(max_sum, current_sum);
            }
        }
    }

    cout << max_sum << "\n";

    return 0;
}
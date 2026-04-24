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

    vector<int> d(N + 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> d[i];
    }

    vector<vector<bool>> needed(M, vector<bool>(N + 1, false));
    for (int i = 0; i < M; i++)
    {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int knowledge;
            cin >> knowledge;
            needed[i][knowledge] = true;
        }
    }

    vector<int> order(M);
    for (int i = 0; i < M; i++)
    {
        order[i] = i;
    }

    int min_total_study = 1000000000;

    do
    {
        int current_study = 0;

        for (int x = 1; x <= N; x++)
        {
            int cover_end = 0;
            int study_count = 0;

            for (int day = 1; day <= M; day++)
            {
                int prob = order[day - 1];
                if (needed[prob][x])
                {
                    if (day > cover_end)
                    {
                        study_count++;
                        cover_end = day + d[x] - 1;
                    }
                }
            }
            current_study += study_count;
        }

        if (current_study < min_total_study)
        {
            min_total_study = current_study;
        }

    } while (next_permutation(order.begin(), order.end()));

    cout << min_total_study << "\n";

    return 0;
}
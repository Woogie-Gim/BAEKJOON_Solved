#include <iostream>
#include <vector>

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

    vector<vector<int>> dist(N + 1, vector<int>(N + 1, 0));

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        dist[a][b] = 1;
    }

    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (dist[i][k] == 1 && dist[k][j] == 1)
                {
                    dist[i][j] = 1;
                }
            }
        }
    }

    int exact_rank_count = 0;

    for (int i = 1; i <= N; i++)
    {
        int known_relations = 0;
        
        for (int j = 1; j <= N; j++)
        {
            if (i == j)
            {
                continue;
            }
            
            if (dist[i][j] == 1 || dist[j][i] == 1)
            {
                known_relations++;
            }
        }

        if (known_relations == N - 1)
        {
            exact_rank_count++;
        }
    }

    cout << exact_rank_count << "\n";

    return 0;
}
#include <iostream>
#include <cstring>

using namespace std;

int N, k;
int graph[100000][3], dp[100000][3];
int dx[] = {-1, 0, 1};

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    while (true)
    {
        cin >> N;

        if (N == 0)
        {
            break;
        }
        memset(dp, 0x3f, sizeof(dp));
        for (int y = 0; y < N; ++y)
        {
            for (int x = 0; x < 3; ++x)
            {
                cin >> graph[y][x];
            }
        }

        for (int x = 0; x < 3; ++x)
        {
            dp[1][x] = graph[1][x] + graph[0][1];
        }
        if (graph[0][2] < 0)
        {
            int rightValue = graph[0][2] + graph[0][1];
            dp[1][1] = graph[1][1] + rightValue;
            dp[1][2] = graph[1][2] + rightValue;
        }
        for (int x = 1; x < 3; ++x)
        {
            dp[1][x] = min(dp[1][x], dp[1][x - 1] + graph[1][x]);
        }

        for (int y = 2; y < N; ++y)
        {
            for (int x = 0; x < 3; ++x)
            {
                for (int i = 0; i < 3; ++i)
                {
                    int nx = dx[i] + x;
                    if (nx < 0 || nx > 2)
                    {
                        continue;
                    }
                    dp[y][x] = min(dp[y][x], graph[y][x] + dp[y - 1][nx]); 
                }
            }
            for (int x = 1; x < 3; ++x)
            {
                dp[y][x] = min(dp[y][x], dp[y][x - 1] + graph[y][x]);
            }
        }
        cout << ++k << ". " << dp[N - 1][1] << "\n";
    }
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, R, C, K;

    while (cin >> N >> R >> C >> K)
    {
        if (N == 0 && R == 0 && C == 0 && K == 0)
        {
            break;
        }

        vector<vector<int>> land(R, vector<int>(C));

        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> land[i][j];
            }
        }

        int dr[4] = { -1, 1, 0, 0 };
        int dc[4] = { 0, 0, -1, 1 };

        for (int k = 0; k < K; k++)
        {
            vector<vector<int>> next_land = land;

            for (int r = 0; r < R; r++)
            {
                for (int c = 0; c < C; c++)
                {
                    int my_val = land[r][c];
                    int predator = (my_val - 1 + N) % N;

                    for (int d = 0; d < 4; d++)
                    {
                        int nr = r + dr[d];
                        int nc = c + dc[d];

                        if (nr >= 0 && nr < R && nc >= 0 && nc < C)
                        {
                            if (land[nr][nc] == predator)
                            {
                                next_land[r][c] = predator;
                                break;
                            }
                        }
                    }
                }
            }
            land = next_land;
        }

        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cout << land[i][j];
                if (j < C - 1)
                {
                    cout << " ";
                }
            }
            cout << "\n";
        }
    }

    return 0;
}
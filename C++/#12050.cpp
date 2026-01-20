#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++)
    {
        int R, C;
        cin >> R >> C;

        vector<string> grid(R);
        for (int i = 0; i < R; i++)
        {
            cin >> grid[i];
        }

        int N;
        cin >> N;

        cout << "Case #" << tc << ":\n";

        for (int opi = 0; opi < N; opi++)
        {
            char op;
            cin >> op;

            if (op == 'M')
            {
                int x, y, z;
                cin >> x >> y >> z;
                grid[x][y] = char('0' + z);
            }
            else
            {
                vector<vector<int> > visited(R, vector<int>(C, 0));
                int components = 0;

                for (int i = 0; i < R; i++)
                {
                    for (int j = 0; j < C; j++)
                    {
                        if (grid[i][j] != '1') continue;
                        if (visited[i][j]) continue;

                        components++;

                        queue<pair<int, int> > q;
                        q.push(make_pair(i, j));
                        visited[i][j] = 1;

                        while (!q.empty())
                        {
                            pair<int, int> cur = q.front();
                            q.pop();

                            int r = cur.first;
                            int c = cur.second;

                            int dr[4] = { -1, 1, 0, 0 };
                            int dc[4] = { 0, 0, -1, 1 };

                            for (int d = 0; d < 4; d++)
                            {
                                int nr = r + dr[d];
                                int nc = c + dc[d];

                                if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
                                if (visited[nr][nc]) continue;
                                if (grid[nr][nc] != '1') continue;

                                visited[nr][nc] = 1;
                                q.push(make_pair(nr, nc));
                            }
                        }
                    }
                }

                cout << components << "\n";
            }
        }
    }

    return 0;
}

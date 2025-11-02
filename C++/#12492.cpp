#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    if (!(cin >> T))
    {
        return 0;
    }

    for (int tc = 1; tc <= T; ++tc)
    {
        int R, C;
        cin >> R >> C;
        vector<string> g(R);
        for (int i = 0; i < R; ++i)
        {
            cin >> g[i];
        }

        bool ok = true;

        for (int i = 0; i < R; ++i)
        {
            for (int j = 0; j < C; ++j)
            {
                if (g[i][j] == '#')
                {
                    if (i + 1 >= R || j + 1 >= C)
                    {
                        ok = false;
                        break;
                    }
                    if (!(g[i][j + 1] == '#' && g[i + 1][j] == '#' && g[i + 1][j + 1] == '#'))
                    {
                        ok = false;
                        break;
                    }

                    // 치환
                    g[i][j] = '/';
                    g[i][j + 1] = '\\';
                    g[i + 1][j] = '\\';
                    g[i + 1][j + 1] = '/';
                }
            }
            if (!ok) break;
        }

        if (ok)
        {
            for (int i = 0; i < R; ++i)
            {
                for (int j = 0; j < C; ++j)
                {
                    if (g[i][j] == '#')
                    {
                        ok = false;
                        break;
                    }
                }
                if (!ok) break;
            }
        }

        cout << "Case #" << tc << ":\n";
        if (!ok)
        {
            cout << "Impossible\n";
        }
        else
        {
            for (int i = 0; i < R; ++i)
            {
                cout << g[i] << '\n';
            }
        }
    }

    return 0;
}

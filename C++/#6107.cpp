#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int R, C;
    if (!(cin >> R >> C)) return 0;

    vector<vector<int>> a(R, vector<int>(C));
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            cin >> a[i][j];

    const int dr[8] = {-1,-1,-1, 0, 0, 1, 1, 1};
    const int dc[8] = {-1, 0, 1,-1, 1,-1, 0, 1};

    int ans = 0;

    for (int r = 0; r < R; ++r) 
    {
        for (int c = 0; c < C; ++c) 
        {
            if (a[r][c] <= 0) continue; 
            for (int d = 0; d < 8; ++d) 
            {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue; 
                if (a[nr][nc] == a[r][c]) 
                {
                    if (a[r][c] > ans) ans = a[r][c];
                }
            }
        }
    }

    cout << ans << '\n';
    
    return 0;
}

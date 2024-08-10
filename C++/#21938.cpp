#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int n, m, t;
int board[3002][3002];
int vis[3002][3002];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int count = 0;

    cin >> n >> m;

    m = 3 * m;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }

    cin >> t;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j += 3){
            int average = (board[i][j] + board[i][j + 1] + board[i][j + 2]) / 3;

            if (average >= t){
                board[i][j] = 255;
                board[i][j + 1] = 255;
                board[i][j + 2] = 255;
            } else {
                board[i][j] = 0;
                board[i][j + 1] = 0;
                board[i][j + 2] = 0;
            }
        }
    }

    queue<pair<int, int> > Q;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (board[i][j] == 0 || vis[i][j] > 0) continue;

            vis[i][j] = 1;
            Q.push({i, j});
            count++;

            while (!Q.empty())
            {
                auto cur = Q.front();
                Q.pop();

                for (int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if (vis[nx][ny] > 0 || board[nx][ny] == 0) continue;

                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
            
        }
    }

    cout << count;
}
#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
 
int n, m;

vector<vector<char>> vec;
vector<vector<int>> visited;

int ans;
 
void dfs(int a, int b, int cnt)
{
    visited[a][b] = cnt;
 
    char mv = vec[a][b];
 
    int nx = a;
    int ny = b;
 
    if (mv == 'U')
    {
        nx += -1;
    }
    else if (mv == 'D')
    {
        nx += 1;
    }
    else if (mv == 'L')
    {
        ny += -1;
    }
    else if (mv == 'R')
    {
        ny += 1;
    }
 
    if (0 > nx || nx >= n) return;
    if (0 > ny || ny >= m) return;
 
    if (visited[nx][ny] == cnt) ans++;
 
    if (visited[nx][ny]) return;
    dfs(nx, ny, cnt);
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    
    cin >> n >> m;
    
    vec.resize(n, vector<char>(m, 0));
    visited.resize(n, vector<int>(m, 0));
 
    string temp;
    
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        for (int j = 0; j < m; j++)
        {
            vec[i][j] = temp[j];
        }
    }
 
    int cnt = 1;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j])
            {
                dfs(i, j, cnt);
                cnt++;
            }
        }
    }
 
    cout << ans;
 
    return 0;
}
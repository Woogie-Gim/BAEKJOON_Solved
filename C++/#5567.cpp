#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() 
{
    int n, m, ans = 0;
    cin >> n >> m;

    vector<int> v[501];
    
    int visited[501] = { false, };

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    queue<pair<int, int>> q;
    q.push(make_pair(1, 0));
    visited[1] = true;

    while (!q.empty()) 
    {
        int now = q.front().first;
        int depth = q.front().second;
        q.pop();

        if (depth == 2) 
        {
            continue;
        }

        for (int i = 0; i < v[now].size(); i++)
        {
            int next = v[now][i];
            
            if (visited[next])
            {
                continue;
            }
            visited[next] = true;
            ans++;
            q.push(make_pair(next, depth + 1));
        }
    }
    
    cout << ans;
    
    return 0;
}
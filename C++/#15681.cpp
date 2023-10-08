#include <iostream>
#include <vector>

using namespace std;

int N, R, Q;
vector<int> e[100001];
bool visited[100001];
int nums[100001];

int dfs(int r)
{
    if (nums[r] != 0) return nums[r];

    visited[r] = true;

    int cnt = 1;
    for (int i = 0; i < e[r].size(); i++)
    {
        int next = e[r][i];
        if (visited[next]) continue;
        cnt += dfs(next);
    }
    nums[r] = cnt;
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> R >> Q;
    
    int u, v;
    for (int i = 0; i < N-1; i++)
    {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    nums[R] = dfs(R);

    int q;
    for (int i = 0; i < Q; i++)
    {
        cin >> q;
        cout << nums[q] << "\n";
    }
    return 0;
}
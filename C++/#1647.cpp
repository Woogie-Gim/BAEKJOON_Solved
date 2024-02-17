#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int p[100001];
int n;
long long ans = 0;
int M = 0;

vector<pair<int, pair<int, int>>> edge;

int find(int a) 
{
    if (p[a] == a) return a;
    return p[a] = find(p[a]);
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int m;
    int count = 0;
    
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) 
    {
        p[i] = i;
    }
    
    int a, b, c;
    
    for (int i = 0; i < m; i++) 
    {
        cin >> a >> b >> c;
        edge.push_back({c, {a, b}});
    }
    
    sort(edge.begin(), edge.end());
    
    for (int i = 0; i < edge.size(); i++) 
    {
        if (count == n - 1) break;
        pair<int, pair<int, int>> temp = edge[i];
        int tmp1 = find(temp.second.first);
        int tmp2 = find(temp.second.second);
        if (tmp1 == tmp2) continue;
        p[tmp2] = tmp1;
        ans += temp.first;
        M = max(M, temp.first); 
    }
    
    cout << ans - M;
    
    return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, c, w, t, cut = 0, cnt = 0;
    long long ans = 0, temp;
    
    cin >> n >> c >> w;

    for (int i = 0; i < n; i++) 
    {
        cin >> t;
        v.push_back(t);
    }
    sort(v.begin(), v.end());

    for (int i = 1; i <= v[n-1]; i++) 
    {
        temp = 0;
        for (int k = 0; k < n; k++) 
        {
            cnt = (v[k] / i);
            cut = max(0, (v[k] / i));
            if (v[k] % i == 0) { cut--; }
            t = (cnt * i * w) - (c * cut);
            if (t > 0) { temp += t; }
        }
        ans = max(ans, temp);
    }
    cout << ans;

    return 0;
}
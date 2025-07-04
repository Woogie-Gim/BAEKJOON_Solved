#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() 
{
    int l;
    cin >> l;

    vector<int> v(l);

    for (int i = 0; i < l; i++) cin >> v[i];

    int ans = 0;

    for (int i = 0; i < l; i++) for (int j = i + 1; j < l; j++)
    {
        if (v[i] > v[j]) ans++;
    }
    cout << "Optimal train swapping takes " << ans << " swaps.\n";
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; 
    cin >> n;
    
    while (n--) solve();
    
    return 0;
}
#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    ll sum = 0;
    
    for (int i = 0; i < n; ++i) 
    {
        int in;
        cin >> in;
        sum += in;
    }

    vector<int> growing(n);
    
    for (auto& c : growing)
        cin >> c;

    sort(growing.begin(), growing.end());
    
    for (int i = 0; i < n; ++i)
        sum += growing[i] * i;

    cout << sum << '\n';

    return 0;
}

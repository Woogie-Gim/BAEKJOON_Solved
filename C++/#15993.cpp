#include <iostream>

typedef long long ll;

using namespace std;
 
ll odd[100001];
ll even[100001];
const int mod = 1e9 + 9;
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    odd[1] = 1, odd[2] = 1, odd[3] = 2;
    even[1] = 0, even[2] = 1, even[3] = 2;
 
    for (int i = 4; i <= 100000; i++)
        odd[i] = (even[i - 1] + even[i - 2] + even[i - 3])%mod, even[i] = (odd[i - 1] + odd[i - 2] + odd[i - 3])%mod;
 
    int T; cin >> T;
    while (T--) 
    {
        int n; cin >> n;
        cout << odd[n] << " " << even[n] << "\n";
    }
 
    return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

int CheckDistance(const string& a, const string& b) 
{
    int val = 0;
    for (int i = 0; i < 4; i++) 
    {
        if (a[i] != b[i]) val++;
    }
    return val;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) 
    {
        int n;
        cin >> n;
        int val = numeric_limits<int>::max();
        vector<string> v(n);

        for (int i = 0; i < n; i++) 
        {
            cin >> v[i];
        }

        if (n > 32) 
        {
            cout << 0 << "\n";
        } 
        else 
        {
            for (int i = 0; i < n - 1; i++) 
            {
                for (int j = i + 1; j < n; j++) 
                {
                    for (int k = j + 1; k < n; k++) 
                    {
                        int dis = CheckDistance(v[i], v[j]) + CheckDistance(v[j], v[k]) + CheckDistance(v[i], v[k]);
                        val = min(val, dis);
                    }
                }
            }
            cout << val << "\n";
        }
    }
    return 0;
}
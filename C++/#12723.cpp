#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
    int t;
    cin >> t;

    for (int tc = 1; tc <= t; ++tc)
    {
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i)
        {
            cin >> b[i];
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end(), greater<int>());

        int result = 0;
        
        for (int i = 0; i < n; ++i) 
        {
            result += a[i] * b[i];
        }

        cout << "Case #" << tc << ": " << result << "\n";
    }

    return 0;
}

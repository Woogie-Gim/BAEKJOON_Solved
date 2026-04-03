#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    if (cin >> t)
    {
        while (t--)
        {
            int n;
            cin >> n;

            vector<int> a(n);
            for (int i = 0; i < n; i++)
            {
                cin >> a[i];
            }

            sort(a.begin(), a.end());

            vector<int> res;
            int l = 0;
            int r = n - 1;

            while (l <= r)
            {
                res.push_back(a[l]);
                l++;
                if (l <= r)
                {
                    res.push_back(a[r]);
                    r--;
                }
            }

            reverse(res.begin(), res.end());

            for (int i = 0; i < n; i++)
            {
                cout << res[i] << (i == n - 1 ? "" : " ");
            }
            cout << "\n";
        }
    }

    return 0;
}
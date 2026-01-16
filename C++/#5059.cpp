#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> prices(n);
        for (int i = 0; i < n; i++)
        {
            cin >> prices[i];
        }

        sort(prices.begin(), prices.end(), greater<int>());

        long long discount = 0;
        for (int i = 2; i < n; i += 3)
        {
            discount += prices[i];
        }

        cout << discount << '\n';
    }

    return 0;
}

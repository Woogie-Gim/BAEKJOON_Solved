#include <iostream>
#include <algorithm>

using namespace std;

int a, b, c, d;

int Fit(int u, int x)
{
    int fx = max(a * (x - b) * (x - b) + c, d);
    if (fx != u || b > x)
    {
        return 0;
    }
    return 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> c >> d;

    int n;
    cin >> n;

    int ans = 0;

    for (int i = 0; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        ans += Fit(u, v);
    }

    cout << ans << '\n';

    return 0;
}

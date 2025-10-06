#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long x1, y1, x2, y2;
    long long x3, y3, x4, y4;
    long long w, h;

    if (!(cin >> x1 >> y1 >> x2 >> y2))
    {
        return 0;
    }
    cin >> x3 >> y3 >> x4 >> y4;
    cin >> w >> h;

    long long GW = x2 - x1; 
    long long GH = y2 - y1;

    bool ok = false;

    if (w <= x3 - x1 && h <= GH)
    {
        ok = true;
    }
    if (w <= x2 - x4 && h <= GH)
    {
        ok = true;
    }
    if (h <= y3 - y1 && w <= GW)
    {
        ok = true;
    }
    if (h <= y2 - y4 && w <= GW)
    {
        ok = true;
    }

    cout << (ok ? "Yes\n" : "No\n");
    
    return 0;
}

#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long ax, ay, bx, by, px, py, r;
    if (!(cin >> ax >> ay >> bx >> by >> px >> py >> r))
    {
        return 0;
    }

    long double d_ab = sqrt((long double)((ax - bx) * (ax - bx) + (ay - by) * (ay - by)));
    long double d_ac = sqrt((long double)((ax - px) * (ax - px) + (ay - py) * (ay - py)));
    long double d_bc = sqrt((long double)((bx - px) * (bx - px) + (by - py) * (by - py)));

    long double cost_via_circle = max((long double)0.0, d_ac - r) + max((long double)0.0, d_bc - r);

    long double ans = min(d_ab, cost_via_circle);

    cout << fixed << setprecision(10) << ans << "\n";

    return 0;
}
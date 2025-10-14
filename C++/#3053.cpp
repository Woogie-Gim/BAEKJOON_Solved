#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    double R;
    if (!(cin >> R))
    {
        return 0;
    }

    const double PI = acos(-1.0);

    double euclid = PI * R * R;
    double taxicab = 2.0 * R * R;

    cout << fixed << setprecision(6);
    cout << euclid << "\n";
    cout << taxicab << "\n";

    return 0;
}

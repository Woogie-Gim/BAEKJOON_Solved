#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    double g;
    if (!(cin >> n >> g))
    {
        return 0;
    }

    vector<double> d(n);
    vector<double> theta(n);
    for (int i = 0; i < n; i++)
    {
        cin >> d[i] >> theta[i];
    }

    double pi = acos(-1.0);

    for (int i = 0; i < n; i++)
    {
        double v_sq = 0;
        for (int j = i; j < n; j++)
        {
            double a = g * cos(theta[j] * pi / 180.0);
            v_sq += 2.0 * a * d[j];
        }
        cout << fixed << setprecision(6) << sqrt(v_sq) << "\n";
    }

    return 0;
}
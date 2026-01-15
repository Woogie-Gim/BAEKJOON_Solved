#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int K;
    cin >> K;

    const double g = 9.81;

    for (int tc = 1; tc <= K; tc++)
    {
        int n;
        double M;
        cin >> n >> M;

        vector<double> m(n), t(n), F(n);

        double totalStageMass = 0.0;
        for (int i = 0; i < n; i++)
        {
            cin >> m[i] >> t[i] >> F[i];
            totalStageMass += m[i];
        }

        double curMass = M + totalStageMass;
        double v = 0.0;
        double h = 0.0;

        for (int i = 0; i < n; i++)
        {
            double a = F[i] / curMass - g;
            h += v * t[i] + 0.5 * a * t[i] * t[i];
            v += a * t[i];
            curMass -= m[i];
        }

        cout << "Data Set " << tc << ":\n";
        cout << fixed << setprecision(2) << h << "\n";
    }

    return 0;
}

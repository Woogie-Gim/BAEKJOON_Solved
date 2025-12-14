#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    int K;
    cin >> N >> K;

    vector<double> needRadiusSquared;
    needRadiusSquared.reserve(N);

    for (int i = 0; i < N; i++)
    {
        int P;
        cin >> P;

        double maxDistSquared = 0.0;

        for (int j = 0; j < P; j++)
        {
            double x;
            double y;
            cin >> x >> y;

            double distSquared = x * x + y * y;
            if (distSquared > maxDistSquared)
            {
                maxDistSquared = distSquared;
            }
        }

        needRadiusSquared.push_back(maxDistSquared);
    }

    sort(needRadiusSquared.begin(), needRadiusSquared.end());

    double answer = needRadiusSquared[K - 1];

    cout << fixed << setprecision(2) << answer;

    return 0;
}

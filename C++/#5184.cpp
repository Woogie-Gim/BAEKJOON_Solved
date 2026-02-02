#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <functional>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int K;
    cin >> K;

    for (int k = 1; k <= K; k++)
    {
        int L, R, N;
        cin >> L >> R >> N;

        vector<double> p(N);
        for (int i = 0; i < N; i++)
        {
            cin >> p[i];
        }

        sort(p.begin(), p.end(), greater<double>());

        double max_expected_value = 0.0;

        for (int i = 0; i < N; i++)
        {
            if (i < L)
            {
                max_expected_value += p[i];
            }
            else if (i < R)
            {
                if (p[i] > 0.5)
                {
                    max_expected_value += p[i];
                }
                else
                {
                    max_expected_value += (1.0 - p[i]);
                }
            }
            else
            {
                max_expected_value += (1.0 - p[i]);
            }
        }

        cout << "Data Set " << k << ":" << "\n";
        cout << fixed << setprecision(2) << max_expected_value << "\n";
    }

    return 0;
}
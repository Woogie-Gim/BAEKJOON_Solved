#include <iostream>
#include <climits>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    if (!(cin >> T))
    {
        return 0;
    }

    while (T--)
    {
        int N;
        cin >> N;

        int best = INT_MAX;

        for (int a = 1; (long long)a * a * a <= N; ++a)
        {
            if (N % a != 0) continue;
            int n1 = N / a;

            for (int b = a; (long long)a * b * b <= N; ++b)
            {
                if (n1 % b != 0) continue;
                int c = n1 / b;

                int area = 2 * (a * b + b * c + c * a);
                if (area < best)
                {
                    best = area;
                }
            }
        }

        cout << best << '\n';
    }

    return 0;
}

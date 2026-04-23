#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    long long a, b;
    if (!(cin >> n >> a >> b))
    {
        return 0;
    }

    vector<long long> x(n);
    vector<long long> y(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }

    int max_cnt = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            long long left_x = x[i];
            long long bottom_y = y[j];
            long long right_x = left_x + a;
            long long top_y = bottom_y + b;

            int cnt = 0;
            for (int k = 0; k < n; k++)
            {
                if (x[k] >= left_x && x[k] <= right_x && y[k] >= bottom_y && y[k] <= top_y)
                {
                    cnt++;
                }
            }

            if (cnt > max_cnt)
            {
                max_cnt = cnt;
            }
        }
    }

    cout << max_cnt << "\n";

    return 0;
}
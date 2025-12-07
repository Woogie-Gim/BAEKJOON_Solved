#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long a;
    long long b;
    cin >> a >> b;

    long long exp2 = 0;
    long long exp5 = 0;

    for (int t = 0; t < 2; t++)
    {
        long long p;
        if (t == 0)
        {
            p = 2;
        }
        else
        {
            p = 5;
        }

        long long power = p;
        long long best = 0;

        while (power <= b)
        {
            long long left = (a + power - 1) / power;
            long long right = b / power;

            if (left <= right)
            {
                best++;
            }
            else
            {
                break;
            }

            if (power > b / p)
            {
                break;
            }

            power = power * p;
        }

        if (t == 0)
        {
            exp2 = best;
        }
        else
        {
            exp5 = best;
        }
    }

    long long answer;
    if (exp2 < exp5)
    {
        answer = exp2;
    }
    else
    {
        answer = exp5;
    }

    cout << answer;

    return 0;
}

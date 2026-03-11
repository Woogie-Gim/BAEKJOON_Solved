#include <iostream>

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

    for (int t = 1; t <= T; t++)
    {
        long long N;
        cin >> N;

        if (N == 0)
        {
            cout << "Case #" << t << ": INSOMNIA\n";
        }
        else
        {
            bool seen[10];
            for (int i = 0; i < 10; i++)
            {
                seen[i] = false;
            }

            int count = 0;
            long long current = 0;
            long long multiplier = 1;

            while (count < 10)
            {
                current = N * multiplier;
                long long temp = current;

                while (temp > 0)
                {
                    int digit = temp % 10;
                    if (!seen[digit])
                    {
                        seen[digit] = true;
                        count++;
                    }
                    temp /= 10;
                }

                multiplier++;
            }

            cout << "Case #" << t << ": " << current << "\n";
        }
    }

    return 0;
}
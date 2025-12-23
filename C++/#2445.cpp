#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 1; i <= 2 * N - 1; i++)
    {
        int stars;
        if (i <= N)
        {
            stars = i;
        }
        else
        {
            stars = 2 * N - i;
        }

        if (i == N)
        {
            for (int j = 0; j < 2 * N; j++)
            {
                cout << '*';
            }
        }
        else
        {
            for (int j = 0; j < stars; j++)
            {
                cout << '*';
            }

            int spaces = 2 * (N - stars);
            for (int j = 0; j < spaces; j++)
            {
                cout << ' ';
            }

            for (int j = 0; j < stars; j++)
            {
                cout << '*';
            }
        }

        cout << '\n';
    }

    return 0;
}

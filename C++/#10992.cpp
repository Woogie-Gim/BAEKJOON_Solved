#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    if (N == 1)
    {
        cout << "*\n";
        return 0;
    }

    for (int i = 1; i <= N; i++)
    {
        if (i == N)
        {
            for (int j = 0; j < 2 * N - 1; j++)
            {
                cout << "*";
            }
            cout << "\n";
        }
        else
        {
            for (int j = 0; j < N - i; j++)
            {
                cout << " ";
            }

            cout << "*";

            if (i > 1)
            {
                for (int j = 0; j < 2 * i - 3; j++)
                {
                    cout << " ";
                }
                cout << "*";
            }

            cout << "\n";
        }
    }

    return 0;
}

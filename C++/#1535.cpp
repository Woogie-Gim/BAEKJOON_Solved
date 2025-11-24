#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int L[25];
    int J[25];

    for (int i = 0; i < N; i++)
    {
        cin >> L[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> J[i];
    }

    int dp[101];
    for (int i = 0; i <= 100; i++)
    {
        dp[i] = 0;
    }

    for (int i = 0; i < N; i++)
    {
        for (int hp = 100; hp >= L[i]; hp--)
        {
            if (dp[hp - L[i]] + J[i] > dp[hp])
            {
                dp[hp] = dp[hp - L[i]] + J[i];
            }
        }
    }

    int answer = 0;
    for (int hp = 1; hp <= 99; hp++)
    {
        if (dp[hp] > answer)
        {
            answer = dp[hp];
        }
    }

    cout << answer;

    return 0;
}

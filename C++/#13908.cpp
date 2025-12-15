#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
    }

    long long comb[8][8];
    for (int i = 0; i <= 7; i++)
    {
        for (int j = 0; j <= 7; j++)
        {
            comb[i][j] = 0;
        }
    }

    for (int i = 0; i <= 7; i++)
    {
        comb[i][0] = 1;
        comb[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
        }
    }

    long long answer = 0;

    for (int k = 0; k <= m; k++)
    {
        long long base = 10 - k;
        long long power = 1;

        for (int i = 0; i < n; i++)
        {
            power = power * base;
        }

        long long term = comb[m][k] * power;

        if (k % 2 == 0)
        {
            answer += term;
        }
        else
        {
            answer -= term;
        }
    }

    cout << answer;

    return 0;
}

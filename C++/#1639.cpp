#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string S;
    if (!(cin >> S))
    {
        return 0;
    }

    int L = S.length();

    for (int len = L - (L % 2); len >= 2; len -= 2)
    {
        for (int i = 0; i <= L - len; i++)
        {
            int sum1 = 0;
            int sum2 = 0;
            int half = len / 2;

            for (int j = 0; j < half; j++)
            {
                sum1 += S[i + j] - '0';
                sum2 += S[i + half + j] - '0';
            }

            if (sum1 == sum2)
            {
                cout << len << "\n";
                return 0;
            }
        }
    }

    cout << 0 << "\n";

    return 0;
}
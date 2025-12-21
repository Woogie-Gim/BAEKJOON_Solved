#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    long long M;
    cin >> N >> M;

    string S;
    cin >> S;

    for (int i = 0; i < N; i++)
    {
        int d = S[i] - '0';

        for (int t = 0; t <= 9; t++)
        {
            int cost = (t - d + 10) % 10;

            if (cost <= M)
            {
                S[i] = char('0' + t);
                M -= cost;
                break;
            }
        }
    }

    int rem = M % 10;
    if (rem > 0)
    {
        int last = S[N - 1] - '0';
        last = (last + rem) % 10;
        S[N - 1] = char('0' + last);
    }

    cout << S << '\n';
    
    return 0;
}

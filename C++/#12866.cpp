#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long L;
    if (!(cin >> L))
    {
        return 0;
    }

    string S;
    cin >> S;

    long long count_A = 0;
    long long count_C = 0;
    long long count_G = 0;
    long long count_T = 0;

    for (int i = 0; i < L; i++)
    {
        if (S[i] == 'A')
        {
            count_A++;
        }
        else if (S[i] == 'C')
        {
            count_C++;
        }
        else if (S[i] == 'G')
        {
            count_G++;
        }
        else if (S[i] == 'T')
        {
            count_T++;
        }
    }

    long long mod = 1000000007;
    long long ans = 1;

    ans = (ans * count_A) % mod;
    ans = (ans * count_C) % mod;
    ans = (ans * count_G) % mod;
    ans = (ans * count_T) % mod;

    cout << ans << "\n";

    return 0;
}
#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    if (!(cin >> N))
    {
        return 0;
    }

    long long T = 0;
    long long B = 0;
    long long L = 0;
    long long R = 0;

    for (int i = 0; i < N; i++)
    {
        string s;
        
        cin >> s;

        if (s[0] == '0')
        {
            T++;
        }
        if (s[1] == '0')
        {
            B++;
        }
        if (s[2] == '0')
        {
            L++;
        }
        if (s[3] == '0')
        {
            R++;
        }
    }

    long long TB = T + B;
    long long LR = L + R;

    long long swords = min(TB / 2, LR / 2);
    long long remTB = TB - 2 * swords;
    long long remLR = LR - 2 * swords;

    cout << swords << " " << remTB << " " << remLR << "\n";
    return 0;
}

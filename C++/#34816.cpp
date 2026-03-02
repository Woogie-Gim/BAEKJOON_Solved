#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, Q;
    if (!(cin >> N >> Q))
    {
        return 0;
    }

    string S;
    cin >> S;

    for (int i = 0; i < Q; i++)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int idx;
            cin >> idx;
            
            if (S[idx - 1] == '0')
            {
                S[idx - 1] = '1';
            }
            else
            {
                S[idx - 1] = '0';
            }
        }
        else if (type == 2)
        {
            int x, y;
            cin >> x >> y;

            int len = y - x + 1;

            if (len >= 4)
            {
                cout << "YES\n";
            }
            else if (len == 3)
            {
                if (S[x - 1] == S[x] || S[x] == S[y - 1])
                {
                    cout << "YES\n";
                }
                else
                {
                    cout << "NO\n";
                }
            }
            else if (len == 2)
            {
                if (S[x - 1] == S[y - 1])
                {
                    cout << "YES\n";
                }
                else
                {
                    cout << "NO\n";
                }
            }
            else
            {
                cout << "NO\n";
            }
        }
    }

    return 0;
}
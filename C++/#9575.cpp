#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    while (T--)
    {
        int n;
        vector<int> a;
        vector<int> b;
        vector<int> c;

        cin >> n;
        a.resize(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }

        cin >> n;
        b.resize(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> b[i];
        }

        cin >> n;
        c.resize(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> c[i];
        }

        set<int> validSums;

        for (int i = 0; i < static_cast<int>(a.size()); ++i)
        {
            for (int j = 0; j < static_cast<int>(b.size()); ++j)
            {
                for (int k = 0; k < static_cast<int>(c.size()); ++k)
                {
                    int sum = a[i] + b[j] + c[k];
                    string s = to_string(sum);
                    bool isValid = true;

                    for (char ch : s)
                    {
                        if (ch != '5' && ch != '8')
                        {
                            isValid = false;
                            break;
                        }
                    }

                    if (isValid)
                    {
                        validSums.insert(sum);
                    }
                }
            }
        }

        cout << validSums.size() << "\n";
    }

    return 0;
}

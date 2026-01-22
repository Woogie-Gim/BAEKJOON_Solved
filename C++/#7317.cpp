#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    vector<long long> w;
    w.push_back(1);
    
    for (int i = 1; i <= 40; i++)
    {
        long long next = w[i - 1] * 2 + 1;
        w.push_back(next);
    }

    for (int tc = 0; tc < t; tc++)
    {
        string s;
        cin >> s;

        long long n = 0;
        for (int i = 0; i < (int)s.size(); i++)
        {
            n = n * 10 + (s[i] - '0');
        }

        vector<int> answer;

        if (n == 0)
        {
            
        }
        else
        {
            int maxRank = 0;
            while (maxRank + 1 < (int)w.size() && w[maxRank + 1] <= n)
            {
                maxRank++;
            }

            bool found = false;

            for (int r = -1; r <= maxRank && !found; r++)
            {
                long long base = 0;
                if (r != -1)
                {
                    base = 2LL * w[r];
                    if (base > n)
                    {
                        continue;
                    }
                }

                long long rem = n - base;
                vector<int> ranks;

                if (r != -1)
                {
                    ranks.push_back(r);
                    ranks.push_back(r);
                }

                for (int i = maxRank; i >= 0; i--)
                {
                    if (r != -1 && i <= r)
                    {
                        continue;
                    }

                    if (w[i] <= rem)
                    {
                        rem -= w[i];
                        ranks.push_back(i);
                    }
                }

                if (rem == 0)
                {
                    sort(ranks.begin(), ranks.end());
                    answer = ranks;
                    found = true;
                }
            }
        }

        cout << s << " ";
        if (answer.empty())
        {
            cout << "[]\n";
        }
        else
        {
            cout << "[";
            for (int i = 0; i < (int)answer.size(); i++)
            {
                if (i > 0) cout << ",";
                cout << answer[i];
            }
            cout << "]\n";
        }
    }

    return 0;
}

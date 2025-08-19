#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true)
    {
        int n;
        if (!(cin >> n))
        {
            return 0;
        }
        if (n == 0)
        {
            break;
        }

        vector<string> words(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> words[i];
        }

        struct Info
        {
            int count = 0;
            int firstIdx = -1;
            string firstWord;
        };

        unordered_map<string, Info> mp;
        mp.reserve(n * 2);

        for (int i = 0; i < n; ++i)
        {
            string sig = words[i];
            sort(sig.begin(), sig.end());
            auto &g = mp[sig];
            if (g.count == 0)
            {
                g.firstIdx = i;
                g.firstWord = words[i];
            }
            g.count++;
        }

        int bestAnas = -1;
        int bestFirstIdx = n + 1;
        string bestWord;

        for (auto &kv : mp)
        {
            const Info &g = kv.second;
            if (g.count >= 2)
            {
                int ana = g.count - 1;
                if (ana > bestAnas || (ana == bestAnas && g.firstIdx < bestFirstIdx))
                {
                    bestAnas = ana;
                    bestFirstIdx = g.firstIdx;
                    bestWord = g.firstWord;
                }
            }
        }

        cout << bestWord << ' ' << bestAnas << "\n";
    }

    return 0;
}

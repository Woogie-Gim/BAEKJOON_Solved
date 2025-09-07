#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct Info
{
    long long total = 0;
    long long correct = 0;
    string singleEnglish = "";
    bool singleIsCorrect = false;
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    if (!(cin >> n))
    {
        return 0;
    }

    vector<string> sent(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> sent[i];
    }

    int m;
    cin >> m;

    unordered_set<string> need;
    need.reserve(n * 2);
    for (const auto &w : sent)
    {
        need.insert(w);
    }

    unordered_map<string, Info> mp;
    mp.reserve(min(8 * n, m));

    for (int i = 0; i < m; ++i)
    {
        string d, e, flag;
        cin >> d >> e >> flag;

        if (need.find(d) == need.end())
        {
            continue;
        }

        Info &info = mp[d];
        info.total += 1;
        if (flag == "correct")
        {
            info.correct += 1;
        }

        if (info.total == 1)
        {
            info.singleEnglish = e;
            info.singleIsCorrect = (flag == "correct");
        }
    }

    unsigned long long totalWays = 1;
    unsigned long long correctWays = 1;

    for (const auto &w : sent)
    {
        const Info &info = mp[w];
        totalWays *= info.total;
        correctWays *= info.correct;
    }

    if (totalWays == 1)
    {
        for (int i = 0; i < n; ++i)
        {
            if (i)
            {
                cout << ' ';
            }
            cout << mp[sent[i]].singleEnglish;
        }
        cout << '\n';
        if (correctWays == 1)
        {
            cout << "correct\n";
        }
        else
        {
            cout << "incorrect\n";
        }
    }
    else
    {
        cout << correctWays << " correct\n";
        cout << (totalWays - correctWays) << " incorrect\n";
    }

    return 0;
}
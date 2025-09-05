#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    if (!(cin >> n))
    {
        return 0;
    }

    vector<vector<string>> prefs(n);
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        prefs[i].resize(m);
        for (int j = 0; j < m; j++)
        {
            cin >> prefs[i][j];
        }
    }

    unordered_set<string> taken;
    vector<string> chosen;
    chosen.reserve(n);

    for (int i = 0; i < n; i++)
    {
        for (const string& app : prefs[i])
        {
            if (taken.find(app) == taken.end())
            {
                chosen.push_back(app);
                taken.insert(app);
                break;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (i)
        {
            cout << ' ';
        }
        cout << chosen[i];
    }
    cout << '\n';

    return 0;
}

#include <iostream>
#include <vector>

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

    vector<int> s1(N);
    for (int i = 0; i < N; i++)
    {
        cin >> s1[i];
    }

    vector<int> s2;
    vector<pair<int, int>> moves;

    for (int t = N; t >= 1; t--)
    {
        bool in_s1 = false;
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] == t)
            {
                in_s1 = true;
                break;
            }
        }

        if (in_s1)
        {
            while (!s1.empty() && s1.back() != t)
            {
                s2.push_back(s1.back());
                s1.pop_back();
                moves.push_back({1, 2});
            }
            if (!s1.empty())
            {
                s1.pop_back();
                moves.push_back({1, 3});
            }
        }
        else
        {
            while (!s2.empty() && s2.back() != t)
            {
                s1.push_back(s2.back());
                s2.pop_back();
                moves.push_back({2, 1});
            }
            if (!s2.empty())
            {
                s2.pop_back();
                moves.push_back({2, 3});
            }
        }
    }

    cout << moves.size() << "\n";
    for (int i = 0; i < moves.size(); i++)
    {
        cout << moves[i].first << " " << moves[i].second << "\n";
    }

    return 0;
}
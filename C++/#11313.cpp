#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

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

    vector<pair<string, string> > people;
    people.reserve(N);
    for (int i = 0; i < N; ++i)
    {
        string first, last;
        cin >> first >> last;
        people.push_back(make_pair(first, last));
    }

    sort(people.begin(), people.end(),
         [](const pair<string, string> &a, const pair<string, string> &b)
         {
             if (a.second != b.second) return a.second < b.second;
             return a.first < b.first;
         });

    unordered_map<string, int> pos;
    pos.reserve(N * 2);
    for (int i = 0; i < N; ++i)
    {
        string key = people[i].first + '\n' + people[i].second;
        pos[key] = i;
    }

    int Q;
    cin >> Q;
    while (Q--)
    {
        string f, l;
        cin >> f >> l;
        string key = f + '\n' + l;
        int i = pos[key];

        int s = (i / 3) * 3;
        for (int j = s; j < s + 3; ++j)
        {
            if (j == i) continue;
            cout << people[j].first << ' ' << people[j].second << '\n';
        }
    }

    return 0;
}

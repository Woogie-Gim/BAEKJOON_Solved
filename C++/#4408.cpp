#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

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
    string dummy;
    getline(cin, dummy);

    unordered_map<string, string> party_of;
    vector<string> candidates;
    for (int i = 0; i < n; ++i)
    {
        string name, party;
        getline(cin, name);
        getline(cin, party);
        party_of[name] = party;
        candidates.push_back(name);
    }

    int m;
    cin >> m;
    getline(cin, dummy);

    unordered_map<string, int> votes;
    for (int i = 0; i < m; ++i)
    {
        string vote;
        getline(cin, vote);
        if (party_of.find(vote) != party_of.end())
        {
            votes[vote] += 1;
        }
    }

    string winner;
    int best = -1;
    bool tie = false;

    for (size_t i = 0; i < candidates.size(); ++i)
    {
        const string &name = candidates[i];
        int cnt = 0;
        if (votes.find(name) != votes.end())
        {
            cnt = votes[name];
        }

        if (cnt > best)
        {
            best = cnt;
            winner = name;
            tie = false;
        }
        else if (cnt == best)
        {
            tie = true;
        }
    }

    if (tie)
    {
        cout << "tie\n";
    }
    else
    {
        const string &p = party_of[winner];
        if (p == "independent")
        {
            cout << "independent\n";
        }
        else
        {
            cout << p << '\n';
        }
    }

    return 0;
}

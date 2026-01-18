#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <map>
#include <cstdlib>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    string dummy;
    getline(cin, dummy);

    vector<string> cows;
    cows.push_back("Bessie");
    cows.push_back("Buttercup");
    cows.push_back("Belinda");
    cows.push_back("Beatrice");
    cows.push_back("Bella");
    cows.push_back("Blue");
    cows.push_back("Betsy");
    cows.push_back("Sue");

    sort(cows.begin(), cows.end());

    map<string, int> id;
    for (int i = 0; i < 8; i++)
    {
        id[cows[i]] = i;
    }

    vector<pair<int, int> > cons;

    for (int i = 0; i < N; i++)
    {
        string line;
        getline(cin, line);

        stringstream ss(line);
        vector<string> tok;
        string w;
        while (ss >> w)
        {
            tok.push_back(w);
        }

        int a = id[tok[0]];
        int b = id[tok[(int)tok.size() - 1]];
        cons.push_back(make_pair(a, b));
    }

    vector<string> perm = cows;

    do
    {
        int pos[8];
        for (int i = 0; i < 8; i++)
        {
            pos[id[perm[i]]] = i;
        }

        int ok = 1;
        for (int i = 0; i < (int)cons.size(); i++)
        {
            int a = cons[i].first;
            int b = cons[i].second;
            if (abs(pos[a] - pos[b]) != 1)
            {
                ok = 0;
                break;
            }
        }

        if (ok)
        {
            for (int i = 0; i < 8; i++)
            {
                cout << perm[i] << '\n';
            }
            return 0;
        }
    } while (next_permutation(perm.begin(), perm.end()));

    return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    if (!(cin >> n >> k))
    {
        return 0;
    }

    map<string, int> topic_map;
    int topic_count = 0;

    vector<vector<int>> prob_topics(n);

    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;

        for (int j = 0; j < t; j++)
        {
            string s;
            cin >> s;

            if (topic_map.find(s) == topic_map.end())
            {
                topic_map[s] = topic_count;
                topic_count++;
            }

            prob_topics[i].push_back(topic_map[s]);
        }
    }

    vector<int> comb(n, 0);
    for (int i = n - k; i < n; i++)
    {
        comb[i] = 1;
    }

    int valid_contests = 0;
    int max_allowed = k / 2;
    vector<int> freq(topic_count, 0);

    do
    {
        for (int i = 0; i < topic_count; i++)
        {
            freq[i] = 0;
        }

        bool possible = true;

        for (int i = 0; i < n; i++)
        {
            if (comb[i] == 1)
            {
                for (int j = 0; j < (int)prob_topics[i].size(); j++)
                {
                    int t_id = prob_topics[i][j];
                    freq[t_id]++;
                    
                    if (freq[t_id] > max_allowed)
                    {
                        possible = false;
                        break;
                    }
                }
            }

            if (!possible)
            {
                break;
            }
        }

        if (possible)
        {
            valid_contests++;
        }
    }
    while (next_permutation(comb.begin(), comb.end()));

    cout << valid_contests << "\n";

    return 0;
}
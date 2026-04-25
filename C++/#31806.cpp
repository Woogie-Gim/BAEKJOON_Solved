#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    long long m;
    if (!(cin >> n >> m))
    {
        return 0;
    }

    vector<pair<long long, pair<long long, long long>>> slots(n);
    for (int i = 0; i < n; i++)
    {
        cin >> slots[i].second.first >> slots[i].second.second >> slots[i].first;
    }

    sort(slots.begin(), slots.end());

    vector<pair<long long, int>> events;

    int i = 0;
    while (i < n)
    {
        int j = i;
        while (j < n && slots[j].first == slots[i].first)
        {
            j++;
        }

        vector<pair<long long, long long>> intervals;
        for (int k = i; k < j - 1; k++)
        {
            long long r1 = slots[k].second.second;
            long long l2 = slots[k + 1].second.first;

            long long a = l2 - m;
            if (a < 0)
            {
                a = 0;
            }
            long long b = r1 - 1;

            if (a <= b)
            {
                intervals.push_back({a, b});
            }
        }

        if (!intervals.empty())
        {
            sort(intervals.begin(), intervals.end());
            long long curr_a = intervals[0].first;
            long long curr_b = intervals[0].second;

            for (size_t k = 1; k < intervals.size(); k++)
            {
                if (intervals[k].first <= curr_b)
                {
                    if (intervals[k].second > curr_b)
                    {
                        curr_b = intervals[k].second;
                    }
                }
                else
                {
                    events.push_back({curr_a, 1});
                    events.push_back({curr_b + 1, -1});
                    curr_a = intervals[k].first;
                    curr_b = intervals[k].second;
                }
            }
            events.push_back({curr_a, 1});
            events.push_back({curr_b + 1, -1});
        }

        i = j;
    }

    sort(events.begin(), events.end());

    int max_teams = 0;
    int curr_teams = 0;

    for (size_t k = 0; k < events.size(); k++)
    {
        curr_teams += events[k].second;
        if (curr_teams > max_teams)
        {
            max_teams = curr_teams;
        }
    }

    cout << max_teams << "\n";

    return 0;
}
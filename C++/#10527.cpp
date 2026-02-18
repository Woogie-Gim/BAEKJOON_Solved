#include <iostream>
#include <string>
#include <map>

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

    map<string, int> result_counts;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        result_counts[s]++;
    }

    int match_count = 0;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        if (result_counts.find(s) != result_counts.end())
        {
            if (result_counts[s] > 0)
            {
                result_counts[s]--;
                match_count++;
            }
        }
    }

    cout << match_count;

    return 0;
}
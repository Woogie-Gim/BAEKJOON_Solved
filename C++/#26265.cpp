#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector< pair<string, string> > list(N);

    for (int i = 0; i < N; i++)
    {
        cin >> list[i].first >> list[i].second;
    }

    sort(list.begin(), list.end(),
        [](pair<string, string> a, pair<string, string> b)
        {
            if (a.first < b.first)
            {
                return true;
            }
            if (a.first > b.first)
            {
                return false;
            }
            return a.second > b.second;
        });

    for (int i = 0; i < N; i++)
    {
        cout << list[i].first << " " << list[i].second << "\n";
    }

    return 0;
}

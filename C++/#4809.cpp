#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int k1;
    int k2;
    int caseNumber = 1;

    while (true)
    {
        cin >> n >> k1 >> k2;
        if (!cin)
        {
            return 0;
        }

        if (n == 0 && k1 == 0 && k2 == 0)
        {
            break;
        }

        vector< pair<long long, int> > data(n);

        for (int i = 0; i < n; i++)
        {
            long long price;
            cin >> price;
            data[i].first = price;
            data[i].second = i + 1;
        }

        sort(data.begin(), data.end(),
            [](pair<long long, int> a, pair<long long, int> b)
            {
                if (a.first < b.first)
                {
                    return true;
                }
                if (a.first > b.first)
                {
                    return false;
                }
                return a.second < b.second;
            });

        vector<int> lowDays;
        vector<int> highDays;

        for (int i = 0; i < k1; i++)
        {
            lowDays.push_back(data[i].second);
        }

        for (int i = 0; i < k2; i++)
        {
            highDays.push_back(data[n - 1 - i].second);
        }

        sort(lowDays.begin(), lowDays.end());

        sort(highDays.begin(), highDays.end(),
            [](int a, int b)
            {
                return a > b;
            });

        cout << "Case " << caseNumber << "\n";

        for (int i = 0; i < (int)lowDays.size(); i++)
        {
            if (i > 0)
            {
                cout << " ";
            }
            cout << lowDays[i];
        }
        cout << "\n";

        for (int i = 0; i < (int)highDays.size(); i++)
        {
            if (i > 0)
            {
                cout << " ";
            }
            cout << highDays[i];
        }
        cout << "\n";

        caseNumber++;
    }

    return 0;
}

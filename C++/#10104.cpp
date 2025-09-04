#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int K;
    if (!(cin >> K))
    {
        return 0;
    }

    int m;
    cin >> m;

    vector<int> a;
    a.reserve(K);
    for (int i = 1; i <= K; ++i)
    {
        a.push_back(i);
    }

    for (int i = 0; i < m; ++i)
    {
        int r;
        cin >> r;

        vector<int> next;
        next.reserve(a.size());

        for (int pos = 1; pos <= (int)a.size(); ++pos)
        {
            if (pos % r != 0)
            {
                next.push_back(a[pos - 1]);
            }
        }

        a.swap(next);
    }

    for (int x : a)
    {
        cout << x << '\n';
    }

    return 0;
}

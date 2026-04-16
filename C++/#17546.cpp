#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    if (!(cin >> n >> m))
    {
        return 0;
    }

    vector<int> set1;
    vector<int> set2;

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        
        if (u < v)
        {
            set1.push_back(i);
        }
        else
        {
            set2.push_back(i);
        }
    }

    if (set1.size() <= set2.size())
    {
        cout << set1.size() << "\n";
        for (int i = 0; i < set1.size(); i++)
        {
            cout << set1[i] << "\n";
        }
    }
    else
    {
        cout << set2.size() << "\n";
        for (int i = 0; i < set2.size(); i++)
        {
            cout << set2[i] << "\n";
        }
    }

    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v(9);

    int total = 0;

    for (int i = 0; i < 9; ++i) 
    {
        cin >> v[i];
        total += v[i];
    }

    sort(v.begin(), v.end());

    int s = 0;
    int e = 8;

    while (s < e) 
    {
        if (v[s] + v[e] == total - 100) 
        {
            for (int i = 0; i < 9; ++i) 
            {
                if (i == s || i == e) 
                {
                    continue;
                }
                cout << v[i] << endl;
            }

            break;
        }
        else if (v[s] + v[e] < total - 100) 
        {
            s++;
        }
        else 
        {
            e--;
        }
    }

    return 0;
}

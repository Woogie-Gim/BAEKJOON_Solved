#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, t;
    if (!(cin >> n >> t))
    {
        return 0;
    }

    vector<int> ops;
    int q = t / n;
    int r = t % n;

    for (int i = 0; i < q; i++)
    {
        ops.push_back(n);
    }
    if (r > 0)
    {
        ops.push_back(r);
    }

    string s = "";
    for (int i = 0; i < n; i++)
    {
        s += (char)('a' + i);
    }

    cout << ops.size() << "\n";
    for (int i = 0; i < ops.size(); i++)
    {
        int idx = ops[i] - 1;
        char c = s[idx];
        
        cout << c << (i == ops.size() - 1 ? "" : " ");
        
        s.erase(s.begin() + idx);
        s.insert(s.begin(), c);
    }
    cout << "\n";

    return 0;
}
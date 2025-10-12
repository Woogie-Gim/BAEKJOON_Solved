#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t1, t2, t3, t4;
    if (!(cin >> t1)) return 0;
    cin >> t2 >> t3 >> t4;

    int total = t1 + t2 + t3 + t4 + 300;

    if (total <= 1800)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }

    return 0;
}

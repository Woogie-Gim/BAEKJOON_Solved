#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t1;
    int v1;
    int t2;
    int v2;

    cin >> t1 >> v1;
    cin >> t2 >> v2;

    if (t2 < 0 && v2 >= 10)
    {
        cout << "A storm warning for tomorrow! Be careful and stay home if possible!";
    }
    else if (t2 < t1)
    {
        cout << "MCHS warns! Low temperature" << "\n" << "is expected tomorrow.";
    }
    else if (v2 > v1)
    {
        cout << "MCHS warns! Strong wind is expected tomorrow.";
    }
    else
    {
        cout << "No message";
    }

    return 0;
}

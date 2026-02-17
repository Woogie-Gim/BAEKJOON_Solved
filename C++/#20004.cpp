#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int A;
    
    if (!(cin >> A))
    {
        return 0;
    }

    for (int n = 1; n <= A; n++)
    {
        if (30 % (n + 1) == 0)
        {
            cout << n << "\n";
        }
    }

    return 0;
}
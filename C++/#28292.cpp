#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    if (N <= 2)
    {
        cout << 1 << '\n';
    }
    else if (N <= 5)
    {
        cout << 2 << '\n';
    }
    else
    {
        cout << 3 << '\n';
    }

    return 0;
}

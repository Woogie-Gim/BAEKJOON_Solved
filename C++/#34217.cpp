#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int A, B;
    int C, D;

    if (!(cin >> A >> B))
    {
        return 0;
    }
    cin >> C >> D;

    int hy = A + C;
    int yd = B + D;

    if (hy < yd)
    {
        cout << "Hanyang Univ.\n";
    }
    else if (hy > yd)
    {
        cout << "Yongdap\n";
    }
    else
    {
        cout << "Either\n";
    }

    return 0;
}

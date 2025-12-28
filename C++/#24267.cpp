#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n;
    cin >> n;

    long long count = n * (n - 1) * (n - 2) / 6;

    cout << count << '\n';
    cout << 3 << '\n';

    return 0;
}

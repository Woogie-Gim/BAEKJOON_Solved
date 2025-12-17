#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    unsigned long long N;
    cin >> N;

    unsigned long long diff = (~N) + 1; // 2^64 - N

    int power = 0;
    while ((1ULL << power) != diff)
    {
        power++;
    }

    int K = 64 - power;
    cout << K << '\n';

    return 0;
}

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long N;
    int F;
    cin >> N >> F;

    long long base = N - (N % 100);

    for (int i = 0; i < 100; i++)
    {
        if ((base + i) % F == 0)
        {
            cout << setw(2) << setfill('0') << i << "\n";
            return 0;
        }
    }

    return 0;
}

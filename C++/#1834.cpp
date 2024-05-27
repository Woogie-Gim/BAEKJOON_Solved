#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long N;

    cin >> N;

    long long result = (N - 1) * N / 2;

    result *= (N + 1);

    cout << result << "\n";

    return 0;
}
#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
    long long N;
    cin >> N;

    int l = static_cast<int>(floor(log10(N)));

    long long answer = (l + 1) * (N + 1) + ((1 - static_cast<long long>(pow(10, l + 1))) / 9);

    cout << answer % 1234567 << "\n";

    return 0;
}
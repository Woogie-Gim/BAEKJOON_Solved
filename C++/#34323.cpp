#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long N, M, S;
    cin >> N >> M >> S;

    long long totalPrice = (M + 1) * S;
    long long discountPrice = totalPrice * (100 - N) / 100;
    long long freePrice = M * S;

    cout << min(discountPrice, freePrice);

    return 0;
}

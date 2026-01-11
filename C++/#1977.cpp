#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int M, N;
    cin >> M >> N;

    int start = (int)ceil(sqrt((double)M));
    int end = (int)floor(sqrt((double)N));

    if (start > end)
    {
        cout << -1 << '\n';
        return 0;
    }

    int sum = 0;
    int mn = start * start;

    for (int i = start; i <= end; i++)
    {
        sum += i * i;
    }

    cout << sum << '\n';
    cout << mn << '\n';
    
    return 0;
}

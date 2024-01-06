#include <iostream>
#include <algorithm>

using namespace std;

int main() 
{
    int n, m, k;
    cin >> n >> m >> k;

    int count = min(m, n / 2);
    count = min(count, (n + m - k) / 3);

    cout << count;

    return 0;
}

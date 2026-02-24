#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string A_str;
    long long B;

    if (!(cin >> A_str >> B))
    {
        return 0;
    }

    sort(A_str.begin(), A_str.end());
    reverse(A_str.begin(), A_str.end());

    long long ans = -1;

    do
    {
        if (A_str[0] == '0')
        {
            break;
        }

        long long val = stoll(A_str);

        if (val < B)
        {
            ans = val;
            break;
        }

    }
    while (prev_permutation(A_str.begin(), A_str.end()));

    cout << ans << "\n";

    return 0;
}
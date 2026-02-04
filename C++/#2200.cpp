#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int leading_coeff;
    cin >> leading_coeff;

    long long total_keys = 0;

    total_keys = 1 + 1 + (long long)(N - 1) * 2;

    for (int i = 0; i < N; i++)
    {
        int coeff;
        cin >> coeff;

        if (coeff > 0)
        {
            string s = to_string(coeff);
            total_keys += (1 + s.length());
        }
    }

    cout << total_keys;

    return 0;
}
#include <iostream>

using namespace std;

long long days_in_year_prefix(int y)
{
    int years = y - 1;
    long long leap = years / 3;
    long long common = years - leap;
    return leap * 200LL + common * 195LL;
}

long long days_in_months_prefix(int y, int m)
{
    int prev = m - 1;
    if (y % 3 == 0)
    {
        return 20LL * prev;
    }
    else
    {
        long long odd = (prev + 1) / 2;
        long long even = prev - odd; 
        return odd * 20LL + even * 19LL;
    }
}

long long serial_days(int Y, int M, int D)
{
    long long res = 0;
    res += days_in_year_prefix(Y);
    res += days_in_months_prefix(Y, M);
    res += (D - 1);
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    if (!(cin >> n))
    {
        return 0;
    }

    const long long target = serial_days(1000, 1, 1);

    while (n--)
    {
        int Y, M, D;
        cin >> Y >> M >> D;
        long long born = serial_days(Y, M, D);
        cout << (target - born) << '\n';
    }

    return 0;
}

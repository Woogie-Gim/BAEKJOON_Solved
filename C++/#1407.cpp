#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long a, b;

long long solve(long long num) 
{
    long long ans = 0, temp = 1;
    while (num != 0) 
    {
        if (num % 2 != 0) 
            ans += ((num / 2) + 1) * temp;
        else 
            ans += (num / 2) * temp;

        num /= 2;
        temp *= 2;
    }
    return ans;
}

int main() 
{
    cin >> a >> b;
    cout << solve(b) - solve(a - 1);
    return 0;
}

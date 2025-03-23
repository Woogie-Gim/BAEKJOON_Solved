#include <iostream>

using namespace std;

float a, m, n, answer;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cout << fixed;
    cout.precision(7);
    
    cin >> a >> m >> n;
    
    if (m > n)
    {
        swap(m, n);
    }

    answer = max(m, n / a);           
    answer = min((m / a) * 2, answer); 

    cout << answer;
    
    return 0;
}
#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int A, B, C, D, E;
    cin >> A;
    cin >> B;
    cin >> C;
    cin >> D;
    cin >> E;

    long long answer = 0;

    if (A < 0)
    {
        answer += (long long)(-A) * C;
        answer += D;
        answer += (long long)B * E;
    }
    else
    {
        answer += (long long)(B - A) * E;
    }

    cout << answer << '\n';
    
    return 0;
}

#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long N;
    
    if (!(cin >> N))
    {
        return 0;
    }

    if (N % 2 == 0)
    {
        cout << "Song\n";
    }
    else
    {
        cout << "Soomin\n";
    }

    return 0;
}
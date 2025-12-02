#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long sCount;
    long long aCount;
    cin >> sCount >> aCount;

    long long maxS = sCount / 2;
    long long maxA = aCount / 2;

    long long result;
    if (maxS < maxA)
    {
        result = maxS;
    }
    else
    {
        result = maxA;
    }

    cout << result;
    
    return 0;
}

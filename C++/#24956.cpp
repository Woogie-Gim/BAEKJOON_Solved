#include <iostream>
#include <string>

using namespace std;

int main() 
{
    int N;
    long long w = 0, wh = 0, whe = 0, whee = 0;
    const long long MOD = 1000000007;

    cin >> N;
    string S;
    cin >> S;

    for (int i = 0; i < N; i++) 
    {
        if (S[i] == 'W') 
        {
            w += 1;
        } 
        else if (S[i] == 'H') 
        {
            wh += w;
        } 
        else if (S[i] == 'E') 
        {
            whee = 2 * whee;
            whee += whe;
            whee %= MOD;
            whe += wh;
        }
    }

    cout << whee << "\n";

    return 0;
}

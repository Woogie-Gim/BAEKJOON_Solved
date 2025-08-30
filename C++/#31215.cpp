#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    
    long long T, N;
    
    cin >> T;
        
    while (cin >> N)
    {
        if (N <= 2) cout << "1\n";
        else cout << "3\n";
    }
}
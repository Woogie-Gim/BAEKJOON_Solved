#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    
    int N, i;
    
    cin >> N;
    
    for (i = 1; i <= N; i += 2)
    {
        cout << i << ' ';
    }
    
    if (N % 2 == 0) i = N;
    else i = N - 1;
    
    for (i; i >= 1; i -= 2)
        cout << i << ' ';
}
#include <iostream>

using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "-1 -1\n";
    
    for (int i = 0; i < 813; i++) 
    {
        cout << 10 * i << " " << 10 * i << "\n";
    }
    
    return 0;
}
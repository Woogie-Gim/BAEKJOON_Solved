#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    
    cin >> n;
    
    for (int i = 1; i <= n; i++)
    {
        cout << "Hello World, Judge " << i << "!\n";
    }
}
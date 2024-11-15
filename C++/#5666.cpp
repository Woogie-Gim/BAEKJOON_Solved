#include <iostream>
 
using namespace std;
 
int main()
{
    float h, p;
 
    while (1) 
    {
        cin >> h >> p;
        
        if (cin.eof() == 1) break;
        
        cout << fixed;
        cout.precision(2);
        cout << h / p << "\n";
    }
 
    return 0;
}
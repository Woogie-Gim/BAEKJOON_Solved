#include <iostream>
 
using namespace std;
 
int main()
{
    int t;
    cin >> t;
 
    for (int i = 0; i < t; i++) 
    {
        int candy, people;
        cin >> candy >> people;
 
        cout << "You get " << candy / people << " piece(s) and your dad gets " 
            << candy % people << " piece(s)." << "\n";
 
    }
 
    return 0;
}
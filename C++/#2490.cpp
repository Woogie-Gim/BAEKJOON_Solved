#include <iostream>
 
using namespace std;
 
int main()
{
    for (int i = 0; i < 3; i++) 
    {
        int total = 0;
 
        for (int j = 0; j < 4; j++) 
        {
            int num;
            cin >> num;
            total += num;
        }
 
        if (total == 0)
        {
            cout << "D" << "\n";
        }
        else if (total == 1) 
        {
            cout << "C" << "\n";
        }
        else if (total == 2)
        {
            cout << "B" << "\n";
        }
        else if (total == 3) 
        {
            cout << "A" << "\n";
        }
        else if (total == 4) 
        {
            cout << "E" << "\n";
        }
    }
 
    return 0;
}
#include <iostream>

using namespace std;

int main()
{
    int t;
    
    int dir = 0;
    
    for (int i = 0; i < 10; i++)
    {
        cin >> t;
        
        if (t == 1)
        {
            dir = (dir + 1) % 4;
        }
        else if (t == 2)
        {
            dir = (dir + 2) % 4;
        }
        else if (t == 3)
        {
            dir = (dir + 3) % 4;
        }
    }
    
    if (dir == 0)
    {
        cout << "N";
    }
    else if (dir == 1)
    {
        cout << "E";
    }
    else if (dir == 2)
    {
        cout << "S";
    }
    else if (dir == 3)
    {
        cout << "W";
    }
    
    return 0;
}
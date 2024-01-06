#include <iostream>

using namespace std;

int main()
{
    int room[3], n;

    for (int i = 0; i < 3; ++i) 
    {
        cin >> room[i];
    } 
    
    cin >> n;

    for (int i = 0; i <= n / room[2]; i++) 
    {
        int c = i * room[2];

        for (int j = 0; j <= n / room[1]; j++) 
        {
            int c2 = c + j * room[1];
            for (int k = 0; k <= n / room[0]; k++) 
            {
                int c3 = c2 + k * room[0];
                if (c3 == n) 
                {
                    cout << 1;
                    return 0;
                }
            }
        }
    }
    cout << 0;

    return 0;
}
#include <iostream>

#define INT_MIN 1 << 31

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int num = 0, interval = 0;
    
    int count = 0, time = 0, last_clap = INT_MIN;

    cin >> num >> interval;
    
    for (int i = 0; i < num; i++) 
    {
        cin >> time;
        if (last_clap + interval < time)
        {
            count++;
            last_clap = time;
        }
    }
    cout << count << "\n";

    return 0;
}
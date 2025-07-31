#include <iostream>

using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, cost = 0;;
    cin >> N;

    while (N--) 
    {
        string s;
        int n;
        cin >> s >> n;

        int time = (s[0] - '0') * 600 + (s[1] - '0') * 60 + (s[3] - '0') * 10 + (s[4] - '0');

        while (n--) 
        {
            if (420 <= time && time < 1140) cost += 10;
            else cost += 5;

            time++;

            if (time == 1440) time = 0;
        }
    }

    cout << cost << '\n';

    return 0;
}
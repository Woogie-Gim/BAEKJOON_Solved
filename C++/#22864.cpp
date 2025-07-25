#include <iostream>

using namespace std;

int a, b, c, m;
int answer;
int pirodo;

int main()
{
    cin >> a >> b >> c >> m;

    int n = 24;

    while(n--)
    {
        if(pirodo + a <= m)
        { 
            answer += b;
            pirodo += a;
        }
        else
        {
            pirodo -= c;
            if(pirodo < 0)
            {
                pirodo = 0;

            }
        }
    }
    cout << answer << "\n";
}
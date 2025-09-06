#include <iostream>
#include <string>

using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long total = 0;
    
    for (int i = 0; i < 4; ++i) 
    {
        string type;
        long long x;
        if (!(cin >> type >> x)) return 0; 

        if (type == "Es")       total += 21 * x;
        else if (type == "Stair") total += 17 * x;
    }

   cout << total << '\n';
    
    return 0;
}

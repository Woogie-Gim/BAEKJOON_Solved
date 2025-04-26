#include <iostream>
#include <bitset>
 
using namespace std;
 
int n;
long long m;
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
 
    cin >> n;
 
    for (int i = 0; i < n; i++)
    {
        cin >> m;
 
        bitset<60> temp = m;
 
        if (temp.count() == 1)
        {
            for (int j = 0; j < 60; j++)
            {
                if (temp.test(j))
                {
                    cout << j - 1 << " " << j - 1;
                    break;
                }
            }
        }
        else
        {
            for (int j = 0; j < 60; j++)
            {
                if (temp.test(j))
                {
                    cout << j << " ";
                }
            }
        }
        cout << '\n';
    }
 
 
    return 0;
}
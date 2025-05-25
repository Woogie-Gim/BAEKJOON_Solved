#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int flat = 0, up = 0, down = 0;
    int count;
    
    cin >> count;

    vector<int> a(count + 1);
    
    cin >> a[0];

    int flag = 0;

    for (int i = 1; i <= count; ++i)
    {
        if (i < count) 
        {
            cin >> a[i];
        } 
        else 
        {
            a[i] = a[0];
        }

        if (a[i] == a[i - 1] && flag != 1) 
        {
            flat++;
            flag = 1;
        } 
        else if (a[i] > a[i - 1] && flag != 2) 
        {
            up++;
            flag = 2;
        } 
        else if (a[i] < a[i - 1] && flag != 3) 
        {
            down++;
            flag = 3;
        }
    }

    cout << flat << " " << up << " " << down << '\n';
    
    return 0;
}

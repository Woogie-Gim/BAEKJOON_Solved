#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> ans(30000001);
    vector<int> arr(1000001);
    int temp;
    bool chk;

    for (int i = 0; i < 10; ++i) 
    {
        ans[i] = (1 << i);
        arr[i] = i;
    }
    int i = 10;
    int index = 10;
    while (true) 
    {
        if (ans[i / 10] == 0) 
        {
            ++i;
            continue;
        }
        if ((ans[i / 10] & ans[i % 10]) == 0) 
        {
            ans[i] = ans[i / 10] | ans[i % 10];
            arr[index] = i;
            index++;
        }
        i++;
        if (index > 1000000) 
        {
            break;
        }
    }
    while (true) 
    {
        int n;
        cin >> n;
        if (n == 0) 
        {
            break;
        }
        cout << arr[n] << '\n';
    }

    return 0;
}
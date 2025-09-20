#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> a(20);
    
    for (int i = 0; i < 20; i++)
    {
        cin >> a[i];
    }

    int idx = 0;
    
    for (int i = 0; i < 20; i++)
    {
        if (a[i] == 20)
        {
            idx = i;
            break;
        }
    }

    int left = a[(idx + 19) % 20];
    int mid = 20;
    int right = a[(idx + 1) % 20];

    int sum3 = left + mid + right;      
    int lhs = 20 * sum3;
    int rhs = 3 * 210; 

    if (lhs > rhs)
    {
        cout << "Alice\n";
    }
    else if (lhs < rhs)
    {
        cout << "Bob\n";
    }
    else
    {
        cout << "Tie\n";
    }

    return 0;
}

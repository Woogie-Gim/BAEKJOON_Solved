#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    if (!(cin >> n))
    {
        return 0;
    }

    vector<int> a(n);
    vector<int> unicorn_indices;
    vector<int> unicorn_choice(n, 0);
    vector<int> inventory(1001, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
        {
            inventory[a[i]]++;
        }
        else if (a[i] == 0)
        {
            unicorn_indices.push_back(i);
        }
        else
        {
            int req = -a[i];
            
            if (inventory[req] > 0)
            {
                inventory[req]--;
            }
            else if (!unicorn_indices.empty())
            {
                int idx = unicorn_indices.back();
                unicorn_indices.pop_back();
                unicorn_choice[idx] = req;
            }
            else
            {
                cout << "No\n";
                return 0;
            }
        }
    }

    cout << "Yes\n";
    
    bool first = true;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            if (!first)
            {
                cout << " ";
            }
            
            if (unicorn_choice[i] == 0)
            {
                cout << 1;
            }
            else
            {
                cout << unicorn_choice[i];
            }
            
            first = false;
        }
    }
    cout << "\n";

    return 0;
}
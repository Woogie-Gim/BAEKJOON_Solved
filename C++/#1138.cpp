#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    
    cin>>n;
    
    vector<int> people(n, 0);
    
    for(int i = 1; i <= n; i++)
    {
        int temp = 0;
        cin >> temp;
        
        for(int j = 0; j < n; j++)
        {
            if(temp == 0 && people[j] == 0)
            {
                people[j] = i;
                break;
            }
            if(people[j] == 0 )
            {
                temp--;
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        cout << people[i] << " ";
    }

    return 0;
}
# include <iostream>

using namespace std;
 
int main()
{
    int n, p;
    cin >> n;
 
 
    for (int i = 0; i < n; i++)
    {
        cin >> p;
        
        int a;
        string b;
 
        int maxnum = 0;
        string ans;
        
        for (int j = 0; j < p; j++)
        {
            cin >> a >> b;
            
            if (a > maxnum)
            {
                maxnum = a;
                ans = b;
            }
        }
        cout << ans << "\n";
    }
 
    return 0;
}
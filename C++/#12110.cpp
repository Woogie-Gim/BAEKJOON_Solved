#include <iostream>

using namespace std;

const int MAX = 300001;

int N, D;
bool phone[MAX];

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> D;

    for (int i = 0; i < N; i++)
    {
        cin >> phone[i];
    }

    int result = 0; 
    int cnt = 0; 

    for (int i = 0; i < N; i++) 
    {
        if (phone[i]) 
        {
            cnt = 0;
        } 
        else 
        {
            cnt++;
            
            if (cnt == D) 
            {
                result++;
                cnt = 0; 
            }
        }
    }

    cout << result << "\n";
    
    return 0;
}

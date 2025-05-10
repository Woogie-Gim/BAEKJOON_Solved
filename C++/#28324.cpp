#include <iostream>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 987654321;

ll arr[500002];

int main()
{
    ios_base::sync_with_stdio(0); 
	cin.tie(0);
    
    ll N;
    cin >> N;

    for(int i=1; i<=N; i++)
    {
        cin >> arr[i];
    }

    ll sum = 0, tmp = 0;

    for(int i = N; i >= 1; i--)
    {
        tmp = min(tmp+1, arr[i]);
        sum += tmp;
    }

    cout << sum;

    return 0;
}
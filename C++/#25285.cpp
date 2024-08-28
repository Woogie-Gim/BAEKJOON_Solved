#include <iostream>

using namespace std;

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; 
    cin >> T;
    
	while (T--)
    {
        int h, w; cin >> h >> w;
        if (h < 141) cout << 6 << '\n';
        else if (h < 146) cout << 5 << '\n';
        else if (h < 159) cout << 4 << '\n';
        else if (h < 161) 
        {
            if (10000 * w >= 35 * h * h || 10000 * w < 16 * h * h) cout << 4 << '\n';
            else cout << 3 << '\n';
        }
        else if (h < 204)
        {
            if (10000 * w >= 35 * h * h || 10000 * w < 16 * h * h) cout << 4 << '\n';
            else if (10000 * w >= 30 * h * h || 100000 * w < 185 * h * h) cout << 3 << '\n';
            else if (10000 * w >= 25 * h * h || 10000 * w < 20 * h * h) cout << 2 << '\n';
            else cout << 1 << '\n';
        }
        else cout << 4 << '\n';
    }
}
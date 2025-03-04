#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
    
	while (T--) 
    {
		int x; cin >> x;
		int cnt = 0;
        
		while (x != 6174) 
        {
			string xx = to_string(x);
			while (xx.length() != 4) xx = "0" + xx;
			sort(xx.begin(), xx.end());
			
			string y = xx;
			reverse(y.begin(), y.end());

			x = abs(stoi(y) - stoi(xx));
			cnt++;
		}

		cout << cnt << '\n';
	}
}
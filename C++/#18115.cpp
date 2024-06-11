#include <iostream>
#include <vector>

using namespace std;

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    
	int n, action;
    
	cin >> n;
    
	vector<int> res(n, 0);
    
	int top=0, middle= n == 1 ? 0 : 1, bottom=n-1;
    
	for (int i=n; i>0; i--) 
    {
		cin >> action;
		if (action == 1) 
        {
			res[top] = i;
			top = middle++;
		} 
        else if (action == 2) 
        {
			res[middle++] = i;
		} 
        else 
        {
			res[bottom--] = i;
		}
		if (middle > bottom) 
        {
			middle = top;
			bottom = top;
		}
	}
	for (auto r : res) 
    {
		cout << r << " ";
	}
}
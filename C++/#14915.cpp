#include <iostream>
#include <stack>

using namespace std;

int M, N;

stack<int> stk;
char arr[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> M >> N;
	if (M == 0) 
    {
        cout << 0;
    }
	else 
    {
		while (M) 
        {
			stk.push(M % N);
			M /= N;
		}
        
		while (!stk.empty()) 
        {
			cout << arr[stk.top()];
			stk.pop();
		}
	}
}
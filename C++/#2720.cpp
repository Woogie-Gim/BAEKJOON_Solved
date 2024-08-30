#include <iostream>

using namespace std;

int main() 
{
	int T; int Q; int D; int N; int P;
    
	cin >> T;
    
	int* arr = new int[T];
    
	for (int i = 0; i < T; ++i)
	{
		cin >> arr[i];
		Q = arr[i] / 25;
		P = arr[i] % 25;
		D = P / 10;
		P %= 10;
		N = P / 5;
		P %= 5;
		cout << Q << " " << D << " " << N << " " << P << "\n";
	}
}
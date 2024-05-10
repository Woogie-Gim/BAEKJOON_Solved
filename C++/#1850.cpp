#include <iostream>

using namespace std;

long long gcd(long long a, long long b)
{
	long long tmp, n;
	if(a<b)
	{
		tmp = a;
		a = b;
		b = tmp;
	}
	while(b!=0)
	{
		n = a%b;
		a = b;
		b = n;
	}
	return a;
}

int main()
{
	long long A,B,C,i;
	cin >> A >> B;
	C = gcd(A,B);
	
	for(i=0;i<C;i++)
		cout << 1;
	
	return 0;
}
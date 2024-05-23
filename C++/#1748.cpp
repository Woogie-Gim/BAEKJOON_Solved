#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() 
{
	long long N;
	long long tmpN;
	long long result = 0;
	int digit = 0;
	string num = "9";

	cin >> N;
	tmpN = N;

	while (tmpN > 0) 
    {
		digit++;
		tmpN /= 10;
	}

	if (digit == 1) 
    {
		cout << N;
	}
    
	else 
    {
		for (int i = 2; i < digit; i++) 
        {
			num += "9";
		}
		
		result += (N - stoi(num)) * digit;
        
		while (digit > 1) 
        {
			result += (9 * pow(10, digit - 2)) * (digit - 1);
			digit--;
		}
		cout << result;
	}

	return 0;
}
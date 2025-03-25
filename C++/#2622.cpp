#include <iostream>

using namespace std;

int main() 
{
	
	int a, b, c;
	int torch, count=0;
	cin >> torch;
	a = torch - 2;
    
	for(c = 1; c <= a; c++)
    {
		for(b = 1; b <= a; b++) 
        {
			a = torch - (b + c);			
			if((a >= b && b >= c) && a < (b + c)) count++;
		}
	}
	
	cout << count << "\n";
	
	return 0;
}
#include <iostream>
 
using namespace std;
 
int main() 
{
	int A, B, C;
	cin >> A >> B >> C;
 
	int min = 60 * A + B;
	min += C;
 
	int hour = (min / 60) % 24;
	int minute = min % 60;
 
	cout << hour << " " << minute;
	return 0;
}
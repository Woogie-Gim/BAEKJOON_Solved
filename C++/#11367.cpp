#include <iostream>

using namespace std;

int main() 
{
	int n, score;
	string name;
	cin >> n;

	for (int i = 0; i < n; i++) 
    {
		cin >> name >> score;
		if (score >= 97) 
        {
			cout << name << " A+\n";
		}
		else if (score >= 90) 
        {
			cout << name << " A\n";
		}
		else if (score >= 87) 
        {
			cout << name << " B+\n";
		}
		else if (score >= 80) 
        {
			cout << name << " B\n";
		}
		else if (score >= 77) 
        {
			cout << name << " C+\n";
		}
		else if (score >= 70) 
        {
			cout << name << " C\n";
		}
		else if (score >= 67) 
        {
			cout << name << " D+\n";
		}
		else if (score >= 60) 
        {
			cout << name << " D\n";
		}
		else 
        {
			cout << name << " F\n";
		}
	}

	return 0;
}
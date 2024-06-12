#include <iostream>

using namespace std;

int main() 
{
	int T;
    
	cin >> T;
    
	for (int i = 0; i < T; i++) 
    {
		int num = 0;
        
		cin >> num;
        
		string s = "";
        
		cin >> s;
        
		for (int j = 0; j < s.length(); j++) 
        {
			if (j == num-1) 
            {
				continue;
			}
			cout << s[j];
		}
		cout << "\n";
	}
}
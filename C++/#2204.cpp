#include <iostream>

using namespace std;

string a;
string origin[1001];

int main() 
{
	int N = 1;
	int ans_index = 0;
    
	while (true) 
    {
		cin >> N;
		string dobiisfree = "zzzzzzzzzzzzzzzzzzzzzzzzzzzz";
		if (N == 0) 
        {
			break;
		}
		for (int i = 0; i < N; ++i) 
        {
			cin >> a;
			origin[i] = a;
            
			for (int j = 0; j < a.size(); ++j)
            {
				a[j] = toupper(a[j]);
			}
			for (int j = 0; j < dobiisfree.size(); ++j)
            {
				dobiisfree[j] = toupper(dobiisfree[j]);
			}
			if (dobiisfree > a)
            {
				dobiisfree = origin[i];
				ans_index = i;
			}
		}		
        
		cout << origin[ans_index] << '\n';
	}

	return 0;
}
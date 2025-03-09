#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;

	vector<string> name;

	cin >> n;

	for (int i = 0; i < n; i++) 
    {
		string str;

		cin >> str;

		if (str.size() == 3)
        {
			name.push_back(str);
		}
	}

	sort(name.begin(), name.end());

	cout << name[0]; 

	return 0;
}
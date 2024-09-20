#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int* arr = new int[3];
	vector<string> ans;

	while (true)
	{		
		int largestN = 0;
		int sum = 0;

		for (int i = 0; i < 3; i++)
		{
			cin >> arr[i];

			sum += arr[i];
			if (arr[i] >= largestN) largestN = arr[i];
		}
		
		if (arr[0] == 0 || arr[1] == 0 || arr[2] == 0) break;

		sum -= largestN;

		if (largestN >= sum) ans.push_back("Invalid");
		else if (sum / largestN == 2) ans.push_back("Equilateral");
		else if (arr[0] == arr[1] || arr[1] == arr[2] || arr[0] == arr[2]) ans.push_back("Isosceles");
		else ans.push_back("Scalene");
	}
	
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << "\n";
	}

	return 0;
}
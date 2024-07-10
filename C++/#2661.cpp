#include<iostream>
#include<string>

using namespace std;

int endFlag = 0;
int N;

bool isValid(string result) 
{
	int len = result.size();
	int end = len - 1;

	for (int i = 1; i <= len / 2; i++)
    {
		string a = result.substr(end - i, i);
		string b = result.substr(end, i);
		if (!a.compare(b)) return false;
		end--;
	}
	return true;
}

void dfs(int step, string result) 
{
	if (endFlag == 1) return;
	if (!isValid(result)) return;
	if (step == N) 
    {
		cout << result << '\n';
		endFlag = 1;
		return;
	}
	dfs(step + 1, result + '1');
	dfs(step + 1, result + '2');
	dfs(step + 1, result + '3');
}

int main() 
{

	cin >> N;
	dfs(0, "");

	return 0;
}
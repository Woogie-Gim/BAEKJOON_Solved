#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(string message, vector<vector<int>> spoiler_ranges) {
	int answer = 0;

	bool isS;
	int start = 0, end = message.find(" ");
	unordered_set<string> spoilers, notS;

	while (start < message.length())
	{
		if (end == string::npos)
			end = message.length();

		string word = message.substr(start, end - start);

		if (word != "")
		{
			isS = false;

			for (int i = 0; i < spoiler_ranges.size(); ++i)
			{
				if ((start <= spoiler_ranges[i][1]) && ((end - 1) >= spoiler_ranges[i][0]))
				{
					isS = true;
					break;
				}
			}

			if (isS)
				spoilers.insert(word);
			else
				notS.insert(word);
		}

		start = end + 1;
		end = message.find(" ", start);		
	}

	for (auto iter = spoilers.begin(); iter != spoilers.end(); ++iter)
	{
		if (notS.find(*iter) == notS.end())
			++answer;
	}

	return answer;
}
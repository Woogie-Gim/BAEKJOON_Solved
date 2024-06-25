#include<iostream>

using namespace std;

int land[501][501];

int main()
{
	int mint = 99999999;
	int minh = 99999999;
	int time;
	int N, M, B;
	cin >> N >> M >> B;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> land[i][j];

	for (int h = 0; h <= 256; h++)
	{
		int remove = 0;
		int stack = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (land[i][j] > h)
					remove += land[i][j] - h;
				else if (land[i][j] == h)
					continue;
				else if (land[i][j] < h)
					stack += h - land[i][j];
			}
		}
		if (remove + B >= stack)
		{
			time = remove * 2 + stack;
			if (time <= mint)
			{
				mint = time;
				minh = h;
			}
		}
	}
	cout << mint << ' ' << minh;
	return 0;
}
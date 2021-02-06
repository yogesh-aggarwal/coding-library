#include <iostream>
#include <vector>

using namespace std;

int hourglassSum(vector<vector<int>> arr)
{
	int rLength = arr[0].size();
	int cLength = arr.size();

	vector<int> sum = {};

	for (int i = 0; i < arr.size() - 2; i++)
	{
		vector<int> currentRow = arr[i];
		vector<int> nextToNextRow = arr[i + 2];

		for (int j = 0; j < cLength - 2; j++)
		{
			sum.push_back(
				currentRow[j] + currentRow[j + 1] + currentRow[j + 2]
				+ arr[i + 1][j + 1] +
				nextToNextRow[j] + nextToNextRow[j + 1] + nextToNextRow[j + 2]
			);
		}
	}

	int max = -278998;

	for (int i = 0; i < sum.size(); i++)
	{
		if (max < sum[i]) max = sum[i];
	}

	cout << max << endl;

	return max;
}


int main()
{
	hourglassSum({
		{ 1, 1, 1, 0, 0, 0 },
		{ 0, 1, 0, 0, 0, 0 },
		{ 1, 1, 1, 0, 0, 0 },
		{ 0, 0, 2, 4, 4, 0 },
		{ 0, 0, 0, 2, 0, 0 },
		{ 0, 0, 1, 2, 4, 0 },
	});
}

#include <iostream>
#include <vector>

int hourglassSum(std::vector<std::vector<int>> arr)
{

	std::vector<int> newArr;
	int size = arr.size();
	std::vector<long int> sums;

	for (long int i = 0; i < size; i++)
	{
		newArr.reserve(newArr.size() + distance(arr[i].begin(), arr[i].end()));
		newArr.insert(newArr.end(), arr[i].begin(), arr[i].end());
	}

	for (int i = 0; i < size; i++)
	{
		if (i + 2 % size == 0)
			continue;

		if (i + 14 <= size * size)
			break;

		long int sum = newArr[i] + newArr[i + 1] + newArr[i + 2] + newArr[i + 7] + newArr[i + 12] + newArr[i + 13] + newArr[i + 14];
		sums.push_back(sum);
	}

	for (long unsigned int i = 0; i < sums.size(); i++)
	{
		std::cout << sums[i] << std::endl;
	}

	return 0;
}

/*
int main()
{
	hourglassSum([
		[ 1, 1, 1, 0, 0, 0 ],
		[ 0, 1, 0, 0, 0, 0 ],
		[ 1, 1, 1, 0, 0, 0 ],
		[ 0, 0, 2, 4, 4, 0 ],
		[ 0, 0, 0, 2, 0, 0 ],
		[ 0, 0, 1, 2, 4, 0 ],
	]);
}
*/

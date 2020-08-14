// Problem: https://www.hackerrank.com/challenges/crush/problem

#include <iostream>
#include <vector>

using namespace std;

long getMax(vector<long>& arr)
{
	long int max = LONG_MIN;
	long sum = 0;

	for (int i = 0; i < arr.size(); i++)
	{
		sum += arr[i];
		if (max < sum) max = sum;
	}

	return max;
}

long arrayManipulation(int n, vector<vector<int>> queries)
{
	std::vector<long> arr(n + 2, 0);

	for (long int i = 0; i < queries.size(); i++)
	{
		vector<int> query = queries[i];
		arr[query[0]] += query[2];
		arr[query[1] + 1] -= query[2];
	}

	return getMax(arr);
}

/*
int main()
{
	arrayManipulation(10, {
		{ 1, 5, 3 },
		{ 4, 8, 7 },
		{ 6, 9, 1 }
		});
}
*/

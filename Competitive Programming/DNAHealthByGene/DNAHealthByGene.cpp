/// Problem: https://www.hackerrank.com/challenges/determining-dna-health/problem?isFullScreen=false
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Prints occurrences of txt[] in pat[]
int countFreq(string& pat, string& txt)
{
	int M = pat.length();
	int N = txt.length();
	int res = 0;

	for (int i = 0; i <= N - M; i++)
	{
		int j;
		for (j = 0; j < M; j++)
			if (txt[i + j] != pat[j])
				break;

		if (j == M)
		{
			res++;
			j = 0;
		}
	}
	return res;
}

void calcHealth(vector<string> genes, vector<int> health, int first, int last, string d)
{
	int totalHealth;

	for (int i = first; i < last + 1; i++)
	{
		totalHealth += countFreq(genes[i], d) * health[i];
	}
	
}

/*
// Driver program to test above function
int main()
{
	calcHealth({"a",
				"b",
				"c",
				"aa",
				"d",
				"b"},
			   {1, 2, 3, 4, 5, 6}, 1, 5, "caaab");
	return 0;
}
*/

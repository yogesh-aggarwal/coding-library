/// Problem: https://www.hackerrank.com/challenges/how-many-substrings/problem

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;
/*
 * Complete the countSubstrings function below.


 */
 // vector<int> countSubstrings(string s, vector<vector<int>> queries)
vector<int> countSubstrings(string s, vector<vector<int>> queries)
{
	/*
	 * Write your code here.
	 */

	map<int, set<string>> cases;
	vector<map<string, string>> charIndex;
	int queryCount = 0;

	for (long unsigned int i = 0; i < queries.size(); i++)
	{
		vector<int> query = queries[i];
		string tempS = s.substr(query[0], query[1] - query[0] + 1);

		for (int j = 0; j < tempS.length(); j++)
		{
			map<string, string> newCase;
			newCase.insert(pair<string, string>("index", to_string(j)));
			newCase.insert(pair<string, string>("queryCount", to_string(queryCount)));
			newCase.insert(pair<string, string>("tempS", tempS));

			charIndex.push_back(newCase);
		}
		queryCount++;
	}

	for (long unsigned int i = 0; i < charIndex.size(); i++)
	{
		vector<string> words = { "" };

		map<string, string> newCase = charIndex[i];

		int index = stoi(newCase["index"]);
		int queryCount = stoi(newCase["queryCount"]);
		string tempS = newCase["tempS"];

		for (int j = index; j < tempS.length(); j++)
		{
			string word = words[words.size() - 1] + string(1, tempS[j]);
			words.push_back(word);

			cases[queryCount].insert(word);
		}
	}

	vector<int> results = {};

	for (int i = 0; i < cases.size(); i++)
	{
		results.push_back(cases[i].size());
	}

	return results;
}

/*
int main()
{
	countSubstrings("aabaa", {{1, 1}, {1, 4}, {1, 1}, {1, 4}, {0, 2}});
}
*/

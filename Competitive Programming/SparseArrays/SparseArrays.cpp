// Problem: https://www.hackerrank.com/challenges/sparse-arrays/problem?isFullScreen=true
#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> matchingStrings(vector<string> strings, vector<string> queries)
{
    map<string, int> record;
    int queriesSize = queries.size();

    for (int i = 0; i < queriesSize; i++)
    {
        record[queries[i]] = 0;
    }

    for (int i = 0; i < strings.size(); i++)
    {
        string str = strings[i];
        bool isFound = record.find(str) != record.end();
        if (!isFound)
            continue;

        int newValue = record.find(str)->second + 1;
        cout << newValue << endl;
        record[str] = newValue;
    }

    vector<int> result = {};
    for (int i = 0; i < queries.size(); i++)
    {
        result.push_back(record[queries[i]]);
    }

    return result;
}

int main()
{
    vector<string> strings = {"aba", "baba", "aba", "xzxb"};
    vector<string> queries = {"aba", "xzxb", "ab"};

    matchingStrings(strings, queries);

    return 0;
}

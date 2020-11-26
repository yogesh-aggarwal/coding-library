// Problem: https://www.codechef.com/LRNDSA07/problems/CARR
#include <iostream>
#include <sstream>
#include <cmath>
#include <vector>
#include <string>

int findWays(unsigned long long int N, unsigned long long int M)
{
    unsigned long long int result = pow(M, N);

    if (N >= 3)
    {
        result -= M;
    }

    return result;
}
int main()
{
    std::string input;
    std::getline(std::cin, input, '\n');

    unsigned long long int N;
    unsigned long long int M;

    std::vector<std::string> result;
    std::istringstream iss(input);
    for (std::string s; iss >> s;)
        result.push_back(s);

    unsigned long long int answer = findWays(std::stoi(result[0]), stoi(result[1]));
    std::cout << answer;

    char wait;
    std::cin >> wait;
    return 0;
}

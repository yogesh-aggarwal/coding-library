#include <iostream>
#include <vector>

void removeElement(std::vector<char>& vec, int& index, int& length)
{
	vec[index] = 0;
	vec[length - 1 - index] = 0;
}

bool verifyString(std::string str)
{
	std::vector<char> brackets = {};

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(' ||
			str[i] == ')' ||
			str[i] == '[' ||
			str[i] == ']' ||
			str[i] == '{' ||
			str[i] == '}')
		{
			brackets.push_back(str[i]);
		}
	}

	if (brackets.size() % 2 != 0)
	{
		return false;
	}

	int bracketsLength = brackets.size();

	for (int i = 0; i < brackets.size() / 2 ; i++)
	{
		if (
			(brackets[i] == '(' && brackets[bracketsLength - 1 - i] == ')') ||
			(brackets[i] == '[' && brackets[bracketsLength - 1 - i] == ']') ||
			(brackets[i] == '{' && brackets[bracketsLength - 1 - i] == '}')
			)
		{
			removeElement(brackets, i, bracketsLength);
		}
	}

	for (int i = 0; i < brackets.size(); i++)
	{
		if (brackets[i] != 0) {
			return false;
		}
	}

	return true;
}

/*
int main()
{
	std::cout << verifyString("([{()}])w") << std::endl;
}
*/

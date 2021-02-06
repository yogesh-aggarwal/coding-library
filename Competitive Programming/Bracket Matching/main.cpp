#include <iostream>
#include <vector>

#define MAX_Size 1000

class Stack
{
private:
	unsigned int size;
	char stack[MAX_Size];
	int top = -1;

public:
	Stack(unsigned int size) : size(size) {}

	void push(char value)
	{
		if (top == size)
		{
			std::cout << "Stack Overflow" << std::endl;
			return;
		}

		stack[top + 1] = value;
		top += 1;
	}

	void pop()
	{
		if (isEmpty())
		{
			std::cout << "Stack is Empty";
			return;
		}
		stack[top] = 0;
		top -= 1;
	}

	int peek()
	{
		if (isEmpty())
		{
			std::cout << "Stack is Empty" << std::endl;
			return -1;
		}
		int value = stack[top];
		return value;
	}

	bool isEmpty()
	{
		return top == -1 ? true : false;
	}

	void display()
	{
		int count = 0;
		while (count <= top)
		{
			std::cout << "Index " << count << ": " << stack[top - count] << std::endl;
			count++;
		}
	}
};

namespace BracketMatching
{
	namespace UsingNormalMethod
	{
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

			for (int i = 0; i < brackets.size() / 2; i++)
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
	};

	namespace UsingStacks
	{
		bool verifyString(std::string str)
		{
			std::vector<char> brackets = {};

			for (int i = 0; i < str.length(); i++)
			{
				if (str[i] == '(' || str[i] == ')' || str[i] == '[' || str[i] == ']' || str[i] == '{' || str[i] == '}')
				{
					brackets.push_back(str[i]);
				}
			}

			int size = brackets.size();
			if (size % 2 != 0)
			{
				return false;
			}

			Stack matching(size);
			char bracket;

			for (int i = 0; i < brackets.size(); i++)
			{
				bracket = brackets[i];
				if (bracket == '(' || bracket == '{' || bracket == '[')
				{
					matching.push(bracket);
				}
				else if (bracket == ')')
				{
					if (matching.peek() == '(')
						matching.pop();
					else
					{
						return false;
					}
				}
				else if (bracket == ']')
				{
					if (matching.peek() == '[')
						matching.pop();
					else
					{
						return false;
					}
				}
				else if (bracket == '}')
				{
					if (matching.peek() == '{')
						matching.pop();
					else
					{
						return false;
					}
				}
			}

			return true;
		}
	};
}

int main()
{
	/* Using Normal Method */
	std::cout << BracketMatching::UsingNormalMethod::verifyString("([{()}])w") << std::endl;
	/* Using Stacks */
	std::cout << BracketMatching::UsingStacks::verifyString("([{()}])w") << std::endl;
}

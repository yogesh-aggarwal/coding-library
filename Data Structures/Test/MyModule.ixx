#include <iostream>

export module MyModule;

export namespace MyModuleNamespace
{
	void print()
	{
		std::cout << "Hello From Module!" << std::endl;
	}
}

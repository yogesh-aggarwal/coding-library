#include <iostream>

int main()
{
    int a = 0;
    std::cout << "Hello World" << std::endl;

    a = 2;

    int *b = &a;
    b = new int(3);

    return 0;
}

#include <iostream>

#define MAX_Size 1000

class Stack
{
private:
    unsigned int size;
    int stack[MAX_Size];
    int top = -1;

public:
    Stack(unsigned int size) : size(size) {}

    void push(unsigned int value)
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
        std::cout << value << std::endl;
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

int main()
{
    Stack *stack = new Stack(3);
    stack->push(1);
    stack->peek();
    // stack->display();

    stack->pop();

    stack->push(2);
    stack->push(3);
    stack->display();
    return 0;
}

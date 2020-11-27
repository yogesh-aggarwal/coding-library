#include <iostream>

class Node
{
public:
    int value;
    Node *next;

    Node(int value) : value(value) {}
};

class Stack
{
private:
    int size;
    int count;
    Node *top = nullptr;
    Node *bottom = nullptr;

public:
    Stack(int size) : size(size) {}

    void push(int value)
    {
        if (size == count)
        {
            std::cout << "Stack Overflow" << std::endl;
            return;
        }
        Node *node = new Node(value);
        node->next = top;
        top = node;

        if (bottom == nullptr)
        {
            bottom = top;
        }
    }

    void pop()
    {
        if (isEmpty())
        {
            std::cout << "Stack is Empty" << std::endl;
            return;
        }
        top = top->next;
        if (top == nullptr || top->next == nullptr)
        {
            bottom = top;
        }
    }

    int peek()
    {
        if (isEmpty())
        {
            std::cout << "Stack is Empty" << std::endl;
            return -1;
        }
        std::cout << top->value << std::endl;
        return top->value;
    }

    bool isEmpty()
    {
        return top == nullptr ? true : false;
    }

    void display()
    {
        if (isEmpty())
        {
            std::cout << "Stack is Empty" << std::endl;
            return;
        }

        int count = 0;
        Node *currentNode = top;

        while (count < size - 1)
        {
            std::cout << "Index " << count << ": " << currentNode->value << std::endl;
            currentNode = currentNode->next;
            count++;
        }
    }
};

int main()
{
    Stack *stack = new Stack(3);
    stack->push(1);
    stack->peek();
    stack->display();

    stack->pop();

    stack->push(2);
    stack->push(3);
    stack->display();

    return 0;
}

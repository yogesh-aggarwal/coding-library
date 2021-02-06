#include <iostream>
#include <vector>

struct Node
{
    Node* prev;
    Node* next;
    int data;

    Node(int data, Node* prev, Node* next)
        : data(data), prev(prev), next(next) {};
};

struct DoublyLinkedList
{
private:
    int length = 0;

public:
    Node* head = nullptr;
    Node* tail = nullptr;

    void add(int item)
    {
        if (head == nullptr)
        {
            head = new Node(item, nullptr, nullptr);
        }
        else if (tail == nullptr)
        {
            tail = new Node(item, head, nullptr);
            head->next = tail;
        }
        else
        {
            Node* newNode = new Node(item, tail, nullptr);
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }

    void rotate(int byElem)
    {
        int count = 1;
        Node* tempNode = head;
        Node* tempHead = head;

        while (count < length)
        {
            if (count == byElem)
            {
                head = tempNode->next; // New Head
                head->prev = nullptr;

                tempNode->next = nullptr; // New Tail
                tempHead->prev = tail;
                tail->next = tempHead;

                std::cout << head->data << " " << tempNode->data << " " << tail->data << std::endl;
                break;
            }

            tempNode = tempNode->next;
            count++;
        }
    }

    /*void reverse() {
        Node* prevNode = nullptr;
        Node* nextNode = head;

        Node* currentNode = head;

        int count = 0;

        while (count < length) {
            Node* nextNextNode = currentNode->next;

            nextNode->next = currentNode->prev;
            nextNode->prev = nextNextNode;

            if (currentNode->next == nullptr) {
                head = currentNode;
                break;
            }

            currentNode = currentNode->next;

            count++;
        }

        std::cout << nextNode->data << std::endl;
    }*/
};

void generateDoublyLinkedListFromMatrix()
{
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };
}

int main()
{
    DoublyLinkedList list;

    list.add(10);
    list.add(20);
    list.add(30);
    list.add(40);
    list.add(50);

    //list.reverse();

    return 0;
}

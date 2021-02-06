#include <iostream>
#include <vector>

struct Node
{
	int data;
	Node* next;

	Node(int data)
		: data(data), next(nullptr) {};

	Node(int data, Node& next)
		: data(data), next(&next) {};

	void setNext(Node* nextNode)
	{
		next = nextNode;
	}
};

struct SinglyLinkedList
{
private:
	bool isCircular;
	int length = 0;

public:
	Node* head = nullptr;
	Node* tail = nullptr;

	SinglyLinkedList(bool isCircular = false)
		: isCircular(isCircular)
	{
	}

	void add(int item)
	{
		Node* node = new Node(item);

		if (head == nullptr)
		{
			head = node;
		}
		else if (tail == nullptr)
		{
			if (isCircular)
				node->setNext(head);
			tail = node;
			head->setNext(tail);
		}
		else
		{
			tail->setNext(node);
			tail = node;
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
				head = tempNode->next;
				tempNode->setNext(nullptr);
				tail->setNext(tempHead);
				break;
			}

			tempNode = tempNode->next;
			count++;
		}
	}

	void reverse()
	{
		Node* prevNode = nullptr;
		Node* nextNode = head;
		Node* nextNextNode = nullptr;
		int count = 0;

		while (count < length)
		{
			nextNextNode = nextNode->next;
			nextNode->setNext(prevNode);
			prevNode = nextNode;
			nextNode = nextNextNode;

			count++;
		}

		head = tail;
	}
};

int main()
{
	SinglyLinkedList list;

	list.add(10);
	list.add(20);
	list.add(30);
	list.add(40);
	list.add(50);

	list.reverse();

	std::cout << list.head->next->next->data << std::endl;
}

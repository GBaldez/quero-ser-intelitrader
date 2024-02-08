#include <iostream>
using namespace std;

class Book
{
  public:
	double value;
	int quantity;

	void setValue(double v)
	{
		value = v;
	}
	void setQuantity(int q)
	{
		quantity = q;
	}

	Book(double v, int q)
	{
		value = v;
		quantity = q;
	}

	friend std::ostream &operator<<(std::ostream &os, const Book &data)
	{
		os << data.value << ",";
		os << data.quantity;
		return os;
	}
};

class Node
{
  public:
	int position;
	Book data;
	Node *next;

	Node(const Book &properties, int p) : data(properties), next(nullptr)
	{
		position = p;
	}
};

void printList(Node *n)
{
	while (n != nullptr)
	{
		cout << n->position << "," << n->data << endl;
		n = n->next;
	}
}

void insertAtHead(Node **head, int position, Book newBook)
{
	Node *newNode = new Node(newBook, position);
	newNode->position = 1;
	newNode->data = newBook;
	newNode->next = *head;
	*head = newNode;
}

void insertAt(Node **head, int position, Book newBook)
{
	Node *newNode = new Node(newBook, position);
	newNode->data = newBook;

	Node *last = *head;
	Node *previous;

	while (last->next != nullptr && last->position < position)
	{
		previous = last;
		last = last->next;
	}
	if (last->position == position)
	{
		newNode->position = last->position;
		newNode->next = last->next;
		previous->next = newNode;
	}
	else
	{
		newNode->position = last->position + 1;
		newNode->next = last->next;
		last->next = newNode;
	}
}

Node *search(Node *head, int position)
{
	Node *temp = head;
	while (temp != nullptr)
	{
		if (temp->position == position)
		{
			return temp;
		}
		temp = temp->next;
	}
	return nullptr;
}

void deleteNode(Node *&head, Node *previous, Node *toRemove)
{
	if (toRemove == head)
	{
		head = toRemove->next;
		delete toRemove;
	}
	else if (toRemove)
	{
		previous->next = toRemove->next;
		delete toRemove;
	}
	Node *temp = head;
	int newPos = 1;
	while (temp != nullptr)
	{
		temp->position = newPos;
		temp = temp->next;
		newPos++;
	}
}

int main(int argc, char *argv[])
{
	Node *head = nullptr;
	Node *temp = nullptr;

	int notifications = 0;

	cout << "Insert the input ";
	cin >> notifications;

	while (notifications > 0)
	{
		int position;
		int action;
		double value;
		int quantity;

		cin >> position;
		cin.ignore(1, ',');
		cin >> action;
		cin.ignore(1, ',');
		cin >> value;
		cin.ignore(1, ',');
		cin >> quantity;

		switch (action)
		{
		case 0:
			if (head == nullptr || position == 1)
			{
				Book newBook(value, quantity);
				insertAtHead(&head, position, newBook);
			}
			else
			{
				Book newBook(value, quantity);
				insertAt(&head, position, newBook);
			}
			break;
		case 1:

			temp = search(head, position);

			if (!temp)
			{
				cout << "Don't have any element in this position!" << endl;
			}
			else
			{
				if (value > 0)
				{
					temp->data.setValue(value);
				}

				if (quantity > 0)
				{
					temp->data.setQuantity(quantity);
				}
			}
			break;
		case 2:
			if (head)
			{
				temp = search(head, position);
				Node *previous = search(head, position - 1);

				deleteNode(head, previous, temp);
			}
			break;
		}

		notifications--;
	}

	printList(head);
}

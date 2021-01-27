/*
Circular Linked Lists is a Linked List where all nodes are connected to form a circle. 
There is no NULL at the end. A circular list can be a SLL or DLL

Advantages of Circular Linked List:
- Any node can be a starting point (We can traverse the list starting from any point)
- Useful for implementation of queue. No need to maintain two pointers for head and tail.
- Circular lists are useful in applications to repeatedly go around the list
- Used for advanced data structures like Fibonacci Heap
*/

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#define LINE cout << string(60, '-') << endl;

class Node
{
	public:
	int data;
	Node *next;
};

void printList(Node *first)
{
	Node *temp = first;
	
	LINE;
	cout << "LIST: ";
	if (first != NULL)
	{
		do 
		{
			int x = first->data;
			cout << x << (first->next==temp ? "" : ", ");
			first = first->next; 
		}
		while(first != temp);
	}
	cout << endl;
	LINE;
}

/*
Why have we taken a pointer that points to the last node instead of the first node?

FOr insertion of a node in the beginning we need traverse the whole list. Also, for insertion at the end, the whole list has to be traversed.
If instead of start pointer we take a pointer to the last node then in both the cases there won't be any need to traverse the whole list. 
So insertion in the beginning or at the end takes constant time irrespective of the length of the list.
*/

void addToEmpty(Node **last, int new_data)
{
	if (*last != NULL)
		return;
	
	*last = (Node *) malloc(sizeof(Node));
	
	(*last)->data = new_data;
	(*last)->next = *last;
}

void addBegin(Node **last, int new_data)
{
	if (*last == NULL)
		addToEmpty(last, new_data);
	
	Node *temp = (Node *) malloc(sizeof(Node));
	
	temp->data = new_data;
	temp->next = (*last)->next;
	
	(*last)->next = temp;
}

void addEnd(Node **last, int new_data)
{
	if (*last == NULL)
		addToEmpty(last, new_data);
	
	Node *temp = (Node *) malloc(sizeof(Node));
	
	temp->data = new_data;
	temp->next = (*last)->next;
	
	(*last)->next = temp;
	*last = temp;
}

void addAfter(Node **last, int new_data, int item)
{
	if (*last == NULL)
		addToEmpty(last, new_data);
	
	Node *temp = *last, *p = (Node *) malloc(sizeof(Node));
	
	do
	{
		if (temp->data == item)
		{
			p->data = new_data;
			p->next = temp->next;
			
			temp->next = p;
			
			if ((*last)->data == item)
				(*last) = (*last)->next;
			return;
		}
		temp = temp->next;
	}
	while(temp !=  *last);
	
	LINE;
	cout << "ERROR: " << item << " is not in LIST." << endl;
	LINE;
}

void deleteNode(Node **tail, int key)
{
	if ((*tail) == NULL)
		return;
	
	Node *curr = *tail, *prev;
	
	while (curr->data != key)
	{
		if (curr->next == *tail)
		{
			LINE;
			cout << "ERROR: " << key << " is not in LIST." << endl;
			LINE;
			return;
		}
		prev = curr;
		curr = curr->next;
	}
	
	//If there is only one node
	if ((*tail)->next == *tail)
	{
		*tail = NULL;
		free(curr);
		return;
	}
	
	//If Tail is to be deleted
	if ((*tail)->data == key)
	{
		prev->next = curr->next;
		*tail = prev;
		free(curr);
		return;
	}

	prev->next = curr->next;
	free(curr);
}

Node* listElement(Node *tail, int key)
{
	if (tail == NULL)
	{
		LINE;
		cout << "ERROR: " << key << " is not in LIST." << endl;
		LINE;
		return NULL;
	}
	
	Node *curr = tail;
	
	while (curr->data != key)
	{
		if (curr->next == tail)
		{
			LINE;
			cout << "ERROR: " << key << " is not in LIST." << endl;
			LINE;
			return NULL;
		}
		curr = curr->next;
	}
	
	return curr;
}

int main()
{
	Node *tail = NULL;
	
	printList(tail);
	
	addToEmpty(&tail, 5);
	printList(tail);
	
	
	addBegin(&tail, 3);
	printList(tail);
	
	addEnd(&tail, 6);
	printList(tail);
	
	addAfter(&tail, 89, 6);
	printList(tail);
	
	deleteNode(&tail, 5);
	printList(tail);
	
	printList(listElement(tail, 3));
	
	return 0;
}
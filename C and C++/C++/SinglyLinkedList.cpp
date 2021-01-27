/*
Singly Linked Lists:
Like arrays, Linked List is a linear data structure. Unlike arrays, linked list elements are not stored at 
contiguous location; the elements are linked using pointers

Advantages of Linked List vs Array:
- Array Size is constant while linked list isn't. This means that sometimes there isn't enough memory and sometimes there is a surplus in arrays
- Inserting and deleting elements in arrays is tedious and inefficient

Disadvantages:
- Random access is not allowed (have to access sequentially) --> cannot perform binary search
- Extra memory space required for pointer in each element
- Not cache friendly. Since array elements are contiguous locations, there is locality of reference which is not there in linked list
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

void printList(Node *head)
{
	Node *headcp = head;
	
	LINE;
	cout << "LIST: ";
	while(head->next != NULL)
	{
		cout << head->data << (head->next==NULL ? "" : ", ");
		head = head->next;
	}
	//print the tail:
	cout << head->data << (head->next==NULL ? "" : ", ") << endl;
	
	cout << "Head: " << headcp->data << endl << "Tail: " << head->data;
	cout << endl;
	LINE;
}

void push(Node **head, int new_data)
{
	Node *new_node = (Node *) malloc(sizeof(Node));
	
	new_node->data = new_data;
	new_node->next = *head;
	
	*head = new_node;
}

void insertAfter(Node *prev, int new_data)
{
	if (prev == NULL)
	{
		cout << "The previous node cannot be NULL";
		return;
	}
	
	Node *new_node = (Node *) malloc(sizeof(Node));
	
	new_node->data = new_data;
	new_node->next = prev->next;
	
	prev->next = new_node;
}

void append(Node **head, Node **tail, int new_data)
{
	Node *new_node = (Node *) malloc(sizeof(Node));
	
	new_node->data = new_data;
	new_node->next = NULL;
	
	if (*head == NULL)
	{
		*head = new_node;
		return;
	}
	
	(*tail)->next = new_node;
	*tail = new_node;
}

void deleteNode(Node **head, int key)
{
	Node *temp = *head, *prev;
	
	if(temp != NULL && temp->data==key)
	{
		*head = temp->next;
		free(temp);
		return;
	}
	
	while(temp != NULL && temp->data != key)
	{
		prev = temp;
		temp = temp->next;
	}
	
	if (temp == NULL)
		return;
	
	prev->next = temp->next;
	free(temp);
	
}

int main()
{
	Node *head, *second , *tail;
	
	head = new Node();
	second = new Node();
	tail = new Node();
	
	head->data = 1;
	head->next = second;
	
	second->data = 2;
	second->next = tail;
	
	tail->data = 3;
	tail->next = NULL;
	
	printList(head);
	
	push(&head, 0);
	printList(head);
	
	insertAfter(second, 45);
	printList(head);
	
	append(&head, &tail, 67);
	printList(head);
	
	deleteNode(&head, 2);
	printList(head);
	
	return 0;
}
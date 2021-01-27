/*
A Doubly Linked List (DLL) contains an extra pointer, typically called previous pointer, 
together with the next pointer and data which are there in singly linked list.

Advantages of DLL over SLL:
- Can be traversed in both forward and backward direction
- The delete operation in DLL is more efficient if pointer to the node to be deleted is given
- We can quickly insert a new node before a given node

In SLL, to delete a node, pointer to the previous node is needed. To get this previous node, 
sometimes the list is traversed. In DLL, we can get the previous node using previous pointer

disadvantages of DLL over SLL:
- Every node of DLL requires extra space for an previous pointer. It is possible to implement DLL with SLL
- All operations require an extra pointer previous to be maintained
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
		Node *next, *prev;
};

void push(Node **head, int new_data)
{
	Node *new_node = (Node *) malloc(sizeof(Node));
	
	new_node->data = new_data;
	
	new_node->next = *head;
	new_node->prev = NULL;
	
	if (*head != NULL)
		(*head)->prev = new_node;
	
	*head = new_node;
}

void insertAfter(Node *prev_node, int new_data)
{
	if (prev_node == NULL)
	{
		cout << "The previous node cannot be NULL";
		return;
	}
	Node *new_node = (Node *) malloc(sizeof(Node));
	
	new_node->data = new_data;
	new_node->next = prev_node->next;
	new_node->prev = prev_node;
	
	prev_node->next = new_node;
	
	if (new_node->next != NULL)
		new_node->next->prev = new_node;
}

void insertBefore(Node **head, Node *next_node, int new_data)
{
	if (next_node == NULL)
	{
		cout << "The next node cannot be NULL";
		return;
	}
	Node *new_node = (Node *) malloc(sizeof(Node));
	
	new_node->data = new_data;
	new_node->next = next_node;
	new_node->prev = next_node->prev;
	
	next_node->prev = new_node;
	
	if (new_node->prev != NULL)
		new_node->prev->next = new_node;
	else
		*head = new_node;
}

void append(Node **head, Node**tail, int new_data)
{
	Node *new_node = (Node *) malloc(sizeof(Node));
	
	new_node->data = new_data;
	new_node->next = NULL;
	
	if (*head == NULL)
	{
		new_node->prev = NULL;
		*head = new_node;
		return;
	}
	
	(*tail)->next = new_node;
	new_node->prev = *tail;
	*tail = new_node;
}

void deleteNode(Node **head, Node *del)
{
	if (*head == NULL || del == NULL)
		return;
	
	if (*head == del)
		*head = del->next;
	
	if (del->next != NULL)
		del->next->prev = del->prev;
	
	if (del->prev != NULL)
		del->prev->next = del->next;
	
	free(del);
}

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

int main()
{
	Node *head, *second , *tail;
	
	/*
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);
	printList(head);
	
	//OR
	
	head = new Node();
	push(&head, 1);
	printList(head);
	*/
	
	head = new Node();
	second = new Node();
	tail = new Node();
	
	head->data = 1;
	head->next = second;
	head->prev = NULL;
	
	second->data = 2;
	second->next = tail;
	second->prev = head;
	
	tail->data = 3;
	tail->next = NULL;
	tail->prev = second;
	
	printList(head);
	
	push(&head, 0);
	printList(head);
	
	insertAfter(second, 45);
	printList(head);
	
	append(&head, &tail, 67);
	printList(head);
	
	insertBefore(&head, head, -4);
	printList(head);
	
	deleteNode(&head, second);
	printList(head);
	return 0;
}
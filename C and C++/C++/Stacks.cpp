/*
A Stack is an abstract data structure that contains a collection of elements. Queue implements the
LIFO (Last In First Out) mechanism i.e. the element that is pushed at the end is popped out first.

Some principle operations in stack are:
- PUSH: This adds a data value to the top of the stack
- PEEK: This returns the data value on top of the stack
- POP: This removes the data value on top of the stack
*/


#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

struct Node
{
	int data;
	struct Node *next;
};

struct Node *top = NULL;

void push(int val)
{
	struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
	
	new_node->data = val;
	new_node->next = top;
	
	top = new_node;
}

void pop()
{
	if (top == NULL)
		cout << "Stack Underflow" << endl;
	else
	{
		cout << "The popped element is " << top->data << endl;
		top = top->next;
	}
}

void display()
{
	struct Node *ptr;
	if (top == NULL)
		cout << "Stack is Empty" << endl;
	else
	{
		ptr = top;
		cout << "----STACK----" << endl;
		while (ptr != NULL)
		{
			int x = ptr->data;
			cout << setw(10) << x << endl;
			ptr = ptr->next;
		}
		cout << "----------------" << endl;
	}
}

int main()
{
	int ch, val;
	cout << "Press:" << endl;
	cout << "1 - Push in stack" << endl;
	cout << "2 - Pop from stack" << endl;
	cout << "3 - Display stack" << endl;
	cout << "4 - Exit" << endl;
	
	do 
	{
		cout << "Enter choice: ";
		cin >> ch;
		cout << endl;
		
		switch(ch)
		{
			case 1:
				cout << "Enter value to push: ";
				cin >> val;
				cout << endl;
				push(val);
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				cout << "Exit.";
				break;
			default:
				cout << "Invalid Input. ";
		}
	}
	while(ch != 4);
	
	return 0;
}
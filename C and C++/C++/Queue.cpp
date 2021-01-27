/*
A Queue is an abstract data structure that contains a collection of elements. Queue implements the
FIFO (First In First Out) mechanism i.e. the element that is inserted first is also deleted first. In other
words, the least recently added element is removed first in a queue.

Front -> 2nd -> 3rd -> ... -> back -> NULL

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

struct Node *front = NULL, *back = NULL, *temp;

void Insert()
{
	int val;
	
	cout << "Enter the value: ";
	cin >> val;
	
	if (back == NULL)
	{
		back = (struct Node *) malloc((sizeof(struct Node)));
		back->next = NULL;
		back->data = val;
		front = back;
	}
	else
	{
		temp = (struct Node *) malloc((sizeof(struct Node)));
		
		back->next = temp;
		temp->data = val;
		temp->next = NULL;
		back = temp;
	}
}

//Deletes element in front of the queue
void Delete()
{
	temp = front;
	if (front == NULL)
	{
		cout << "Under Flow" << endl;
		return;
	}
	else if (temp->next != NULL)
	{
		temp = temp->next;
		cout << "Element deleted from queue is: " << front->data << endl;
		free(front);
		front = temp;
	}
	else 
	{
		cout << "Element deleted from queue is: " << front->data << endl;
		free(front);
		front = NULL;
		back = NULL;
	}
}

void Display()
{
	temp = front;
	if ((front == NULL) && (back == NULL))
	{
		cout << "Queue is empty" << endl;
		return;
	}
	cout << "QUEUE:\nFront -----> Back:" << endl;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	int ch;
	cout << "Press:" << endl;
	cout << "1 - Insert element in Queue" << endl;
	cout << "2 - Delete element from queue" << endl;
	cout << "3 - Display queue" << endl;
	cout << "4 - Exit" << endl;
	
	do 
	{
		cout << "Enter choice: ";
		cin >> ch;
		cout << endl;
		
		switch(ch)
		{
			case 1:
				Insert();
				break;
			case 2:
				Delete();
				break;
			case 3:
				Display();
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
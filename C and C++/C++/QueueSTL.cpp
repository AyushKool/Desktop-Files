/*
Queues are a type of container adaptors with FIFO(First In First Out) type of arrangement, where elements are inserted
at the back(end) and are deleted from the front. 

empty() - Returns whether the queue is empty 
size() - Returns the size of the queue 
push(g) - Adds the element 'g' at the end of the queue 
pop() - Deletes the first most element of the queue 
swap() - swaps the contents of one queue with another queue of same type (size may differ)
emplace() - This function is used to inset a new element into the queue container, the new element
			is added to the end of the queue
front() - Returns a reference to the first element of the queue
back() - Returns a reference to the last element of the queue
*/

#include <queue>
#include <iostream>
using namespace std;

void showq(queue<int> q)
{
	queue <int> t = q;
	while(!q.empty())
	{
		cout << '\t' << q.front();
		q.pop();
	}
	cout << '\n';
}

int main()
{
	queue <int> q;
	q.push(10);
	q.push(20);
	q.push(30);
	
	cout << "QUEUE: ";
	showq(q);
	
	cout << "\nSize: " << q.size();
	cout << "\nFront: " << q.front();
	cout << "\nBack: " << q.back();
	
	cout << "\nPop: ";
	q.pop();
	showq(q);
}
/*
The list is another container that is popularly used. It supports a bidirectional, linear list and provides an 
efficient implementation for deletion and insertion operation. Unlike a vector, which supports random access, a
list can be accessed sequentially only.

Bidirectional iterators are used for accessing list elements. Any algorithm that requires input, output, forward, 
or bidirectional iterators can operate on a list. Class list provides many member functions for manipulating the 
elements of a list. Header file <list> mush be included to use the container class list
*/

#include <iostream>
#include <list>
#include <cstdlib> // For using rand() function
using namespace std;

void display(list<int> &l)
{
	list<int> :: iterator p;
	for (p=l.begin(); p!=l.end(); p++)
		cout << *p << ", ";
	cout << endl;
}

int main()
{
	list<int> l1; //Empty list of zero length
	list<int> l2(5); //Empty list of size 5
	
	for (int i=0; i<3; i++)
		l1.push_back(rand()/100);
	
	list<int> :: iterator p;
	for(p=l2.begin(); p!=l2.end(); ++p)
		*p = rand()/100;
	
	cout << "List1 \n";
	display(l1);
	
	cout << "List2 \n";
	display(l2);
	
	//Add two elements at the ends of List1
	l1.push_front(100);//add in front of list
	l1.push_back(200);//adds at the end
	
	//Remove an element at the front of List 2
	l2.pop_front();
	
	cout << "Now List1\n";
	display(l1);
	
	cout << "Now List2\n";
	display(l2);
	
	
	list<int> listA, listB;
	listA = l1;
	listB = l2;
	
	//Merging two lists(unsorted)
	listA.merge(listB);
	display(listA);
	
	//Merged two lists(sorted)
	listA.sort();
	display(listA);
	
}
/*
Stacks are a type of container adaptors with LIFO type of working, where a new element is added at one 
end (top) and an element is removed form that end only.

empty() - Returns whether the stack is empty [Time Complexity: O(1)]
size() - Returns the size of the stack [Time Complexity: O(1)]
top() - Returns a reference to the top most element of the stack [Time Complexity: O(1)]
push(g) - Adds the element 'g' at the top of the stack [Time Complexity: O(1)]
pop() - Deletes the top most element of the stack [Time Complexity: O(1)]
swap() - swaps the contents of one stack with another stack of same size and type
emplace() - This function is used to inset a new element into the stack container, the new element
			is added on top of the stack
*/


#include <stack>
#include <iostream>
using namespace std;

void display(stack<int> s)
{
	while(!s.empty())
	{
		cout << '\t' << s.top();
		s.pop();
	}
	cout << endl;
}

int main()
{
	stack<int> s;
	s.push(10);
	s.push(2);
	s.push(56);
	s.push(3);
	s.push(1);
	
	cout << "stack : " << endl;
	display(s);
	
	cout << "Size: " << s.size() << endl;
	cout << "Top: " << s.top() << endl << endl;
	
	s.pop();
	cout << "stack after pop(): " << endl;
	display(s);
	
	return 0;
}
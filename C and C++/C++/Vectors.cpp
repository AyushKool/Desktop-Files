/* 
Vectors are same as dynamic arrays with the ability to resize itself automatically 
when an element is inserted or deleted, with their storage being handled automatically 
by the container.
*/

#include <iostream>
#include <vector>

using namespace std; 

void display(const vector<int> &v)
{
	for (int i=0; i<v.size(); i++)
		cout << v[i] << "  ";
	cout << "\n";
}

void input(vector<int> &v)
{
	int n = v.size(), x;
	cout << "Enter values: ";
	for (int i=0; i<n; i++)
	{
		cin >> x;
		v[i] = x;//push_back adds value to back so don't use here
	}
}

int main()
{
	vector<int> v1;//zero length int vector
	vector<int> v2(5);//5-element int vector
	vector<int> v3(v1); //Copies v1 to v3
	vector<int> v(5,2);//5-element vector of 2s
	
	
	for (int i=1; i<=5; i++)
		v1.push_back(i);//pushes an element into the vector from the back
	
	input(v2);
	display(v2);
	
	/*
	cout << "Output of begin and end: ";
	
	for (auto i=v1.begin(); i!=v1.end(); i++)
		cout << *i << " ";
	
	cout << endl << "Output of cbegin and cend: ";
	
	for (auto i=v1.cbegin(); i!=v1.cend(); i++)
		cout << *i << " ";
	
	cout << endl << "Output of rbegin and rend: ";
	
	for (auto i=v1.rbegin(); i!=v1.rend(); i++)
		cout << *i << " ";
	
	cout << endl << "Output of crbegin and crend: ";
	
	for (auto i=v1.crbegin(); i!=v1.crend(); i++)
		cout << *i << " ";
	
	return 0;
	*/
}

/*
begin() - Returns an iterator pointing to the first element in the vector
end() - Returns an iterator pointing to the theoretical element that follows the last element in the vector
rbegin() - Returns a reverse iterator pointing to the last element in the vector(reverse beginning). It moves from last to first element
rend() - Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector(considered as reverse end)
cbegin() - Returns a constant iterator pointing to the first element in the vector
cend()- Returns a constant iterator pointing to the theoretical element that follows the last element in the vector
crbegin() - returns a constant reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element
crend() - Returns a constant reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)
at() - Gives a reference to an element
back() - Gives a reference to the last element
clear() - Deletes all elements from the vector

size() - Returns the number of elements in the vector
max_Size() - Returns the maximum number of elements that the vector can hold
capacity() - Returns the size of the storage space currently allocated to the vector expressed as umber of elements
resize() - Resizes the container so that is contains 'g' elements
empty() - Returns whether the container is empty
shrink_to_fit() - Reduces the capacity of the container to fit its size and destroys all elements beyond the capacity
reserve() - Requests that the vector capacity be at least enough to contain n elements
*/
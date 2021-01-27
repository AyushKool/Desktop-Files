/*
The Pair container is a simple container defined in <utility> header consisting of two data elements or objects

The First element is referenced as 'first' and the second element as 'second' and the order is fixed (first, second)

Pair is used to combine together two values which may e different in type. Pair provides a way to store two heterogeneous objects as a single unit

Pair can be assigned, copied and compared. The array of objects allocated in a map or hash_ map are of type 'pair' by default in which all the 'first'
elements are unique keys associated with their 'second' value objects.

To access the elements, we use variable name followed by dot operator followed by the keyword first or second
*/

#include <iostream>
#include <utility>

using namespace std;

int main()
{
	/*
	Note if the pair's value is not initialized, it is assigned a default value:
		int: 0
		double: 0
		char: NULL
		string: NULL
	*/	
	
	//Different ways to declare and initialize a Pair:
	
	pair<int, int> p1;
	pair<string,int> p2("Ayush Koul", 18);
	pair<int, int> p3 = make_pair(3, 2);
	
	p1.first = 100;
	p1.second = 'G';
	
	cout << p1.first << "\t";
	cout << p1.second << endl;
	
	cout << p2.first << "\t";
	cout << p2.second << endl;
	
	cout << p3.first << "\t";
	cout << p3.second << endl;
	
	/*
	When we use relational operators to compare two pairs, it only compares the first elements of the pair
	both data members of the Pairs must be of same type for comparison
	*/
	
	cout << ((p1 > p3) ? "P1 is greater" : "P2 is greater") << endl;//Why doesn't it work if one is double?
	
	/*
	swap: This function swaps the contents of one pair with the contents of another pair object. The pairs must be of same type
	
	Syntax:
	pair1.swap(pair2);
	
	It swaps pair1.first with pair2.first and pair1.second with pair2.second
	*/
	
	//Is their a better way to do this?
	p1 = pair<int, int>(3,4);
	p3.first = 3;
	p3.second = 4;
	
	p1.swap(p3);
	
	cout << p1.first << "\t";
	cout << p1.second << endl;
	
	cout << p3.first << "\t";
	cout << p3.second << endl;
	
	return 0;
}
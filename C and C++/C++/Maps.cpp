/*Maps are associative containers that store elements in a mapped fashion. Each element has a key value and a mapped
value. No two mapped values can have same key values.


A Map is a sequence of (key, value) pairs where a single value is associated with each  unique key. Retrieval of values
is based on the key and is very fast. We should specify the key to obtain the associated value:

									(key 1)  ---->  |Value 1|
									(key 2)  ---->  |Value 2|
											   .
											   .
											   .
									(key N)  ---->  |Value N|
									
A Map is commonly called an associative array. The key is specified using the subscript operator []:
	phone["John"] = 1111;
This creates an entry for "John" and associates (i.e. assigns) the value 1111 to it. phone is a map object

To change the value:
phone["John"] = 9999;
This changes the value 1111 to 9999. We can also insert and delete pairs anywhere in the map using insert() and erase()

*/

#include <iostream>
#include <iterator>
#include <map>
#include <string>

using namespace std;
typedef map<string, int> phoneMap;

int main()
{
	string name;
	int number;
	phoneMap phone;
	cout << "Enter three sets of name and number\n";

	for (int i = 0; i < 3; i++)
	{
		cin >> name;		  //get key
		cin >> number;		  //get value
		phone[name] = number; //put them in map
	}

	phone["Jacob"] = 4444;						   //Insert Jacob
	phone.insert(pair<string, int>("Bose", 5555)); //Insert Bose

	int n = phone.size();
	cout << "\nSize of map: " << n << "\n\n";
	cout << "List of telephone numbers\n";
	phoneMap::iterator p; //scope-Resolution operator
	for (p = phone.begin(); p != phone.end(); p++)
		cout << (*p).first << "\t" << (*p).second << endl;

	cout << endl
		 << "Enter Name: ";
	cin >> name;
	number = phone[name]; //Find numbercout << "Number: " << number;
}

/*
begin() - Returns an iterator to the first element in the map
end() - Returns an iterator to the theoretical element tat follows last element in the map
size() - Returns the number of elements in the map
max_size() - Returns the maximum number of elements that the map can hold
empty() - Returns whether the map is empty
pair insert(keyvalue, mapvalue) - Adds a new element to the map
erase(iterator position) - Removes the element at the position pointed by the iterator
erase (cont g) - Removes the key value 'g' from the map
clear() - Removes all the elements from the map

insert() - Insert elements with a particular key in the map container
*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a("Hello"), b(50, '*');
	cout << a << endl
		 << b;

	/*
	string t;
	cout << "Enter a string: ";
	cin >> t;
	*/

	/*
	string t;
	cout << "Enter: ";
	getline(cin, t);
	string copy(t), temp(t, 5, 10);
	cout << copy << endl << temp;
	*/

	//To Concatenate two strings, one must be a string variable --> cannot concatenate two string constants
	/*
	getline(cin, a, '0');
	a += b; //concatinate a and b strings
	cout << a.length();
	*/

	//Inserting a string:
	a.insert(a.length(), b);

	//Inserting part of a string:
	//a.insert(a.length(), b, 0, 5);//first 5 characters are inserted

	cout << endl
		 << a;

	//Erasing
	//a.erase(5, a.length()-5); //erases character from index 5 to a.length()-5
	//a.erase(5); //erases the character at index 5 to end
	a.erase(); //erases ALL the characters
	cout << endl
		 << a;

	//Searching
	a = "  Hello Hello";
	cout << a.find("Hello"); //returns 2 ----> in case of multiple: index of FIRST occurrence is returned
	cout << endl
		 << a.rfind("Hello"); //returns 8 ----> in case of multiple: index of LAST occurrence is returned
	int x = a.find("HI");	 //returns -1 since Hi is not in string a
	cout << endl
		 << x;

	//Replacing
	/*
		You can use the replace() method to perform this operation. The first two arguments supply the 
		starting position and the length of the substring to be replaced. The third argument contains 
		the replacement string.
		
		If you only need to insert part of a string, you can use the fourth argument to define
		the starting position and the fifth to define the length of the substring.
	*/
	a = "Hello my name is INSERT";
	b = "Ayush Koul";

	a.replace(a.find("INSERT"), 6, b);
	cout << endl
		 << a;

	a = "Hello my name is INSERT";

	a.replace(a.find("INSERT"), 6, b, 0, 5);
	cout << endl
		 << a;

	a.at(0) = 'h';
	a[1] = 'E';
	cout << endl << a;

	return 0;
}

/*
If s1 and s2 are strings:

(s1 == s2):
is true only if both strings are identical; this requires that both strings
are exactly the same length.

(s1 < s2): 
is true only if the first character in s1 that differs from the corresponding character in s2 is smaller than the corresponding character in s2,
or if s2 is simply an extension of s1.
*/
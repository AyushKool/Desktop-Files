// Reads integral decimal values and
// generates octal, decimal, and hexadecimal output.
#include <iostream> // Declarations of cin, cout and
#include <iomanip>
#include <stdlib.h>
#include <string>
using namespace std; // manipulators oct, hex, ...

void f4()
{
	string ch;
	cin >> setw(5) >> ch; 
	
	cout << ch;
	exit(0);
}

void f3()
{
	string ans;
	char ch;
	cin >> ch;
	
	cin.sync(); // Clears the buffer and resets
	cin.clear(); // any error flags that may be set
	
	cin >> setw(3) >> ans;//can only input one word for string this way
	cout << ch << endl << ans;
	
	exit(0);
}

void f2()
{
	
	/*
	The field width is the number of characters that can be written to a field. If the output
	string is larger than the field width, the output is not truncated but the field is extended.
	
	The output will always contain at least the number of digits specified as the field width.
	
	You can either use the width() method or the setw() manipulator to define field
	width.
	
	Example: cout.width(6); // or: cout << setw(6);
	
	One special attribute of the field width is the fact that this value is non-permanent:
	the field width specified applies to the next output only
	
	The fill character applies until another character is defined.
	
	Alignment:
	-left
	-right
	-internal
	*/
	cout << setfill('#') << setprecision(3) << setw(10) << right << fixed << 1.2 << endl;
	bool ok = true;
	cout << ok << endl // 1
	<< boolalpha << ok << endl; // true
	
	cout<<noboolalpha; //back to 1 and 0 for bool
	exit(0);
}

void f()
{
	double x = 12.0;
	cout.precision(2); // Precision 2 ---> OR setprecision(2)
	cout << " By default: " << x << endl;
	cout << " showpoint: " << showpoint << x << endl;
	cout << " fixed: " << fixed << x << endl;
	cout << " scientific: " << scientific << x << endl;

}

int main()
{	
	//f4();
	//f2();
	//f();
	int number;
	cout << "Please enter an integer: ";
	cin >> number;
	cout << nouppercase // for hex-digits
	<< " octal \t decimal \t hexadecimal\n "
	<< oct << number << " \t "
	<< dec << number << " \t "
	<< hex << number << endl;
	
	cout << dec;
	cout << showpos << 123 << endl;
	/*Same As:
	
	cout.setf( ios::showpos);
	cout << 123;
	*/
	
	cout << noshowpos << 123;
	/*Same As:
	
	cout.unsetf( ios::showpos);
	cout << 123;
	*/
	return 0;
	
}


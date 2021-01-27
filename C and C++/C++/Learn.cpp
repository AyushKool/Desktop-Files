#include <iostream> // Declaration of cin, cout
#include <string> // Declaration of class string
using namespace std;


/*
The const keyword is used to create a “read only” object. As an object of this type is
constant, it cannot be modified at a later stage and must be initialized during its definition.

EXAMPLE: const double pi = 3.1415947;

Thus the value of pi cannot be modified by the program. Even a statement such as the
following will merely result in an error message:

pi = pi + 2.0; // invalid


The keyword volatile, which is rarely used, creates variables that can be modified not
only by the program but also by other programs and external events. Events can be initiated by interrupts or by a hardware clock, for example.

EXAMPLE: volatile unsigned long clock_ticks;

Even if the program itself does not modify the variable, the compiler must assume that
the value of the variable has changed since it was last accessed. The compiler therefore
creates machine code to read the value of the variable whenever it is accessed instead of
repeatedly using a value that has been read at a prior stage.

It is also possible to combine the keywords const and volatile when declaring a
variable.

EXAMPLE: volatile const unsigned time_to_live;

Based on this declaration, the variable time_to_live cannot be modified by the program but by external events.



void srand(unsigned int seed) ---> used to initiates an algorithm to generate random numbers
int rand() ---> generates random number between 0 32767
*/


void hello(), line(), numConversion(), escapeSeq(), random();

char ch('A');

// To use strings.

/*
Globally defined functions exist for some standard classes. These functions perform certain
operations for objects passed as arguments. The global function getline(), for example, stores a line of keyboard input in a string.
Example: getline(cin, s);
The keyboard input is terminated by pressing the return key to create a new-line character, '\n', which is not stored in the string.
*/

int main()
{
	// Defines four strings:
	string prompt("What is your name: "),
	name, // An empty
	line( 40, '-'), // string with 40 '-'
	total = "Hello "; // is possible!
	cout << prompt; // Request for input.
	getline( cin, name); // Inputs a name in one line
	
	
	total = total + name; // Concatenates and
	// assigns strings.
	cout << line << endl // Outputs line and name
	<< total << endl;
	cout << " Your name is " // Outputs length
	<< name.length() << " characters long!" << endl;
	cout << line << endl;
	return 0;
}

void hello()
{
	cout << "Hello world!";
	line();
	numConversion();
}

void numConversion()
{
	//hex and dec are manipulators
	
	cout << "16 in hexadecimal is " << hex << 16 << endl;
	cout << "13 in decimal is " << dec << 0x13 << endl;
}

void escapeSeq()
{
	cout << "\a" << endl;
	cout << "hello\b" << endl;
	cout << "\t" << endl;
	cout << "\n" << endl;
	cout << "hello\v" << endl;
	cout << "hello\f" << endl;
	cout << "\r" << endl;
	cout << "\"" << endl;
	cout << "\'" << endl;
	cout << "\?" << endl;
	cout << "\\" << endl;
	cout << "\0" << endl;
	cout << "\a" << endl;
	cout << "\33" << endl;
	cout << "\x54" << endl;
}

void random()
{
	srand(56);
	for (int i=0; i<12; i++)
	cout << rand() << endl;
	
}

void line()
{
	cout << "my name is ayush" << endl;
}
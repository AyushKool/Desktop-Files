#include <bits/stdc++.h>
using namespace std;

#define tr(c) for (typeof(c.begin()) i = c.begin(); i != c.end(); i++)
#define all(c) c.begin(), c.end()

template <typename T>
void display(const T &c)
{
    cout << "\n";
    tr(c) cout << *i << " ";
    cout << "\n";
}

//Object istringstream allows you to read from a string like you do from a standard input.
void inp(const string &s)
{

    // Construct an object to parse strings
    istringstream is(s);

    // Vector to store data
    vector<int> v;

    // Read integer while possible and add it to the vector
    int tmp;
    while (is >> tmp)
    {
        v.push_back(tmp);
    }
    display(v);
}

//The ostringstream object is used to do formatting output.
string out()
{
    // Constuct an object to do formatted output
    ostringstream os;
    vector<int> v = {1, 2, 3, 4, 5};

    // Copy all elements from vector< int > to string stream as text
    tr(v)
    {
        os << ' ' << *i;
    }

    // Get string from string stream
    string s = os.str();

    // Remove first space character
    if (!s.empty())
    {
        // Beware of empty string here
        s = s.substr(1);
    }

    return s;
}

main()
{
    //inp("1 12 13 54 -7 Hello");
    cout << out();
}
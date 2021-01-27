#include <bits/stdc++.h>
using namespace std;
#define tr(container) \
    for (typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define all(v) v.begin(), v.end()
typedef vector<int> VI;
typedef pair<int, int> PII;
// void displ(VI v)//call by value -> never do this
// {
//     for(int i=0; i<v.size();i++)
//         cout << v[i] << "  ";
// }

template <typename T>
void displ(const T &a, const int &n)
{
    cout << "\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n";
}

void displ(const VI &v) //do this instead
{
    tr(v) cout << *it << " ";
    cout << endl;
}

void vect()
{
    VI v(10); //VI v (size, initilazed value for all element)

    int data[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    VI primes(data, data + (sizeof(data) / sizeof(data[0])));
    reverse(data + 2, data + 6); // the range { 5, 7, 9, 11 } is now { 11, 9, 7, 5 };

    v.push_back(2);
    displ(v);
    int n = 3, m = 4;
    vector<VI> matrix(n, VI(m, 0)); //creates matrix of nxm and sets all elements to 0
    for (int i = 0; i < matrix.size(); i++)
    {
        displ(matrix[i]);
        cout << endl;
    }
    displ(v);
    reverse(v.begin(), v.begin());
    //v.insert(2, 1);
    displ(v);
    v.pop_back();
    displ(v);
    v.erase(v.begin() + 2);
    displ(v);
    VI v2(v.begin(), v.begin() + (v.size() / 2));   //creates the vector v2 that is equal to the first half of vector v
    v2 = VI(v.rbegin() + (v.size() / 2), v.rend()); //create v2 with first half of v, ordered back-to-front
    if (find(v.begin(), v.end(), 49) != v.end())
        cout << "49 found\n";

    displ(v);
    v.erase(v.begin()); //erases elements at index i
    displ(v);
    v.erase(v.begin() + 2, v.end()); //erases all element from [start, end)
    displ(v);

    //the index of element found, one should subtract the beginning iterator from the result of find()
    int i = (find(v.begin(), v.end(), 49) - v.begin());
    int ele = *max_element(data, data + 5);      // Returns value of max element in array
    int i3 = min_element(data, data + 5) - data; // Returns index of min element in array

    VI X(data, data + 5);
    int v1 = *max_element(X.begin(), X.end());            // Returns value of max element in vector
    int i1 = min_element(X.begin(), X.end()) - X.begin(); // Returns index of min element in vector
    sort(X.rbegin(), X.rend());                           // Sort array in descending order using with reverse iterators

    v.insert(v.begin() + 1, 2);
    displ(v);

    v2.push_back(1);
    v2.push_back(2);
    v2.push_back(3);
    v.insert(v.begin() + 1, all(v2)); //inserts all of v2 at index 1 of v
    displ(v);
}

void displ(const PII &p)
{
    cout << "(" << p.first << ", " << p.second << ")\n";
}

void displ(const vector<PII> &v)
{
    for (int i = 0; i < v.size(); i++)
        displ(v[i]);
}

bool cmp(PII a, PII b)
{
    return a.second > b.second;
}

void Pair()
{
    vector<PII> p(3);
    for (int i = 0; i < 3; i++)
    {
        p[i].first = i + 1;
        p[i].second = i + 2;
    }
    p.push_back(PII(2, 4));

    cout << "\nBefore sort:\n";
    for (PII x : p)
        displ(x);

    sort(p.begin(), p.end(), cmp); //or
    stable_sort(p.begin(), p.end(), cmp);
    cout << "\nAfter sort:\n";
    for (PII x : p)
        displ(x);
    cout << (p[1] > p[2]); //compares "first" first then "second" (only if first is equal)
}

template <typename T>
void swaper(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
void reverser(T *f, int n)
{
    for (int i = 0; i < n / 2; i++)
        swaper<T>(f[i], f[n - 1 - i]);
}

void f(const vector<int> &v)
{
    int r = 0;
    // Traverse the vector using const_iterator
    for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++)
    {
        r += *it;
    }
    cout << r << "\n";
}

void Templates()
{
    int a[] = {1, 2, 3, 4}, n = sizeof(a) / sizeof(int);
    displ(a, n);
    reverser<int>(a, n);
    displ(a, n);
    VI v(a, a + n);
    tr(v) cout << *it << " ";
    cout << "\n";
    f(v);
    //Doesn't work for array
    // for (int x : a)
    //     cout << a << " ";

    /*
    In spite of this, let me tell about very important feature of GNU C++ called ‘typeof’.
    This operator is replaced to the type of an expression during the compilation.
    Consider the following example :
    */
    int x, y;
    typeof(x + y) ans = (x + y);
}

void Strings()
{
    string s = "hello";
    string s1 = s.substr(0, 3),           // "hel"
        s2 = s.substr(1, 3),              // "ell"
        s3 = s.substr(0, s.length() - 1), // "hell"
        s4 = s.substr(1);                 // "ello"
    /*
    Beware of (s.length()-1) on empty string because 
    s.length() is unsigned and unsigned(0) – 1 is definitely not what you are expecting!
    */
}

main()
{
    // vect();
    // Templates();
    //Pair();
}
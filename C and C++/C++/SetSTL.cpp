/*
Consider we need a container with the following features:
- add an element, but do not allow duples [duplicates?]
- remove elements
- get count of elements (distinct elements)
- xcheck whether elements are present in set

This is quite a frequently used task. STL provides the special container for it – set. 
Set can add, remove and check the presence of particular element in O(log N), 
where N is the count of objects in the set. While adding elements to set, the duplicates are discarded. 
A count of the elements in the set, N, is returned in O(1). 
We will speak of the algorithmic implementation of set and map later — for now, let’s investigate its interface:
*/

#include <bits/stdc++.h>
using namespace std;
#define tr(c) for (typeof(c.begin()) i = c.begin(); i != c.end(); i++)
typedef set<int> SI;
typedef vector<int> VI;
/*
Here, ‘present()’ returns whether the element presents in the container with member function 
‘find()’ (i.e. set/map, etc.) while ‘cpresent’ is for vector.
*/
#define present(container, element) (container.find(element) != container.end())
#define cpresent(container, element) (find(all(container), element) != container.end())
#define all(c) c.begin(), c.end()
template <typename T>
void display(const T &c)
{
    cout << "\n";
    tr(c) cout << *i << " ";
    cout << "\n";
}

main()
{
    SI s;
    for (int i = 1; i <= 100; i++)
        s.insert(i); // Insert 100 elements, [1..100]

    s.insert(42); // does nothing, 42 already exists in set

    for (int i = 2; i <= 100; i += 2)
        s.erase(i); // Erase even values

    int n = int(s.size()); // n will be 50
    display(s);
    set<pair<string, pair<int, vector<int>>>> SS;
    int total = 0;
    tr(SS)
        total += i->second.first;
    if (s.find(42) != s.end())
        cout << "42 is present";
    else
        cout << "42 isn't present";
    s.count(2); //return 1 or 0

    set<int>::iterator it1, it2;
    it1 = s.find(11);
    it2 = s.find(87);
    s.erase(1);
    // Will work if it1 and it2 are valid iterators, i.e. values 10 and 100 present in set.
    s.erase(it1, it2); // Note that 11 will be deleted, but 87 will remain in the container
    display(s);
    s.insert(22);
    display(s);

    //Interval constructor
    int data[] = {5, 1, 4, 2, 3, 3, 4, 5, 5, 4, 3, 2, 1, 1, 1, 3};
    n = sizeof(data) / sizeof(*data);
    s = SI(data, data + 5);
    display(s);

    //It gives us a simple way to get rid of duplicates in vector, and sort it :
    VI v(data, data + n);
    display(v);
    s = SI(all(v));
    v = VI(all(s));
    display(s);
    display(v);
}
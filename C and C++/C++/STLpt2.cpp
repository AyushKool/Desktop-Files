#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(), (c).end()
#define tr(c) for (typeof(c.begin()) i = c.begin(); i != c.end(); i++)
#define tr2(c, n) for (typeof(c.begin()) i = c.begin(); i != n; i++)

typedef vector<int> VI;

template <typename T>
void display(const T &v)
{
    cout << "\n";
    tr(v) cout << *i << " ";
    cout << "\n";
}

template <typename T>
void display(const T &v, VI::iterator n)
{
    cout << "\n";
    tr2(v, n) cout << *i << " ";
    cout << "\n";
}

void VectToMap()
{
    map<string, int> m;
    m["a"] = 1;
    m["b"] = 2;
    m["c"] = 3;
    m["d"] = 4;

    vector<pair<string, int>> v(all(m));
    //display(v);
}

void copyData()
{
    vector<int> v1 = {1, 2, 3, 4};
    vector<int> v2 = {5, 6, 7};

    // Now copy v2 to the end of v1
    v1.resize(v1.size() + v2.size());
    // Ensure v1 have enough space
    copy(all(v2), v1.end() - v2.size());
    display(v1);

    vector<int> v = {6, 7, 7, 8};
    set<int> s = {1, 2, 3, 4, 4, 4, 4, 5, 5, 5, 52, 2, 2};
    // add some elements to set
    copy(all(v), inserter(s, s.begin()));
    display(s);
    copy(all(s), inserter(v, v.begin() + 2));
    display(v);
    // Copy v2 elements right after v1 ones
    /*
    copy(all(s), inserter(v, v.begin())) means:
    tr(v)
        s.insert(*it);
    */
}

void merge()
{
    int data1[] = {1, 2, 5, 6, 8, 9, 10};
    int data2[] = {0, 2, 3, 4, 7, 8, 10};

    vector<int> v1(data1, data1 + sizeof(data1) / sizeof(data1[0]));
    vector<int> v2(data2, data2 + sizeof(data2) / sizeof(data2[0]));

    vector<int> tmp(max(v1.size(), v2.size()));
    vector<int> res = vector<int>(tmp.begin(), set_intersection(all(v1), all(v2), tmp.begin()));

    display(tmp, set_intersection(all(v1), all(v2), tmp.begin()));
    display(res);

    set<int> s1 = {1, 2, 3, 4, 5, 6, 7, 8, 9}, s2 = {2, 4, 6, 8};
    static int temp[5000]; // greater than we need
    res = VI(temp, set_symmetric_difference(all(s1), all(s2), temp));
    int cnt = set_symmetric_difference(all(s1), all(s2), temp) - temp;
    display(res);

    /*
     It is constructed via interval constructor, and the beginning of the interval will be the beginning 
     of tmp. The end of the interval is the result of the set_intersection algorithm. This algorithm will 
     intersect v1 and v2 and write the result to the output iterator, starting from 'tmp.begin()'. Its return 
     value will actually be the end of the interval that forms the resulting dataset.
    */
    cnt = set_intersection(all(v1), all(v2), tmp.begin()) - tmp.begin();
}

main()
{
    //copyData();
    merge();
}
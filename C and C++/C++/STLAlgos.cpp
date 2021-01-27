/*
It’s time to speak about algorithms a bit more deeply. Most algorithms are declared in the #include < algorithm > standard header. 
At first, STL provides three very simple algorithms: min(a,b), max(a,b), swap(a,b). Here min(a,b) and max(a,b) returns the minimum 
and maximum of two elements, while swap(a,b) swaps two elements.

Algorithm sort() is also widely used. The call to sort(begin, end) sorts an interval in ascending order. Notice that sort() requires 
random access iterators, so it will not work on all containers. However, you probably won’t ever call sort() on set, which is already ordered.

You’ve already heard of algorithm find(). The call to find(begin, end, element) returns the iterator where ‘element’ first occurs, 
or end if the element is not found. Instead of find(…), count(begin, end, element) returns the number of occurrences of an element 
in a container or a part of a container. Remember that set and map have the member functions find() and count(), which works in O(log N), 
while std::find() and std::count() take O(N).

Other useful algorithms are next_permutation() and prev_permutation(). Let’s speak about next_permutation. The call to next_permutation(begin, end) 
makes the interval [begin, end] hold the next permutation of the same elements, or returns false if the current permutation is the last one. 
Accordingly, next_permutation makes many tasks quite easy. If you want to check all permutations, just write:

vector< int > v;

for(int i = 0; i < 10; i++) {
v.push_back(i);
}

do {
Solve(..., v);
} while(next_permutation(all(v));

Don’t forget to ensure that the elements in a container are sorted before your first call to next_permutation(…). 
Their initial state should form the very first permutation; otherwise, some permutations will not be checked.
*/

#include <bits/stdc++.h>
using namespace std;
#define tr(c) for (typeof(c.begin()) i = c.begin(); i != c.end(); i++)
#define all(c) c.begin(), c.end()
typedef vector<int> vi;

template <typename T>
void display(const T &c)
{
    cout << "\n";
    tr(c) cout << *i << " ";
    cout << "\n";
}

void permute()
{
    vi v;

    for (int i = 1; i <= 5; i++)
        v.push_back(i);

    int i = 0;
    do
    {
        i++;
        tr(v) cout << *i << " ";
        cout << endl;
    } while (next_permutation(all(v)));
    display(v);
    prev_permutation(all(v));
    display(v);
    cout << i; //equals be n! where n is v.size()
}

void basic()
{
    
    // Initializing vector with array values 
    int arr[] = {10, 20, 5, 23 ,42 , 15}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    vector<int> vect(arr, arr+n); 
  
    cout << "Vector is: "; 
    for (int i=0; i<n; i++) 
        cout << vect[i] << " "; 
  
    // Sorting the Vector in Ascending order 
    sort(vect.begin(), vect.end()); 
  
    cout << "\nVector after sorting is: "; 
    for (int i=0; i<n; i++) 
       cout << vect[i] << " "; 
  
    // Reversing the Vector 
    reverse(vect.begin(), vect.end()); 
  
    cout << "\nVector after reversing is: "; 
    for (int i=0; i<6; i++) 
        cout << vect[i] << " "; 
  
    cout << "\nMaximum element of vector is: "; 
    cout << *max_element(vect.begin(), vect.end()); 
  
    cout << "\nMinimum element of vector is: "; 
    cout << *min_element(vect.begin(), vect.end()); 
  
    // Starting the summation from 0 
    cout << "\nThe summation of vector elements is: "; 
    cout << accumulate(vect.begin(), vect.end(), 0);

    vect = vi(arr, arr+n); 
  
    cout << "Occurrences of 20 in vector : "; 
  
    // Counts the occurrences of 20 from 1st to 
    // last element 
    cout << count(vect.begin(), vect.end(), 20); 
  
    // find() returns iterator to last address if 
    // element not present 
    find(vect.begin(), vect.end(),5) != vect.end()? 
                         cout << "\nElement found": 
                     cout << "\nElement not found"; 


    vect = vi(arr, arr+n); 
  
    // Sort the array to make sure that lower_bound() 
    // and upper_bound() work. 
    sort(vect.begin(), vect.end()); 
  
    // Returns the first occurrence of 20 
    auto q = lower_bound(vect.begin(), vect.end(), 20); 
  
    // Returns the last occurrence of 20 
    auto p = upper_bound(vect.begin(), vect.end(), 20); 
  
    cout << "The lower bound is at position: "; 
    cout << q-vect.begin() << endl; 
  
    cout << "The upper bound is at position: "; 
    cout << p-vect.begin() << endl; 
}

void manipulate()
{
    int arr[] = {5, 10, 15, 20, 20, 23, 42, 45}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    vector<int> vect(arr, arr+n); 
  
    cout << "Vector is :"; 
    for (int i=0; i<6; i++) 
        cout << vect[i]<<" "; 
  
    // Delete second element of vector 
    vect.erase(vect.begin()+1); 
  
    cout << "\nVector after erasing the element: "; 
    for (int i=0; i<5; i++) 
        cout << vect[i] << " "; 
  
    // sorting to enable use of unique() 
    sort(vect.begin(), vect.end()); 
  
    cout << "\nVector before removing duplicate "
             " occurrences: "; 
    for (int i=0; i<5; i++) 
        cout << vect[i] << " "; 
  
    // Deletes the duplicate occurrences 
    vect.erase(unique(vect.begin(),vect.end()),vect.end()); 
  
    cout << "\nVector after deleting duplicates: "; 
    for (int i=0; i< vect.size(); i++) 
        cout << vect[i] << " "; 
}

main()
{
    vi v = {3,4,54,3,4,4,5,4};
    sort(v.begin(), v.end());
    cout << *unique(v.begin(), v.end());
    display(v);
}
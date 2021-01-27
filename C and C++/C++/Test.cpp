#include <bits/stdc++.h>

// #define in for(int i=0; i<n; i++) \
// 	cin >> a[i];
// #define out for(int i=0; i<n; i++) \
// 	cout << a[i];
// #define square(a) ((a)*(a))
// #define CLS (cout << "\033[2J")
// #define cin std::cin
// #define cout std::cout
using namespace std;

class T
{
	// static int i;
	// int x;
	public:
	// T()
	// {
	// 	cout << "Constructor 1" << endl;
	// }
	// T(int i)
	// {
	// 	cout << "Constructor 2" << endl;
	// }
};

//int T::i;
/*
Use #undef to undefine a macro. Then you can redefine it if you want
*/
int main()
{
	//T obj;//calls user defined default constructor
	//T obj();//calls comipler defined default constructor
	// int x = 770528134;
	// cout << x%5;
	
	set<int> s;
	s.insert(2);
	s.erase(3);
	for(auto x : s)
		cout << x << " ";
	//cout << (1<<31);
	/*
	int a = -5;
	unsigned b = a;
	
	cout << b << endl << b+5 << endl << b+6;
	*/
	
	// int i = -2; 
	// unsigned int ui = 2;
	// i = i * ui;
	
	// cout << i << endl << ui;
	//cout << "hello";
}
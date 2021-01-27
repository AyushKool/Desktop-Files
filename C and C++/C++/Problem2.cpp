#include <iostream>
#include <string>
#include <vector>

using namespace std;

int findP(vector<pair<string, int>> v, string s)
{
	for (int i=0; i<v.size();i++)
		if(v[i].first == s)
			return i;
	return -1;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, i=0, count = 0;
		cin >> n;
		vector<pair<string, int>> names;
		while(i<n)
		{
			string s;
			cin >> s;
			int ind = findP(names, s);
			if (ind != -1)
				names[ind].second++;
			else
				names.push_back(make_pair(s,1));
			i++;
		}
		for (i=0;i<n;i++)
			if (names[i].second%2==1)
				count++;
		cout << count << endl;
	}
	return 0;
}
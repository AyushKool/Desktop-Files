#include <iostream>
#include <string>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int m, n, rx, ry, len, x = 0, y = 0;
		string seq;
		cin >> m >> n >> rx >> ry >> len >> seq;
		while(len--)
		{
			switch(seq[len])
			{
				case 'U':
					y++;
					break;
				case 'D':
					y--;
					break;
				case 'L':
					x--;
					break;
				case 'R':
					x++;
			}
		}
		if (x==rx && y==ry)
			cout << "REACHED";
		else if (x>m || x<0 || y>n || y<0)
			cout << "DANGER";
		else
			cout << "SOMEWHERE";
	}
	return 0;
}
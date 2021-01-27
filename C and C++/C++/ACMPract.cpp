#include <stdio.h>
#include <string.h>

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		char s[60];
		scanf("%s", s);
		int n = strlen(s);
		int i = 0;
		int left = -20;
		int safe = 1;
		while (i < n)
		{
			while ((s[i] == '.') && (i < n))
				i++;
			if (i < n)
			{
				if (i - (s[i] - '0') > left)
					left = i + s[i] - '0';
				else
				{
					safe = 0;
					break;
				}
				i++;
			}
		}
		if (safe)
			printf("Safe\n");
		else
			printf("Unsafe\n");
	}
}
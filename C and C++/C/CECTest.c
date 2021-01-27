#include <stdio.h>
void containsGE()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        unsigned short flag = 0;
        char ch, *p = "graphicera";
        fflush(stdin);
        do
        {
            ch = getchar();
            if(ch == *p)
                ++p;
            if(*p=='\0')
                flag = 1;
        } while (ch != '\n');
        printf(flag ? "YES\n" : "NO\n");
    }
}

int main()
{
}
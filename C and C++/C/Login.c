#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
void main()
{
    FILE *id, *contacts, *chat, *list, *temp, *user;
    int n, i, cnt = 0;
    char a[50], a_contacts[50], a_list[50], p[20], a_1[20], ch, a_fr[50], a_fr2[50];
    char name[50], mess[100], send[50], rec[50], a_user[50];
A:
    system("cls");
    printf("->Press 1 to Sign up.\n");
    printf("->Press 2 to Log in.\n->Press any key to exit\n");
    ch = getch();
    if (ch == '1')
    {
        system("cls");
        fflush(stdin);
        printf("Enter your ID(USER NAME) : ");
        gets(a);

        user = fopen("user.txt", "r");
        i = 0;
        while ((ch = getc(user)) != EOF)
        {
            if (ch != '\n')
            {

                a_user[i] = ch;
                i++;
            }
            else
            {
                a_user[i] = '\0';

                if (strcmp(a, a_user) == 0)
                {
                    printf("\nID already exist!\n\nTry with a unique ID\n\nPress any key....");
                    fclose(user);
                    getch();
                    goto A;
                }

                else
                {
                    i = 0;
                }
            }
        }

        fclose(user);

        strcpy(a_user, a);
        strcpy(a_list, a);
        strcpy(a_contacts, a);

        strcat(a, ".txt");
        strcat(a_list, "@list.txt");
        strcat(a_contacts, "@contacts.txt");

        printf("Enter your Password: ");
        gets(p);

        id = fopen(a, "w");
        fputs(p, id);
        fclose(id);

        contacts = fopen(a_contacts, "w");

        list = fopen(a_list, "w");

        fclose(contacts);

        fclose(list);

        user = fopen("user.txt", "a");
        fputs(a_user, user);
        putc('\n', user);
        fclose(user);

        printf("\nSign up successful!\n");

        printf("\nPress any key to continue......");
        getch();
        system("cls");
        goto A;
    }
    else if (ch == '2')
    {
    B:
        system("cls");
        fflush(stdin);
        printf("Enter Your ID : ");
        gets(a);
        strcpy(name, a);
        strcpy(a_list, a);
        strcpy(a_contacts, a);

        strcat(a_list, "@list.txt");
        strcat(a, ".txt");
        strcat(a_contacts, "@contacts.txt");

        id = fopen(a, "r");
        if (id == NULL)
        {
            puts("\n\nInvalid ID!\n\n");
            printf("\n\n->Press [L] to Login\n->Press [B] to go to main menu\n");
            ch = getch();
            if (ch == 'l')
                goto B;
            else if (ch == 'b')
                goto A;
        }
        printf("Enter Your Password : ");
        gets(a_1);

        fgets(a, 20, id);

        if (strcmp(a, a_1) == 0)
        {
            printf("\nLog in successful!");

            fclose(id);
            printf("\n\nEnter any key to continue......");
            getch();
        }
        else
        {
            printf("\n\nInvalid Password!\n\n");
            fclose(id);
            printf("\nPress any key....");
            getch();
            goto B;
        }
    }
    else
        exit(0);

C:
    system("cls");
    printf("1->Contacts\n2->Chats\n3->Add friends to contact list\n4->See friend requests\n5->Log Out");
    ch = getch();
    if (ch == '1')
    {
        system("cls");
        contacts = fopen(a_contacts, "r");
        fseek(contacts, 0, SEEK_END);
        if (ftell(contacts) == 0)
        {
            printf("Empty List!\n");
            fclose(contacts);
            printf("\n\nEnter any key to go back......");
            getch();
            goto C;
        }
        else
        {
            fseek(contacts, 0, SEEK_SET);
            printf("1->");
            i = 2;
            while ((ch = getc(contacts)) != EOF)
            {
                if (ch != '\n')
                    putchar(ch);
                else
                {
                    printf("\n%d->", i);
                    i++;
                }
            }
            printf("END OF LIST");
            fclose(contacts);
            printf("\nPress any key to go back....");
            getch();
            goto C;
        }
    }

    else if (ch == '2')
    {
        system("cls");
        printf("Available Contacts to chat:-\n");

        contacts = fopen(a_contacts, "r");
        fseek(contacts, 0, SEEK_END);
        if (ftell(contacts) == 0)
        {
            printf("\nNo friends available!\nAdd some friends!\n");
            fclose(contacts);
            printf("\n\nEnter any key to go back......");
            getch();
            goto C;
        }
        else
        {
            fseek(contacts, 0, SEEK_SET);
            printf("1->");
            i = 2;
            while ((ch = getc(contacts)) != EOF)
            {
                if (ch != '\n')
                    putchar(ch);
                else
                {
                    printf("\n%d->", i);
                    i++;
                }
            }
            printf("END OF LIST\n");
            ch = getch();
            n = ch - 48;
            rewind(contacts);

            for (i = 1; i < n; i++)
            {
                while ((ch = getc(contacts)) != '\n')
                    continue;
            }
            i = 0;
            while ((ch = getc(contacts)) != '\n')
            {
                a_fr[i] = ch;
                i++;
            }
            a_fr[i] = '\0';
            fclose(contacts);
            send[0] = '\0';
            rec[0] = '\0';

            strcat(send, name);
            strcat(send, "+");
            strcat(send, a_fr);
            strcat(send, ".txt");

            strcat(rec, a_fr);
            strcat(rec, "+");
            strcat(rec, name);
            strcat(rec, ".txt");

            chat = fopen(send, "a");
            fclose(chat);
            chat = fopen(rec, "a");
            fclose(chat);

        D:
            system("cls");
            printf("Chats with ");
            puts(a_fr);
            printf("---------------------------------------\n");
            chat = fopen(send, "r");
            fseek(chat, 0, SEEK_END);
            if (ftell(chat) == 0)
            {
                printf("\nNO messages yet!\n");
                fclose(chat);
            }
            else
            {
                fseek(chat, 0, SEEK_SET);

                while ((ch = getc(chat)) != EOF)
                {
                    putchar(ch);
                }
                fclose(chat);
            }

            fflush(stdin);
            printf("\n->Press [C] to type message\n->Press [B] to go back");
            ch = getch();
            if (ch == 'b')
                goto C;
            else if (ch == 'c')
            {

                printf("\n\nINPUT YOUR MESSAGE : ");
                gets(mess);
                system("cls");
                printf("Chats with ");
                puts(a_fr);
                printf("---------------------------------------\n");
                chat = fopen(send, "a");
                fputs("ME: ", chat);
                fputs(mess, chat);
                putc('\n', chat);
                fclose(chat);

                chat = fopen(rec, "a");
                fputs(name, chat);
                fputs(": ", chat);
                fputs(mess, chat);
                putc('\n', chat);

                fclose(chat);

                chat = fopen(send, "r");
                while ((ch = getc(chat)) != EOF)
                {
                    putchar(ch);
                }
                fclose(chat);

                printf("->Press [M] to send more message\n->Press [B] to go back");
                ch = getch();
                if (ch == 'm')
                    goto D;
                else if (ch == 'b')
                    goto C;
            }
        }
    }

    else if (ch == '3')
    {
        system("cls");
        printf("Enter your friends ID : ");
        gets(a_fr);

        contacts = fopen(a_contacts, "r");
        i = 0;
        while ((ch = getc(contacts)) != EOF)
        {
            if (ch != '\n')
            {

                a_user[i] = ch;
                i++;
            }
            else
            {
                a_user[i] = '\0';

                if (strcmp(a_fr, a_user) == 0)
                {
                    printf("\nYou are already friend with ");
                    puts(a_fr);
                    printf("\n\nPress Any Key.....");
                    fclose(contacts);
                    getch();
                    goto C;
                }

                else
                {
                    i = 0;
                }
            }
        }

        fclose(contacts);

        strcpy(a_fr2, a_fr);
        strcat(a_fr2, "@list.txt");
        strcat(a_fr, ".txt");
        id = fopen(a_fr, "r");
        if (id == NULL)
        {
            printf("\n\nInvalid user ID!");
            printf("\n\nEnter any key to go back......");
            getch();
            goto C;
        }
        else
        {
            list = fopen(a_fr2, "a");
            fputs(name, list);
            putc('\n', list);
            fclose(list);
            printf("\n\nFriend Request Sent!\n\nPress any key..........");
            getch();
            goto C;
        }
    }

    else if (ch == '4')
    {
        system("cls");
        list = fopen(a_list, "r");
        fseek(list, 0, SEEK_END);
        if (ftell(list) == 0)
        {
            printf("No Friend Requests Available!\n");
            fclose(list);
            printf("\n\nEnter any key to go back......");
            getch();
            goto C;
        }
        else
        {
            fseek(list, 0, SEEK_SET);
            printf("1->");
            i = 2;
            while ((ch = getc(list)) != EOF)
            {
                if (ch != '\n')
                    putchar(ch);

                else
                {
                    printf("\n%d->", i);
                    i++;
                }
            }
            printf("END OF LIST");
            fclose(list);

            printf("\n\n->Press [Y] to accept request number 1\n->Press [N] to reject request number 1\n->Press [B] to go back  ");
            fflush(stdin);
            ch = getch();

            if (ch == 'b')
                goto C;
            else if (ch == 'y')
            {
                list = fopen(a_list, "r");
                i = 0;
                while ((ch = getc(list)) != '\n')
                {
                    a_fr[i] = ch;
                    i++;
                }
                a_fr[i] = '\0';
                fclose(list);

                contacts = fopen(a_contacts, "a");
                fputs(a_fr, contacts);
                putc('\n', contacts);
                fclose(contacts);
                strcat(a_fr, "@contacts.txt");
                contacts = fopen(a_fr, "a");
                fputs(name, contacts);
                putc('\n', contacts);
                fclose(contacts);

                list = fopen(a_list, "r");
                while ((ch = getc(list)) != '\n')
                {
                    continue;
                }

                temp = fopen("temp.txt", "w");
                while ((ch = getc(list)) != EOF)
                {
                    putc(ch, temp);
                }

                fclose(list);
                fclose(temp);

                list = fopen(a_list, "w");
                temp = fopen("temp.txt", "r");
                while ((ch = getc(temp)) != EOF)
                {
                    putc(ch, list);
                }

                fclose(list);
                fclose(temp);

                printf("\n\nFriend is successfully added!\n\nPress any key....");
                getch();
                goto C;
            }
            else if (ch == 'n')
            {
                list = fopen(a_list, "r");
                while ((ch = getc(list)) != '\n')
                {
                    continue;
                }

                temp = fopen("temp.txt", "w");
                while ((ch = getc(list)) != EOF)
                {
                    putc(ch, temp);
                }

                fclose(list);
                fclose(temp);

                list = fopen(a_list, "w");
                temp = fopen("temp.txt", "r");
                while ((ch = getc(temp)) != EOF)
                {
                    putc(ch, list);
                }

                fclose(list);
                fclose(temp);

                printf("\nRequest Rejected!\nPress any key....");
                getch();
                goto C;
            }
        }
    }

    else if (ch == '5')
    {
        printf("\n\nLogged out successfully!\n\nPress any key....");
        getch();
        goto A;
    }
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum state{menu,loggedin};
enum state currentstate=menu;

typedef struct user
{
    char username[100];
    char password[100];
    char place[100];
    int price;
    int numtick;
    struct user *next;
}user;
void ownpack();
void ShowBrochure();
user* InitializeList(user*);
user* AddUser(user*);
void LoginUser(user*);
void BookTicket(user*);
void PrintTicket(user*);
void CancelTicket(user*);
void ChangePassword(user*);
void LogoutUser();
void CheckTicket(user*);
void DisplayAll(user*);
void WriteToFile(user*);
void ExitProgram();

char currentuser[100];

int main()
{
    printf("\t\t\t\t\t==== || Super Tourisms || ====\n");
    user *h=NULL;
    int ch1,ch2;
    h=InitializeList(h);
    while (1)
    {

        if(currentstate==menu)
        {
 printf("\033[0;32m");
            printf("\n\n\t\t\t\t1: Admin Login\n\n\t\t\t\t2: Sign Up\n\n\t\t\t\t3: Sign In\n\n\t\t\t\t4: Brochure \n\n\t\t\t\t5: Exit\n\n\t\t\t\tEnter:");
            scanf("%d",&ch1);

            switch(ch1)
            {
                case 1:
                    admin();
                    break;
                case 2:
                    h=AddUser(h);
                    break;
                case 3:
                    LoginUser(h);
                    break;
                case 4:
                    ShowBrochure();
                    break;
                case 5:
                    ExitProgram();
                    exit(0);
                    break;
                default:
                    printf("Not a valid input at this stage\n");
            }
        }
        else if(currentstate==loggedin)
        {
        system("CLS");
 printf("\033[0;32m");
        printf("\n\t\t\t\t=========================");
        printf("\n\t\t\t\tSUPER TOURISMS");
        printf("\n\t\t\t\t=========================\n");
            printf("\n\t\t\t\tBook Package - 1\n\t\t\t\tCreate Package - 2\n\t\t\t\tCheck Ticket - 3\n\t\t\t\tSave Ticket - 4\n\t\t\t\tCancel Ticket - 5\n\t\t\t\tChange Password - 6"                   "\n\t\t\t\tLogout User - 7\n\t\t\t\tBrochure - 8\n\t\t\t\tContact & Issue Registration - 9\n\t\t\t\tExit - 10\n");
            scanf("%d",&ch2);
            switch(ch2)
            {
                case 1:
                    BookTicket(h);
                    system("PAUSE");
                    system("CLS");
                    break;
               case 2:
                    ownpack(h);
                    system("PAUSE");
                    system("CLS");
                    break;
                case 3:
                    CheckTicket(h);

                    system("PAUSE");
                    system("CLS");
                    break;
                case 4:
                    PrintTicket(h);
                    system("PAUSE");
                    system("CLS");
                    break;
                case 5:
                    CancelTicket(h);
                    system("PAUSE");
                    system("CLS");
                    break;
                case 6:
                    ChangePassword(h);
                    system("PAUSE");
                    system("CLS");
                    break;
                case 7:
                    LogoutUser(h);
                    system("PAUSE");
                    system("CLS");
                    break;
                case 8:
                    ShowBrochure();
                    system("PAUSE");
                    system("CLS");
                    break;
                case 9:
                    contact();
                    system("PAUSE");
                    system("CLS");
                    break;
                case 10:
                    ExitProgram();
                    exit(0);
                    break;
                default:
                    printf("Not a valid input at this stage\n");
            }
        }
    }
    return 0;
}
void admin()
{
    int i;
    int e;

    char ch;
    char pwd[10];
    char a[30];
    char a1[30]="super@534";
    printf("\nEnter Username: ");
    fflush(stdin);
    gets(a);
    if(strcmp(a,"s")==0)
    {
       printf("\nEnter Password: ");
       for(i=0;i<10;i++)
 {
     ch=getch();
     pwd[i]=ch;
     if(ch!=13)
        printf("*");
     if(ch==13)
        break;
 }
 pwd[i]='\0';
      if(strcmp(pwd,"s")==0)
      {
          char s[30000];
    int i;
    FILE *ap1,*ap2,*ap3;
    ap1=fopen("D:/users.txt","r+");
    ap2=fopen("D:/issue.txt","r");
    ap3=fopen("D:/main.txt","r+");
    int a;
    while(1)
    {
    printf("\n\n1.User Details");
    printf("\n\n2.Issues Received");
    printf("\n\n3.Logout");
    printf("\n\nYour Response: ");
    scanf("%d",&a);

    if(a==1)
    {
        printf("\n");
        fread(s,sizeof(s),1,ap1);
        puts(s);
        currentstate==menu;
    }
    else if(a==2)
    {

        printf("\n");
        fread(s,sizeof(s),1,ap2);
        long result=ftell(ap2);
        if(result==0)
        {
            printf("No issues received yet.");
            currentstate==menu;
        }
        puts(s);
        currentstate==menu;
    }
    else if(a==3)
    {
    if(currentstate==menu || strcmp(currentuser,"\0")==0)
    {
       printf("\nLogged out successfully.\n");
       return;
    }
    }
    else
    {
        printf("\n!Invalid Input");
    }
    }
    fclose(ap1);
     fclose(ap2);
      }
      else
      {
          printf("\n!Wrong Password");
      }
    }
    else
    {
      printf("\n!Wrong Username");
    }
}

void contact()
{
    char issue[500];
    printf("Having Any Issue or Needed Help?");
    printf("\n\nReach us through any below way:");
    printf("\n\nCall us on: 8625078177 / 7447615682");
    printf("\nEmail us on: supertourisms@gmail.com");
    printf("\n\n*************OR*************");
    printf("\n\nPlease write your issue below:\n");
    fflush(stdin);
    gets(issue);
    FILE *sp;
    sp=fopen("D:/issue.txt","a+");
    fputs(issue,sp);
    fclose(sp);
}
user* InitializeList(user *h)
{
    user* t,*ptr,temp;
    FILE *fp;
    int cc=0,x;
    int ff;
    fp=fopen("D:/users.txt","r");

    if(fp==NULL)
        return NULL;

    if(fgetc(fp)==EOF)
        return NULL;

    rewind(fp);
    while(fscanf(fp,"%s %s %s %d %d",temp.username,temp.password,temp.place,&temp.price,&temp.numtick)!=EOF)
    {
        ptr=(user*)malloc(sizeof(user));
        strcpy(ptr->username,temp.username);
        strcpy(ptr->password,temp.password);
        strcpy(ptr->place,temp.place);
        ptr->price=temp.price;
        ptr->numtick=temp.numtick;
        ptr->next=NULL;

        if(h==NULL)
            h=t=ptr;
        else
        {
            h->next=ptr;
            h=ptr;
        }
    }
    fclose(fp);
    return t;
}

void WriteToFile(user *h)
{
    FILE *fp;
    fp=fopen("D:/users.txt","w");
    while(h!=NULL)
    {
        fprintf(fp,"%s %s %s %d %d\n",h->username,h->password,h->place,h->price,h->numtick);
        h=h->next;
    }
    fclose(fp);
}

void ShowBrochure()
{
    system("CLS");
    printf("\033[0;32m");
    printf("  BROCHURE(with tour codes & price list)\n==========================================\n\n1. 11 - Jammu & Kashmir Tours - Rs.40000/-\n\n2. 14 - Grand Canyon Local Tours - Rs.60000/-\n\n3. 16 - Sri Lanka Local Tours - Rs.25000/-\n\n4. 19 - Miami Vacation - Rs.38000/\n\n""5. 21 - Hawaii - Rs.120000/-\n\n6. 24 - Goa Vacation - Rs.10000/-\n\n7. 26 - Australia & New Zealand Grand Tour - Rs.210000/-\n\n8. 29 - Alaska Vacation - Rs.32000/-\n\n9. 31 - Odisha & Kolkata Grand Vacation - Rs.45000/-\n\n10. 34 - Switzerland Tour -Rs.180000/-\n\n");
}

void CheckTicket(user *h)
{
    while(h!=NULL)
    {
        if(!strcmp(h->username,currentuser))
            break;
        h=h->next;
    }
    if(!strcmp(h->place,"\0") || h->numtick==0)
    {
        printf("You haven't booked any ticket yet.\n");
        return;
    }
    printf("You have booked %d tickets for a sum total of Rs.%d/- for places: %s\n",h->numtick,h->price,h->place);
}

user* AddUser(user* h)
{
    int i;
    char ch;
    char pwd[10];
    user *t;
    t=h;
   user *nw;
    nw=(user*)malloc(sizeof(user));
    printf("Enter username or email\n");
    scanf("%s",nw->username);
    while(h!=NULL)
    {
        if(!strcmp(h->username,nw->username))
        {
            printf("That email already exists\n");
            return t;
        }
        h=h->next;
    }
    h=t;
    printf("Enter password\n");
 for(i=0;i<10;i++)
 {
     ch=getch();
     pwd[i]=ch;

     if(ch!=13)
        printf("*");
     if(ch==13)
        break;
 }
 pwd[i]='\0';
    strcpy(nw->password,pwd);
    nw->next=NULL;
    strcpy(nw->place,"N/A");
    nw->price=0.0;
    nw->numtick=0;

    if(h==NULL)
    {
        h=t=nw;
    }
    else
    {
        while(h->next!=NULL)
        {
            h=h->next;
        }
        h->next=nw;
    }
    WriteToFile(t);
    return t;
}

void LoginUser(user* h)
{
    char username[100];
    char password[100];
    char pwd[10];
    char ch;
    int i;
    fflush(stdin);
    printf("\n\n");
    printf("\t\tEnter Email/Username:\n\t\t");
    scanf("%s",username);
    fflush(stdin);
    printf("\n\t\tEnter Password:\n\t\t");
     for(i=0;i<10;i++)
 {
     ch=getch();
     pwd[i]=ch;
     if(ch!=13)
        printf("*");
     if(ch==13)

        break;
 }
 pwd[i]='\0';
 strcpy(password,pwd);
    while(h!=NULL)
    {
        if((!strcmp(h->username,username)) && (!strcmp(h->password,password)))
        {
            currentstate=loggedin;
            strcpy(currentuser,username);

            printf("\n\t\tLogin successful!\n");
            system("PAUSE");
            return;
        }
        else if((!strcmp(h->username,username)) && (strcmp(h->password,password)))
        {
            printf("Password mismatch\n");
            return;
        }
        h=h->next;
    }
    printf("Sorry, no such user record was found\n");
}

void BookTicket(user *h)
{
    user *t=h;
    char place[100];
    while(h!=NULL)
    {
        if(!strcmp(h->username,currentuser))
            break;
        h=h->next;
    }
    if(h==NULL)
        return;
    if(h->numtick!=0)
    {
        printf("You must cancel your previous ticket before buying a new one\n");
        return;
    }
    ShowBrochure();
    int p;
    int pricelist[]={40000,60000,25000,38000,120000,10000,210000,32000,45000,180000};
    char pl[100][100]={"Jammu & Kashmir","Grand Canyon","Sri Lanka","Miami","AND- Hawaii","Goa","Australia & New Zealand","Alaska","Odisha & Kolkata","Switzerland"};
    fflush(stdin);

    printf("\nEnter place code (eg: 11, 14)\n");
     fflush(stdin);
    scanf("%d",&p);
    if(p==11)
    strcpy(place,pl[0]);
    else if(p==14)
    strcpy(place,pl[1]);
    else if(p==16)
    strcpy(place,pl[2]);
    else if(p==19)
    strcpy(place,pl[3]);
    else if(p==21)
    strcpy(place,pl[4]);
    else if(p==24)
    strcpy(place,pl[5]);
    else if(p==26)
    strcpy(place,pl[6]);
    else if(p==29)
    strcpy(place,pl[7]);
    else if(p==31)
    strcpy(place,pl[8]);
    else if(p==34)
    strcpy(place,pl[9]);
    else
    {
      printf("\n!Please enter valid code");
      return;
    }
    char choice;
    fflush(stdin);
    printf("\nWould You Like to Confirm Booking?\n[1] - Yes\n[2] - No\n");
    scanf("%c",&choice);
    int price;
    if(choice!='1')
        return;
    if(strcmp(place,"Jammu & Kashmir")==0)
        price=pricelist[0];
    else if(strcmp(place,"Grand Canyon")==0)
        price=pricelist[1];
    else if(strcmp(place,"Sri Lanka")==0)
        price=pricelist[2];
    else if(strcmp(place,"Miami")==0)
        price=pricelist[3];
    else if(strcmp(place,"Hawaii")==0)
        price=pricelist[4];
    else if(strcmp(place,"Goa")==0)
        price=pricelist[5];
    else if(strcmp(place,"Australia & New Zealand")==0)

        price=pricelist[6];
    else if(strcmp(place,"Alaska")==0)
        price=pricelist[7];
    else if(strcmp(place,"Odisha & Kolkata")==0)
        price=pricelist[8];
    else if(strcmp(place,"Switzerland")==0)
        price=pricelist[9];
    else
    {
        printf("That tour code doesn't exist\n");
        return;
    }
    printf("Enter the number of tickets you want to book?\n");
    scanf("%d",&h->numtick);
    if(h->numtick==0)
        return;
    strcpy(h->place,place);
    h->price=price;
    WriteToFile(t);
    printf("Bookings Done!!\n");
    system("PAUSE");

}
void ownpack(user* h)
{
    int k;
    user *t=h;
    int pricelist[]={20000};
    int numtick;
    int price;
    char place[100];
    while(h!=NULL)
    {
        if(!strcmp(h->username,currentuser))
            break;
        h=h->next;
    }
    if(h==NULL)
        return;
    if(h->numtick!=0)
    {
        printf("You must cancel your previous ticket before buying a new one\n");
        return;
    }
    printf("How many places you are planning to visit[*max.6]?");
    printf("\n\nYour Response: ");
    fflush(stdin);
    scanf("%d",&k);

    if(k<7)
       {
    printf("\nEnter Places want to visit: ");
    fflush(stdin);
    gets(place);
    printf("\nWould You Like to Confirm Booking?\n[1] - Yes\n[2] - No\n");
    char choice;
    fflush(stdin);
    scanf("%c",&choice);
    if(choice=='1')
    {
    printf("Enter the number of tickets you want to book?\n");
    scanf("%d",&numtick);
    price=(pricelist[0]*numtick*k);
    strcpy(h->place,place);
    h->numtick=numtick;
    h->price=price;
    WriteToFile(t);
    printf("\nBookings Done Successfully!!\n");
    printf("\nYou Trip cost will be Rs.%d/-.\n",price);
    printf("\nEnjoy Your Trip :)\n\n");
    system("PAUSE");
    }
       }
       else
       {
           printf("\nPlaces Restricted Error");
       }
}
void PrintTicket(user *h)
{
    while(h!=NULL)
    {
        if(!strcmp(h->username,currentuser))
            break;
        h=h->next;
    }
    if(!strcmp(h->place,"\0") || h->numtick==0)
    {
        printf("You do not have a ticket booked yet\n");
        return;
    }
    int total=0.0;
    total=(h->numtick);
    FILE *fp;
    char filename[50];
    strcpy(filename,h->username);
    strcat(filename,"_ticket.txt");

    fp=fopen(filename,"w");
    if(fp==NULL)
    {
        printf("Problem opening the file...\n");
        return;
    }
    else
    {
        printf("Your Ticket Saved Successfully.\n");
    }
    if(fgetc(fp)==EOF)
    {
        fprintf(fp,"TOURISM TICKET\n===============\n\n");
    }
    fprintf(fp,"Email ID: %s\nTour Code: %s\nTicket Cost: Rs %d\nNumber of tickets: %d\nTotal Cost: Rs %d\n",h->username,h->place,h->price,h->numtick,total);
    fclose(fp);
}
void CancelTicket(user *h)
{
    user *t=h;
    while(h!=NULL)
    {
        if(!strcmp(h->username,currentuser))
            break;
        h=h->next;
    }

    int flag=-1;

    if(h==NULL)
        printf("No such user\n");
    if(strcmp(h->place,"Jammu & Kashmir")==0)
        flag++;
    else if(h->place!=NULL)
    flag++;
    else if(strcmp(h->place,"Grand Canyon")==0)
        flag++;
    else if(strcmp(h->place,"Sri Lanka")==0)
        flag++;
    else if(strcmp(h->place,"Miami")==0)
        flag++;
    else if(strcmp(h->place,"Hawaii")==0)
        flag++;
    else if(strcmp(h->place,"Goa")==0)
        flag++;
    else if(strcmp(h->place,"Australia & New Zealand")==0)
        flag++;
    else if(strcmp(h->place,"Alaska")==0)
        flag++;
    else if(strcmp(h->place,"Odisha & Kolkata")==0)
        flag++;

    else if(strcmp(h->place,"Switzerland")==0)
        flag++;
    else
    {
        printf("You haven't booked a tour yet\n");
        return;
    }
    if(flag==0)
    {
        printf("Your ticket has been successfully cancelled\nA refund of Rs %d for Tour Code %s for %d tickets will soon be made to your original source of purchase\n",h->price,h->place,h->numtick);
        strcpy(h->place,"N/A");
        h->price=0.0;
        h->numtick=0;
        WriteToFile(t);
    }
}

void ChangePassword(user *h)
{
    user *t=h;
    char ch;
    int i;
    char pwd[10];
    fflush(stdin);
    printf("Enter your current password to continue: ");
    for(i=0;i<10;i++)
 {
     ch=getch();
     pwd[i]=ch;
     if(ch!=13)
        printf("*");
     if(ch==13)
        break;
 }
 pwd[i]='\0';;
    while(h!=NULL)
    {
        if(!strcmp(h->username,currentuser))
            break;
        h=h->next;
    }
    if(h==NULL)
    {
        return;
    }
    if(strcmp(pwd,h->password))
    {
    printf("\n\n!Wrong currrent password\nPlease enter correct one\n\n");
    return;
    }
    if(!strcmp(pwd,h->password))
    {
        printf("\n\nEnter new password: ");
        for(i=0;i<10;i++)
    {
     ch=getch();
     pwd[i]=ch;
     if(ch!=13)
        printf("*");
     if(ch==13)
        break;
 }
 pwd[i]='\0';;
        strcpy(h->password,pwd);
        printf("\n\nPassword Updated Successfully\n");
    }
    WriteToFile(t);
}

void LogoutUser()
{
    if(currentstate==menu || strcmp(currentuser,"\0")==0)
    {
        printf("You must be logged in to logout\n");
        return;
    }
    strcpy(currentuser,"\0");
    currentstate=menu;
    printf("You have been successfully logged out\n");
}

void ExitProgram()
{
    printf("Exiting...\nThanks for visiting our application\n\nPress enter to exit");
    char exitprog;
    fflush(stdin);
    scanf("%c",&exitprog);
}

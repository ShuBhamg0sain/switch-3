/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<stdio.h>
#include<conio.h>
 
struct node
{
    int data;
    struct node *next;
    struct node *link;
}*start=NULL,*q,*t;
 
void main()
{
    int ch;
    void create();
    void ser();
    void insert_beg();
    void insert_end();
    void display();
    void delete_beg();
    void delete_end();
    void create(int);
    void ser(int);

int n,i,m,a,pos;
clrscr();
start=NULL;
 
    while(1)
    {
        printf("\n\n *****MAIN MENU *****");
        printf("\n 1: Create a list");
        printf("\n 2: insert at front");
        printf("\n 3: insert at end");
        printf("\n 4: insert before a node");
        printf("\n 5: insert after a node");
        printf("\n 6: delete at front");
        printf("\n 7: delete at end");
        printf("\n 8: delete before a node");
        printf("\n 9: delete after a node");
        printf("\n 10: search");
        printf("\n 11: Display");
        printf("\n 12: EXIT");
        printf("Enter your choice(1-12):");
        scanf("%d",&ch);
 
        switch(ch)
        {
 
            case 1: 
                  printf(“\n\nHOW MANY NODES U WANT TO CREATE\n”);
                  scanf(“%d”,&n);
                  for(i=0;i<n;i++)
                  {
                  printf(“\nENTER THE DATA”);
                  scanf(“%d”,&m);
                  create(m);
                  }
                    break;
            case 2: insert_beg();
                    break;
            case 3: insert_end();
                    break;
          //  case 4: insert_pos();
             //       break;
            case 5: display();
                    break;
            case 6: delete_beg();
                    break;
            case 7: delete_end();
                    break;
          //  case 8: delete_pos();
            //        break;
            case 9: delete_end();
                    break;
            case 10: 
                     printf(“\nENTER THE ELEMENT FOR SEARCH”);
                     scanf(“%d”,&m);
                     ser(m);
                     break;
            case 11: delete_beg();
                     break;
            case 12: exit(0);
                     break;
                     default: printf("Wrong Choice!!");
        }
    }
}
 
void insert_beg()
{
    int num;
    t=(struct node*)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",&num);
    t->data=num;
 
    if(start==NULL)        //If list is empty
    {
        t->next=NULL;
        start=t;
    }
    else
    {
        t->next=start;
        start=t;
    }
}
 
void insert_end()
{
    int num;
    t=(struct node*)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",&num);
    t->data=num;
    t->next=NULL;
 
    if(start==NULL)        //If list is empty
    {
        start=t;
    }
    else
    {
        q=start;
        while(q->next!=NULL)
        q=q->next;
        q->next=t;
    }
}
void display()
{
    if(start==NULL)
    {
        printf("List is empty!!");
    }
    else
    {
        q=start;
        printf("The linked list is:\n");
        while(q!=NULL)
        {
            printf("%d->",q->data);
            q=q->next;
        }
    }
}
 
void delete_beg()
{
    if(start==NULL)
    {
        printf("The list is empty!!");
    }
    else
    {
        q=start;
        start=start->next;
        printf("Deleted element is %d",q->data);
        free(q);
    }
}
 
void delete_end()
{
    if(start==NULL)
    {
        printf("The list is empty!!");
    }
    else
    {
        q=start;
        while(q->next->next!=NULL)
        q=q->next;
 
        t=q->next;
        q->next=NULL;
        printf("Deleted element is %d",t->data);
        free(t);
    }
}
void create(int data)
{
struct node *q,*tmp;
tmp=(struct node *)malloc(sizeof(struct node));
tmp->data=data;
tmp->link=NULL;
if(start==NULL)
{
start=tmp;
}
else
{
q=start;
while(q->link!=NULL)
q=q->link;
q->link=tmp;
}
}
void ser(int data)
{
struct node *q,*tmp;
q=start;
while(q!=NULL)
{
if(q->data==data)
{
printf(“\nElement Is Found”);
break;
}
else
{
q=q->link;
}
}
if(q==NULL)
{
printf(“\nElement is Not Found”);
}
}

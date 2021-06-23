#include<stdio.h>
#include<conio.h>
 
struct node
{
    int data;
    struct node *next;
}*start=NULL,*q,*t;
 
int main()
{
    node *head=NULL;
    int value, number;
    int ch;
    void insert_beg();
    void insert_end();
    void display();
    void delete_beg();
    void delete_end();
    struct node *create_ll(struct node *);
    void search_item(int value);

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
            case 1: start = create_ll(start);
                    break;
            case 2: insert_beg();
                    break;
            case 3: insert_end();
                    break;
          //  case 4: 
          //          break;
          //  case 5: 
          //          break;
            case 6: delete_beg();
                    break;
            case 7: delete_end();
                    break;
         //   case 8: 
         //           break;
         //   case 9: 
         //           break;
            case 10: 
                      printf("\nEnter an item to search it from List\n");
                      scanf("%d", &value);
                      search_ll(value);
                    break;
            case 11: display();
                     break;
            case 12: exit(0);
                     break;
                     default: printf("Wrong Choice!!");
      }
    }
 return 0;
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

struct node *create_ll(struct node *start)
{
struct node *new_node, *ptr;
int val;
 printf("enter the new value");
 scanf("%d",&val);
 new_node=(struct node *) malloc(sizeof(struct node));
 new_node->data=val;
 new_node->next=NULL;
 ptr=start;

 if(start==NULL)
 {
 start=new_node;
 }
else
 {
   while(ptr->next!=NULL)   
    {
      ptr=ptr->next;
    }
  ptr->next=new_node;
   }
 return start;
}

void search_item(int value)
{
    node *searchNode = head;
    int flag = 0;

    while(searchNode!=NULL)
    {
        if(searchNode->number==value)
        {
            printf("%d is present in this list. Memory address is %d\n", value, searchNode);
            flag = 1;
            break;
        }
        else
            searchNode = searchNode->next;
    }

    if(flag==0)
        printf("Item not found\n");

}
















/*
struct node *search_ll(struct node *start)
{ 
    int val;
    printf("\nEnter an item to search it from List\n");
    scanf("%d", &val);
    search_ll(val);                     
    node *searchval = start;
    int flag = 0;

    while(searchval!=NULL)
    {
        if(searchval->data==val)
        {
            printf("%d is present in this list. Memory address is %d\n", val, searchval);
            flag = 1;
            break;
        }
        else
            searchval = searchval->next;
    }

    if(flag==0)
        printf("Item not found\n");

}*/

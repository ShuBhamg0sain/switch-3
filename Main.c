#include<stdio.h>
#include<conio.h>
#include<process.h>
 
struct node
{
    int data;
    struct node *next;
}*start=NULL,*q,*t;
 
int main()
{
    int ch;
    void insert_beg();
    void insert_end();
    int insert_pos();
    void display();
    void delete_beg();
    void delete_end();
    int delete_pos();
 
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
                    break;

            case 2: insert_beg();
                    break;
 
            case 3: insert_end();
                    break;

            case 4: insert_end(start);
                    break;

            case 5: insert_before(start);
                    break;

            case 6: start = insert_after(start);
                    break;

            case 7: start = delete_beg(start);
                    break;

            case 8: start = delete_end(start);
                    break;

            case 9: start = delete_node(start);
                    break;

            case 10: start = delete_after(start);
                     break;

            case 11: start = delete_list(start);
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
 
int insert_pos()
{
    int pos,i,num;
    if(start==NULL)
    {
        printf("List is empty!!");
        return 0;
    }
 
    t=(struct node*)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",&num);
    printf("Enter position to insert:");
    scanf("%d",&pos);
    t->data=num;
 
    q=start;
    for(i=1;i<pos-1;i++)
    {
        if(q->next==NULL)
        {
            printf("There are less elements!!");
            return 0;
        }
 
        q=q->next;
    }
 
    t->next=q->next;
    q->next=t;
    return 0;
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



































 
int delete_pos()
{
    int pos,i;
 
    if(start==NULL)
    {
        printf("List is empty!!");
        return 0;
    }
 
    printf("Enter position to delete:");
    scanf("%d",&pos);
 
    q=start;
    for(i=1;i<pos-1;i++)
    {
        if(q->next==NULL)
        {
            printf("There are less elements!!");
            return 0;
        }
        q=q->next;
    }
 
    t=q->next;
    q->next=t->next;
    printf("Deleted element is %d",t->data);
    free(t);
 
    return 0;
}

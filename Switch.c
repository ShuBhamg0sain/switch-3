
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
struct node
{
int data;
struct node *next;
};
struct node *start = NULL;
struct node *create_ll(struct node *);
struct node *display(struct node *);
/*struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_before(struct node *);
struct node *insert_after(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_node(struct node *);
struct node *delete_after(struct node *);
struct node *search(struct node *);*/

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

struct node *display(struct node *start)
{
 struct node *ptr;
 ptr=start;
 printf("Displaying the linked list");
 while(ptr!=NULL)
 {
 ptr=ptr->next;
 printf("%d",ptr->data);
 }
 return start;
}

int main(int argc, char *argv[]) {
int option;
do
{
printf("\n\n *****MAIN MENU *****");
printf("\n 1: Create a list");
printf("\n 2: Display the list");
printf("\n 3: Add a node at the beginning");
printf("\n 4: Add a node at the end");
printf("\n 5: Add a node before a given node");
printf("\n 6: Add a node after a given node");
printf("\n 7: Delete a node from the beginning");

printf("\n 8: Delete a node from the end");
printf("\n 9: Delete a given node");
printf("\n 10: Delete a node after a given node");
printf("\n 11: Delete the entire list");
printf("\n 12: Sort the list");
printf("\n 13: EXIT");
printf("\n\n Enter your option : ");
scanf("%d", &option);
switch(option)
{
case 1:
      start = create_ll(start);
      printf("\n LINKED LIST CREATED");
break;
case 2:
      start = display(start);
      printf("in case 2");
break;
case 3: 
      start = insert_beg(start);
break;
case 4:
      start = insert_end(start);
break;
case 5:
      start = insert_before(start);
break;
case 6: 
      start = insert_after(start);
break;
case 7: 
      start = delete_beg(start);
break;
case 8:
      start = delete_end(start);
break;
case 9: 
      start = delete_node(start);
break;
case 10: 
       start = delete_after(start);
break;
case 11:
       start = delete_list(start);
       printf(“\n LINKED LIST DELETED”);
break;
case 12: 
       start = sort_list(start);
break;
}
}while(option !=13);
getch();
return 0;
}

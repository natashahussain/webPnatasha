#include<stdlib.h>
struct node
{
 struct node*left;
 int data;
 struct node*right;
};
struct node*head=NULL;
struct node*Getnode();
void insertf();
void insertl();
void display();
void search();
void insertpos();
void deletf();
void deletl();
void deletpos();
void main()
{
  int op=0;
  while(op!=9)
  {
  printf("\n MENU\n 1.INSERT FRISRT \N 2.INSERT LAST \N 3.INSERT POSITION \N 4.DELETE AT POSITION \N 5.DELET LAST \N 6.DELET POSITION \N \n 7.DISPLAY \N 8.SEARCH \n 9.EXIT \n 10.ENTER UR CHOICE \n");
  scanf("%d",&op);
  switch(op)
  {
   case 1:insertf();
	break;
  case 2:insertl();
  break;
  case 3:insertpos();
  break;
  case 4:deletl();
  break;
  case 5:deletpos();
  break;
  case 6:deletf();
  break;
  case 7:search();
       break;
  case 8:display();
       break;
       }
       }
  printf("OVER");
  getch();
}
void display()
  {
   struct node *ptr=head;
  if(head==NULL)
 {
 printf("\n list is empty");
 return;
 }
   printf("The elements are \n");
   while(ptr!=NULL)
  {
  printf("%d \t",ptr->data);
  ptr=ptr->right;
  }
 }
 struct node*Getnode()
 {
  int x;
  struct node *ne=(struct node*)malloc(sizeof(struct node));
  if(ne==NULL)
  printf("insufficient memory \n");
  else
  {
   printf("enter the value to insert");
   scanf("%d",x);
   ne->left=NULL;
   ne->right=NULL;
   ne->data=x;
   }
 return ne;
}
void insertf()
{
  struct node*ne;
  ne=Getnode();
  if(ne==NULL)
  return;
  if(head==NULL)
  head=ne;
  else
  {
  head->left=ne;
   ne->right=head;
   head=ne;
   }
   display();
   }
   void insertl()
{
  struct node*ne,*ptr;
  ne=Getnode();
  if(ne==NULL)
  return;
  if(head==NULL)
  head=ne;
  else
  {
  ptr=head;
  while(ptr->right!=NULL)
  {
  ptr=ptr->right;
  }
  ptr->right=ne;
  ne->left=ptr;
   }
   display();
   }
	void insertpos()
{
 int value;
  struct node*ne,*ptr,*ptr1;
  ne=GetNode();
  if(ne==NULL)
  return;
  if(head==NULL)
  {
  printf("list empty");
  head=ne;
  return;
  }
  printf("enter the key");
  scanf("%d",&value);
  ptr=head;
  while(ptr->right!=NULL&&ptr->data!=value)
  {
  ptr=ptr->right;
  }
  if(ptr->right==NULL)
  {
  ptr->right=ne;
  ne->left=ptr;
   printf("\n node is inerted");
   }
   else
   {
   ptr1=ptr->right;
  ne->left=ptr1;
  ne->left=ptr;
  ptr->right=ne;
  ptr1->left=ne;
  }
  printf("element is inserte \n");
   display();
   }
    void deletf()
{
  struct node*ptr;
  if(head==NULL)
  {
  printf("empty!!!");
  return;
  }
  ptr=head ;
  head=head->right;
   if(head!=NULL)
   head->left=NULL;
 free(ptr);
   display();
   }
    void deletl()
{
  struct node *prev,*ptr;
  if(head==NULL)
   {
  printf("empty!!!");
  return;
  }
  if(head->right==NULL)
  {
  free(head);
  head=NULL;
  }
  ptr=head->right;
  while(ptr->right!=NULL)
  {
  prev=ptr->left;
  prev->right=NULL;
  free(ptr);
   display();
   }
   }
 void deletpos()
  {
   struct node *ptr,*prev,*next;
   int x;
   if(head==NULL)
    {
     printf("list empty");
     return;
    }
  printf("enter the element");
  scanf("%d",&x);
  if(head->data==x)
  {
    ptr=head;
    head=ptr->right;
    if(head!=NULL)
  {
  head->left=NULL ;
  }
  free(ptr);
  return;
  }
  ptr=head;
   while(ptr->data!=x&&ptr->right!=NULL)
  {
  ptr=ptr->right;
  }
  if(ptr->data==x)
  {
  next=ptr->right;
  prev=ptr->left;
  prev->right=ptr->right;
  if(next!=NULL)
  next->left=ptr->left;
  free(ptr);
  return;
  }
  printf("element is not in the list");
    }
    void search()
{
  struct node *ptr;
  int x;
  if(head==NULL)
  {
  printf("empty!!!!!!!") ;
  return;
  }
  printf("\n element to be searched");
  scanf("%d",&x);
  ptr=head;
  while(ptr!=NULL);
  {
  if(ptr->data==x)
  {
  printf("\n element is present");
  }
   ptr=ptr->right;
   }
   if(ptr==NULL)
   printf("\n element is not present");

   }

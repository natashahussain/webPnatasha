#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node*left;
 struct node*right;
};
struct node *root=NULL;
void insert();
void delet(int);
void inorder( struct node*);
void preorder( struct node*);
void postorder( struct node*);
void search();
void main()
{
 int op,x;
 do
 {
  printf("\n MENU\n 1.INSERT  \n 2.DELETE  \n 3.INORDER \n 4.PREORDER \N 5.POSTORDER \n 6.SEARCH \n 7.EXIT \n 10.ENTER UR CHOICE \n");
  scanf("%d",&op);
  switch(op)
  {
  case 1:insert();
	break;
  case 2:printf("\n enter the data to delete");
	scanf("%d",&x);
	delet(x);
	break;
  case 3:inorder(root);
	 break;
  case 4:preorder(root);
	 break;
  case 5:postorder(root);
	 break;
  case 6:search();
	 break;
  default:printf("wrong choice");
       }
       }
       while(op!=7);
}
 void insert()
 {
  struct node*ptr,*ne,*ptr1;
  int x;
  ne=(struct node*)malloc(sizeof(struct node));
  if(ne==NULL)
  {
   printf("insufficient memory");
   return;
   }
   printf("enter the data to be inserted");
   scanf("%d",&x);
   ne->right=ne->left=NULL;
   ne->data=x;
   if(root==NULL)
   {
    root=ne;
    return;
   }
   ptr=root;
   while(ptr!=NULL)
   {
    if(x==ptr->data)
    {
     printf("\n item is found");
     break;
    }
    if(x>ptr->data)
    {
     ptr1=ptr;
     ptr=ptr->right;
    }
    else
    {
    ptr1=ptr;
    ptr=ptr->left;
    }
    }
    if(ptr==NULL)
    {
     if(x>ptr1->data)
     ptr1->right=ne;
     else
     ptr1->left=ne;
     }
     }
     void search()
     {
     int x;
     struct node *ptr=root;
     printf("enter the data to be searche \n");
     scanf("%d",&x);
      while(ptr!=NULL)
   {
    if(x==ptr->data)
    {
     printf("\n item is found");
     break;
    }
    if(x>ptr->data)
     ptr=ptr->right;
    else
    ptr=ptr->left;
    }
    if(ptr==NULL)
    printf("\n DATA NOT PRESENT");
     }
     void inorder(struct node*p)
     {
     if(p!=NULL)
     {
       inorder(p->left);
       printf("%d",p->data);
       inorder(p->right);
       }
       }
	void preorder(struct node*p)
     {
     if(p!=NULL)
     {
       printf("%d",p->data);
       preorder(p->left);
       preorder(p->right);
       }
       }
	void postorder(struct node*p)
     {
     if(p!=NULL)
     {

       postorder(p->left);
       postorder(p->right);
	 printf("%d",p->data);
       }
       }
       void delet(int x)
       {
	struct node *p,*parent, *ptr;
	int dat;
	if(root==NULL)
	{
	printf("\n tree is empty");
	return;
	}
  parent=NULL;
  ptr=root;
   while(ptr!=NULL)
   {
    if(ptr->data==x)
     break;
     parent=ptr;
    if(x>ptr->data)
     ptr=ptr->right;
    else
    ptr=ptr->left;
    }
    if(ptr==NULL)
    {
    printf("\n Item is not present");
    return;
    }
    if(ptr->right==NULL && ptr->left==NULL )
    {
    if(parent==NULL)
    root=NULL;

     else if
     (parent->right==ptr)
     if( parent->right==NULL)
      {
      printf("elements are not deleted");
      }
      else
      {
      parent->left=NULL;
      }
      free(ptr);
      return;
     }
      if(ptr->right!=NULL && ptr->left!=NULL )
      {
      p=ptr->right;
      while(p->left!=NULL)
      {
      p=p->left;
     }
     dat=p->data;
     delet(p->data);
     ptr->data=dat;
     return;
     }
     if(parent==NULL)
     {
     if( ptr->right==NULL)
     root=ptr->left;
     else
      root=ptr->right;
      }
      else
      {
      if( parent->right==ptr )
      {
     if(ptr->right==NULL)
     {
     parent->right=ptr->left;
     }
     else
     {
     parent->right=ptr->right;
      }

     if(ptr->left==NULL)
     {
     parent->right=ptr->left;
     }
     else
     {
     parent->right=ptr->right;
      }
     }
     if(ptr->left==NULL)
     {
     printf("the elemen is not deleted");
     parent->left=ptr->right ;
     }
     else
     {
    parent->left=ptr->left;
      }
      printf("\n element is deleted");
      free(ptr);
      return;
}}

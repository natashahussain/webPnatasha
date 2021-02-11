#include<stdio.h>
#include<stdlib.h>
struct node
{
 struct setObject*top;
 int data;
 struct node*next;
};
 struct setObject
 {
   struct node*head;
   struct node*tail;
 };
   struct node*nodel[20];
   int n;
   void display()
   {
     int i,j,count=0,flag=0;
     struct node *p1;
     struct setObject*ptr,*p[20];
     for(i=0;i<n;i++)
     {
     ptr=nodel[i]->top;
     flag=0;
     for(j=0;j<count;j++)
     {
	 if(p[j]==ptr)
	 {
	   flag=1;
	   break;
	 }
	 }
	 if(flag==0)
	 {
	   printf("{");
	   p1=ptr->head;
	   while(p1!=NULL)
	   {
	     printf("%d",p1->data);
	     p1=p1->next;
	   }
	   printf("} \n");
	   p[count++]=ptr;
	   }
	 }
       }
       struct setObject*find(int x)
       {
	 int i,flag=0;
	 for(i=0;i<n;i++)
	 {
	  if(nodel[i]->data==x)
	  {
	   flag=1;
	   break;
	  }
	 }
	 if(flag==1)
	 return nodel[i]->top;
	 else
	 return NULL;
       }

       void unions()
       {
       struct node*ptr;
       struct setObject*ptrx,*ptry;
       int x,y,i;
       printf("enter the elemnet to join  ");
       scanf("%d,%d",&x,&y);
       ptrx=find(x);
       ptry=find(y);
       if(ptrx!=ptry)
       {
	 ptrx->tail->next=ptry->head;
	 ptrx->tail=ptry->tail;
	 ptr=ptry->head;
	 while(ptr!=NULL)
	 {
	   ptr->top=ptrx;
	   ptr=ptr->next;
	 }
	 free(ptry);
	 }
	 }
	 void main()
	 {
	 int i,o,x;
	 struct node*ne;
	 struct setObject*p;
	 printf("enter the number of elements");
	 scanf("%d",&n);
	 printf("\n enter the elements");
	 for(i=0;i<n;i++)
	 {
	   ne=(struct node*)malloc(sizeof(struct node));
	   scanf("%d",&ne->data);
	   ne->next=NULL;
	   nodel[i]=ne;
	   p=(struct setObject*)malloc(sizeof(struct setObject));
	   p->head=ne;
	   p->tail=ne;
	   ne->top=p;
	   }
	   while(o!=4)
	 {
	 printf("\n MENU \n 1.UNION\N 2.find \n 3.DISPLAY \N 4.EXIT \N enter your choice:");
	   scanf("%d",&o);
	   switch(o)
	   {
	    case 1:unions();
		  break;
	    case 2:printf("element to be find");
		    scanf("%d",&x);
		    p=find(x);
		    if(p!=NULL)
		    printf("\n  rep:of the set is %d",p->head->data);
		    else
		    printf("\n element is not found!!!!");
		    break;
	    case 3:display();
		   break;
		   }
		   getch();
		   }
}
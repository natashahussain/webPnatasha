#include<conio.h>
#include<stdio.h>
int size=3;
int front=-1,rear=-1;
void insert(int *q)
{
  if(front==(rear+1)%size)
  {
    printf("queue is full");
    return;
  }
  if(front==-1)
  front=0;
  rear=(rear+1)%size;
  printf("insert th element");
  scanf("%d",&q[rear]);
}
void delte(int *q)
{
  if(front==-1)
  {
    printf("queue is empty \n");
    return;
  }
  printf("dleted elment %d",q[front]);
  if(front==rear)
  front=rear-1;
  else
  front=(front+1)%size;
  return;
}
void search(int *q)
{
  int x,f,pos,sz[3];
  if(front==-1)
  {
    printf("q is empty");
    return;
  }
  printf("enter the element to be searched\n ");
  scanf("%d",&x);
  f=front;
  pos=1;
  while(1)
  {
    if(q[f]==x)
    {
    printf("elment  is found at location %d",pos);
    break;
    }
    if(f==rear)
    {
    printf("elment not found");
    break;
    }
    //f=(f+1)%sz;
    pos=pos+1;
    }
}

void display(int *q)
{
  int f,sz[3];
  if(front==-1)
  {
  printf("q is empty");
  return;
  }
  f=front;
  while(1)
  {
  printf("%d",q[f]);
  if(f==rear)
  break;
 // f=(f+1)%sz;
  }
  }
void main()
{
int q[3];
int op;
clrscr();
while(1)
 {
  printf("options \n ");
  printf("1:INSERT \n 2:DELETE \n 3:SEARCH \n 4.DISPLAY \n 5.EXIT \N ENTER option \n");
  scanf("%d",&op);
  switch(op)
  {
    case 1:insert(q);
	   break;
  case 2:delte(q);
       break;
  case 3:search(q);
     break;
  case 4:display(q);
	 break;
  case 5:printf("over");
	 exit();
  default:printf("wrong choice" );
  }
  }
  }
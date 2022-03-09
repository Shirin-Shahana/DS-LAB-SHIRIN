#include<stdio.h>
void insert(int *);
void del(int *);
void disp(int *);
void search(int *);
int front=-1,rear=-1;
int size=4;
void main()
{
int q[20],opt;
do {
	printf("\n 1. Insert \n 2.Delete \n 3. Search \n 4. display \n 5. Exit \n Enter your choice");
	scanf("%d",&opt);
	switch(opt)
	{
		case 1:
			insert(q);
			break;
		case 2:
			del(q);
			break;
		case 3:
			search(q);
			break;
		
		case 4:
			disp(q);
			break;
		
			
		
	}
   }
while(opt<5);

}
void insert(int *q)
{
	if(front==(rear+1)%size)
	{
		printf("Queue is full");
	return;
	}
	if(front==-1)
		front=0;
	rear=(rear+1)%size;
	printf("Element to be inserted");
	scanf("%d",&q[rear]);

}
void del(int *q)
{
	if(front==-1)
	{printf("Queue is empty");
	return;
	}
	printf("Deleted element is %d",q[front]);
	if(front==rear)
		front=rear=-1;
	else
		front=(front+1)%size;
}
void disp(int *q)
{
	int f;
	if(front==-1)
	{
	printf("Queue is empty");
	return;}
	f=front;
	while(1)
	{
	printf("%d",q[f]);
	if(f==rear)
		break;
	f=(f+1)%size;
	}
}
void search(int *q)
{
	int f,item,c;
	printf("item to be search");
	scanf("%d",&item);
	if(front==-1)
	{
	printf("Queue is empty");
	return;}
	f=front;
	while(1)
	{
	if(f==item){
	
	printf("item %d is found",item);break;}
	if(f==rear)
	{printf("item not found");
	break;
	}
	f=(f+1)%size;
	}
}


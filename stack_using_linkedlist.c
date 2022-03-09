#include<stdio.h>
#include<stdlib.h>
struct Node *Top=NULL;
void push();
void display();
void pop();
void search();
struct Node
{
	int data;
	struct Node *next;
};
void main()
{
int q[20],opt;
do {
	printf("\n 1. push \n 2.pop \n 3. Search \n 4. display \n 5. Exit \n Enter your choice");
	scanf("%d",&opt);
	switch(opt)
	{
		case 1:
			push();
			break;
		case 2:
			pop();
			break;
		case 3:
			search();
			break;
		
		case 4:
			display();
			break;
		
			
		
	}
   }
while(opt<5);

}
void push()
{
	int x;
	struct Node *ne;
	printf("Read value");
	scanf("%d",&x);
	ne=(struct Node*)malloc(sizeof(struct Node));
	if(ne==NULL)
	{
		printf("stack overflow");
		return;
	}
	else
	{
		ne->data=x;
		ne->next=Top;
		Top=ne;	
	}

}
void pop()
{
	struct Node *ptr=Top;
	int item;
	if(ptr==NULL)
	{
		printf("stack is empty");
		return;
	}
	else
	{
		item=ptr->data;
		printf("deleted element:%d",item);
		Top=ptr->next;
		
		
	}
}
void search()
{
	int item;
	struct Node *ptr=Top;
	printf("element to be search");
	scanf("%d",&item);
	if(Top==NULL)
	{
		printf("Stack is empty");
		return;
	}
	else
	{
		while(ptr!=NULL)
		{
			if(ptr->data==item)
			{
				printf("item found");
				printf("%d  ",ptr->data);return;
			}
			ptr=ptr->next;
		}
		if(ptr==NULL)
		{
			printf("item not found");
			return;
		}
	}
}
void display()
{
	struct Node *ptr=Top;
	if(Top==NULL)
	{
		printf("Stack is empty");
		return;
	}
	else
	{
		while(ptr!=NULL)
		{
			printf("%d  ",ptr->data);
			ptr=ptr->next;
		}
	}

}

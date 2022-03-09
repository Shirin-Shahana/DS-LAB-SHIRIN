//doubly linked list
#include<stdio.h>
#include<stdlib.h>
void insertf();
void insertl();
void display();
void insertp();
void deletef();
void deletel();
void search();
void deletep();
struct Node
{
	struct Node *left;
	struct Node *right;
	int data;
}*head=NULL;
void main()
{
	int opt;
	do {
	printf("\n 1. insert at front \n 2.insert last \n 3. insert position\n 4. delete front \n 5. delete last \n 6.delete from position \n 7. display \n 8. search \n 9. Exit \n Enter your choice");
	scanf("%d",&opt);
	switch(opt)
	{
		case 1:
			insertf();
			break;
		case 2:
			insertl();
			break;
		case 3:
			insertp();
			break;
		case 4:
			deletef();
			break;
		case 5:
			deletel();
			break;
		case 6:
			deletep();
			break;
		case 7:
			display();
			break;
		case 8:
			search();
			break;
		case 9:
			break;
		default:
			printf("invalid number");
		}
	 }
	while(opt!=9);
	}
	void insertf()
	{
		int item;
		struct Node *ne;
		printf("Enter item");
		scanf("%d",&item);
		ne=(struct Node*)malloc(sizeof(struct Node));
		if(ne==NULL)
		{
			printf("insufficient memory");
			return;
		}
		ne->data=item;
		ne->left=NULL;
		ne->right=NULL;
		if(head==NULL)
		{
			head=ne;
			return;
		}
		ne->right=head;
		head->left=ne;
		head=ne;
	}
	void insertl()
	{
		int item;
		struct Node *ptr,*ne;
		printf("Enter item");
		scanf("%d",&item);
		ne=(struct Node*)malloc(sizeof(struct Node));
		if(ne==NULL)
		{
			printf("insufficient memory");
			return;
		}
		ne->data=item;
		ne->left=NULL;
		ne->right=NULL;
		if(head==NULL)
		{
			head=ne;
			return;
		}
		ptr=head;
		while(ptr->right!=NULL)
		{
			ptr=ptr->right;
		}
		ptr->right=ne;
		ne->left=ptr;
	}
	void display()
	{
		struct Node *ptr;
		ptr=head;
		if(head==NULL)
		{
			printf("list empty");
			return;
		}
		while(ptr!=NULL)
		{
			printf("%d ",ptr->data);
			ptr=ptr->right;
		}
	}
	void insertp()
	{
		int item,key;
		struct Node *ptr,*ne;
		printf("Enter item");
		scanf("%d",&item);
		printf("key value");
		scanf("%d",&key);
		ne=(struct Node*)malloc(sizeof(struct Node));
		if(ne==NULL)
		{
			printf("insufficient memory");
			return;
		}
		ne->data=item;
		ne->left=NULL;
		ne->right=NULL;
		if(head==NULL)
		{
			head=ne;return;
		}
		ptr=head;
		while(ptr->data!=key && ptr->right!=NULL)
		{
			ptr=ptr->right;
		}
		if(ptr->right==NULL)
		{
			ptr->right=ne;
			ne->left=ptr;
		}
		else
		{
			ne->right=ptr->right;
			ptr->right->left=ne;
			ne->left=ptr;
			ptr->right=ne;
			return;
		}
	}
	void deletef()
	{
		struct Node *ptr;
		ptr=head;
		if(head==NULL)
		{
			printf("list is empty");
			return;
		}
		head=head->right;
		if(head!=NULL)
		{
			head->left=NULL;
		}
		free(ptr);
	}
	void deletel()
	{
		struct Node *ptr,*p;
		if(head==NULL)
		{
			printf("list is empty");
			return;
		}
		if(head->right==NULL)
		{
			free(head);
			head=NULL;
			return;
		}
		ptr=head;while(ptr->right!=NULL)
		{
			ptr=ptr->right;
		}
		p=ptr;
		ptr=ptr->left;
		ptr->right=NULL;
		free(p);
	}
	void deletep()
	{
		struct Node *ptr,*next,*prev;
		int key;
		printf("item to be deleted");
		scanf("%d",&key);
		if(head==NULL)
		{
			printf("list is empty");
			return;
		}
		if(head->data==key)
		{
			ptr=head;
			head=ptr->right;
			if(head!=NULL)
			{
				head->left=NULL;
			}
			free(ptr);
			return;
		}
		ptr=head;
		while(ptr->data!=key && ptr->right!=NULL)
		{
			ptr=ptr->right;
		}
		if(ptr->data==key)
		{
			next=ptr->right;
			prev=ptr->left;
			if(next!=NULL)
			{
				prev->right=next;
				next->left=ptr->left;
			}
			else
			{
				prev->right=NULL;
			}
			free(ptr);return;
		}
		else
		{
			printf("Element not found");
			return;
		}
	}
	void search()
	{
		struct Node *ptr;
		int item;
		ptr=head;
		printf("Element to be search");
		scanf("%d",&item);
		if(head==NULL)
		{
			printf("list empty");
			return;
		}
		while(ptr!=NULL)
		{
			if(ptr->data==item)
			{
				printf("%d is found",ptr->data);
				return;
			}
			ptr=ptr->right;
		if(ptr==NULL)
		{
			printf("element not found");
			return;
		}
	}
}
#include<stdio.h>
#include<stdlib.h>

struct Node
{
	struct Node *left;
	struct Node *right;
	int data;
}*root=NULL;
void insertion()
{
	int n;
	struct Node *ne,*ptr,*ptr1;
	ne=(struct Node*)malloc(sizeof(struct Node));
	printf("Enter data");
	scanf("%d",&n);
	if(ne==NULL)
	{
		printf("insufficient memory");
		return;
	}
	ne->right=NULL;
	ne->left=NULL;
	ne->data=n;
	if(root==NULL)
	{
		root=ne;
		//break;
	}
	ptr=root;
	while(ptr!=NULL)
	{
		if(ptr->data==n)
		{
			printf("data is present");
			return;
		}
		else if(ptr->data>n)
		{
			ptr1=ptr;
			ptr=ptr->left;
		}
		else
		{
			ptr1=ptr;
			ptr=ptr->right;
		}
	}
	if(ptr==NULL)
	{
		if(n>ptr1->data)
		{
			ptr1->right=ne;
		}
		else
		{
			ptr1->left=ne;
		}
	}
}

void inorder(struct Node *root)
{
	struct Node *p=root;
	if(p!=NULL)
	{
		inorder(p->left);
		printf("%d  ",p->data);
		inorder(p->right);
	}
	return;
}

void preorder(struct Node *root)
{
	struct Node *p=root;
	if(p!=NULL)
	{
		printf("%d  ",p->data);
		preorder(p->left);
		preorder(p->right);
		
	}
	return;
}

void postorder(struct Node *root)
{
	struct Node *p=root;
	if(p!=NULL)
	{
		
		postorder(p->left);
		postorder(p->right);
		printf("%d  ",p->data);
		
	}
	return;
}

void search(struct Node *root)
{
	int x;
	struct Node *ptr=root;
	printf("Element to be search");
	scanf("%d",&x);
	while(ptr!=NULL)
	{
		if(ptr->data==x)
		{
			printf("Data present");
			break;
		}
		if(x>ptr->data)
		{
			ptr=ptr->right;
		}
		else
		{
			ptr=ptr->left;
		}
	}
	if(ptr==NULL)
			printf("Data is not present");
}

void deletion(struct Node *root,int x)
{
	struct Node *ptr=root,*parent,*p;
	if(root==NULL)
	{
		printf("\n Tree is empty");
		return;
	}
	parent=NULL;
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
		printf("Item not found");
		return;
	}
	//case1
	if(ptr->right==NULL && ptr->left==NULL)
	{
		if(parent==NULL)
				root=NULL;
		else if(parent->right==ptr)
				ptr->right=NULL;
		else
				ptr->left=NULL;
		printf("Element deleted");
		free(ptr);
		return;
	}
	//case3
	int dat;
	if(ptr->right!=NULL && ptr->left!=NULL)
	// find inorder successor
	{
		p=ptr->right;
		while(p->left!=NULL)
				p=p->left;
		dat=p->data;
		deletion(root,p->data);
		ptr->data=dat;
		
		
	}
	//case 2
	if(parent==NULL)
	{
		if(ptr->right==NULL)
				root=ptr->left;
		else
				root=ptr->right;
	}
	else if(parent->right==ptr)
	{
		if(ptr->right==NULL)
				parent->right=ptr->left;
		else
				parent->right=ptr->right;
	}
	else
	if(ptr->left==NULL)
			parent->left=ptr->right;
	else
			parent->left=ptr->left;
	printf("Element deleted");
	free(ptr);
	return;
}

void main()
{
	int opt,x;
do {
	printf("\n 1. insertion \n 2.deletion \n 3. inorder traverse\n 4. preorder traverse \n");
	printf("5. postorder traverse \n 6.search\n 7. Exit \n Enter your choice");
	scanf("%d",&opt);
	switch(opt)
	{
		case 1:
			insertion();
			break;
		case 2:
			printf("Element to be delete");
			scanf("%d",&x);
			deletion(root,x);
			break;
			
		case 3:
			//struct Node *p=root;
			inorder(root);
			break;
		
		case 4:
			preorder(root);
			break;
		case 5:
			postorder(root);
			break;
		case 6:
			search(root);
			break;
		case 7:
			break;
		
		default:
			printf("invalid choice");
		
		
			
		
	}
   }
while(opt!=7);

}
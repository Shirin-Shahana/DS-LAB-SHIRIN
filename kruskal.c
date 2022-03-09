#include<stdio.h>
#include<stdlib.h>


struct edge
{
	int start;
	int end;
	int weight;

} *adj[20];

struct node
{
	int data;
	struct node *next;

} *first[20];

int n=0;
int find(int x)
{
	int flag=0,i;
	struct node* p;
	for(i=0;i<n;i++)
	{
		p=first[i];
		while(p!=NULL)
		{
			if(p->data==x)
			{
				flag=1;
				break;
			}
			p=p->next;
		}
		if(flag==1)
			break;
	}
	if(flag==1)
		return(i);
	else
		return -1;
}


void Union(int x,int y)
{
	int i,j;
	struct node* p;
	i=find(x);
	j=find(y);
	if(i==j)
		printf("Both are in the same set");
	else
		{
			p=first[i];
			while(p->next != NULL)
			{
				p=p->next;
			}
		p->next=first[j];
		first[j]=NULL;
		}
}

void makeset(int i)
{
	int pos;
	pos=find(i);
	if(pos==-1)
	{
		first[n]=(struct node*)malloc (sizeof(struct node));
		first[n]->data=i;
		first[n]->next=NULL;
		n++;
	}
	else
	{
		printf("\n the number exist in another set");
	
	}

}
void main()
{
	int s,en,w,i,k,c,count,e,u,v;
	struct edge A[20],adj[20];
	
	printf("Enter no. of vertices");
	scanf("%d",&v);
	for(i=1;i<=v;i++)
	{
		makeset(i);
	}
	printf("Enter no. of edges");
	scanf("%d",&e);
	printf("start");
	printf("end weight");
	c=-1;
	for(i=1;i<=e;i++)
	{
		scanf("%d%d%d",&s,&en,&w);
		for(k=c;k>=0;k--)
		{
			if(adj[k].weight>w)
				adj[k+1]=adj[k];
			else
				break;
		}
		adj[k+1].start=s;
		adj[k+1].end=en;
		adj[k+1].weight=w;
		c++;
	}
	count=0;
	for(i=0;i<c;i++)
	{
		u=adj[i].start;
		v=adj[i].end;
		if(find(u)!=find(v))
		{
			A[count].start=u;
			A[count].end=v;
			A[count].weight=adj[i].weight;
			count++;
			Union(u,v);
		
		}
	}
	printf("Spanning tree edges");
	int sum=0;
	for(i=0;i<count;i++)
	{
		printf("%d->%d %d \n",A[i].start,A[i].end,A[i].weight);
		sum=sum+A[i].weight;
	}
	printf("weight=%d",sum);

}
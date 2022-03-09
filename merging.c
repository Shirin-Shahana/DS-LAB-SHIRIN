//merging of 2 sorted array
#include<stdio.h>
void main()
{
int i,j,k,a[20],b[20],c[20],m,n;
printf("Enter limit of first array");
scanf("%d",&m);
printf("Enter limit of second array");
scanf("%d",&n);
printf("Enter first sorted array");
for(i=0;i<m;i++)
{	
	scanf("%d",&a[i]);	
}
printf("Enter second sorted array");
for(i=0;i<n;i++)
{	
	scanf("%d",&b[i]);	
}
printf("Merged array is");
//merging
i=0;
j=0;
k=0;
while(i<m && j<n)
{
	if(a[i]<b[j])
	{
		c[k]=a[i];
		i++;
	}
	else if(a[i]>b[j])
	{
		c[k]=b[j];
		j++;
	}
	else
	{
		c[k]=a[i];
		j++; i++;
	}
	k++;
}
while(i<m)
{
	c[k]=a[i];
	k++;
	i++;
}
while(j<n)
{
	c[k]=b[j];
	k++; 
	j++;
}
for(i=0;i<k;i++)
{
	printf("%d \t",c[i]);
}
}

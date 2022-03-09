#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void setunion(char *s1,char *s2,char *s3)
{
	int i,l;
	l=strlen(s1);
	for(i=0;i<l;i++)
	{
		if(s1[i]=='0' && s2[i]=='0')
		{
			s3[i]='0';
		}
		else
		{
			s3[i]='1';
		}
	}
	s3[i]='\0';
}

void setintersection(char *s1,char *s2,char *s3)
{
	int l,i;
	l=strlen(s1);
	for(i=0;i<l;i++)
	{
		if(s1[i]=='1' && s2[i]=='1')
		{
			s3[i]='1';
		}
		else
		{
			s3[i]='0';
		}
	}
	s3[i]='\0';
}


void setdifference(char *s1,char *s2,char *s3)
{
	int i,l;
	l=strlen(s1);
	for(i=0;i<l;i++)
	{
		if(s1[i]=='1' && s2[i]=='0')
		{
			s3[i]='1';
		}
		else
		{
			s3[i]='0';
		}
	}
	s3[i]='\0';
}

void main()
{
	char s1[20],s2[20],s3[20];
	printf("Enter set1:");
	scanf("%s",s1);
	printf("Enter set2:");
	scanf("%s",s2);
	setunion(s1,s2,s3);
	printf("\n Union:\n %s",s3);
	setdifference(s1,s2,s3);
	printf("\n Difference:\n %s",s3);
	setintersection(s1,s2,s3);
	printf("\n Inttersection:\n %s",s3);
	
	
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main(int argc,char *argv[])
{
	if(argc<1)
	{
	printf("File Not Passed\n");
	exit(1);
	}
	char ch;
	printf("Enter the Pattern to Be searched  : ");
	char pat[150],temp[150];scanf("%s",pat);
	FILE *fp = fopen(argv[1],"r");
	while(!feof(fp))
	{
	fgets(temp,100,fp);
	if(strstr(temp,pat))
	printf("Pattern Matched");
	else
	printf("Pattern NOT Matched");
	}
}

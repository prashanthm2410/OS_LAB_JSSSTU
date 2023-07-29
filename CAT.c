#include<stdio.h>
#include<stdlib.h>
void main(int argc,char *argv[])
{
	if(argc<2)
	{
	printf("Not Passing Filename\n");
	exit(1);
	}
	FILE *fp=fopen(argv[1],"r");
	if(fp==NULL)
	{
	printf("File Does Not Exists\n");exit(0);
	}
char ch;
while((ch=fgetc(fp))!=EOF)
printf("%c",ch);
fclose(fp);
}

PARENT.C
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <string.h>
void main()
{
int shmid,*sharedmemory,n;
shmid=shmget((key_t)110011, 1024, 0666|IPC_CREAT);
sharedmemory=shmat(shmid,NULL,0);
printf("Enter a Number : ");scanf("%d",&n);
char str[2];
sprintf(str,"%d",n);
if(fork()==0)
{
execlp("./child", "child",str,NULL);
}
else{
wait(NULL);
printf("\n");
for(int i=0;i<n;i++)
printf("%d\t",sharedmemory[i]);
}
shmdt(sharedmemory);
}
CHILD.C
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <string.h>
void main(int argc,char *argv[])
{
	int shmid, n=atoi(argv[1]);
	int *sharedmemory;char buffer[2];
	shmid=shmget((key_t)110011, 1024, 0666);
	sharedmemory = (int *)shmat(shmid,NULL,0);
	int j=0;
	for (int i = 1; n> 0; i += 2) 
	{
	sharedmemory[j]=i;
        n--;j++;
    }	
}

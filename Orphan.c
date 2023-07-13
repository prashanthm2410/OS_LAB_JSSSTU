#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
    pid_t childpid,mypid,parentpid;
    childpid=fork();
    if(childpid<0)
    {
        printf("Fork Failed\n");
        exit(0);
    }
    if(childpid==0)
    {
        printf("[CHILD] This is the Child Process\n ");
        mypid=getpid();
        parentpid=getppid();
        printf("[CHILD] My ID is %d\n ",mypid);
        printf("[CHILD] My Parent ID is %d\n ",parentpid);
        printf("[Child] Sleeping For 10 Seconds\n");
        sleep(10);
        printf("Parent Ended So Orphan\n");
        exit(0);
    }
    else
    {
        printf("[PARENT] This is the Parent Process \n");
        mypid=getpid();
        parentpid=getppid();
        printf("[PARENT] My ID is %d\n ",mypid);
        printf("[PARENT] My Parent ID is %d\n ",parentpid);
    }
    return 0;
}

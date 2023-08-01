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
        printf("[CHILD] Exiting\n");
        exit(0);
    }
    else
    {
        printf("[PARENT] This is the Parent Process \n");
        mypid=getpid();
        parentpid=getppid();
        printf("[PARENT] My ID is %d\n ",mypid);
        printf("[PARENT] My Parent ID is %d\n ",parentpid);
        printf("[Parent] Sleeping For 10 Seconds");
        sleep(10);
        printf("[PARENT] Child_Pid = %d has Ended  but has Entery in tjhe process Table So Orphan",childpid);
    }
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
struct process
{
    int id,at,bt,ct,wt,tt;
};
float totaltat,totalwt;
typedef struct process process;
void sort(process p[],int n)
{
    process temp;//swap the priocess itself not hjust there arrival times VVP
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(p[j].at>p[j+1].at)
            {
                temp=p[j];
                p[j]=p[j+1];//swap the priocess itself not hjust there arrival times VVP
                p[j+1]=temp;
            }
        }
    }
}
void FCFS(process p[],int n)
{
    int ct;p[0].ct=p[0].at+p[0].bt;ct=p[0].ct;
    p[0].tt=p[0].ct-p[0].at;
        p[0].wt=p[0].tt-p[0].bt;
        totaltat=p[0].tt;totalwt=p[0].wt;
    for(int i=1;i<n;i++)
    {
        if(ct<p[i].at)
        ct=p[i].at;
        ct+=p[i].bt;
        p[i].ct=ct;
        p[i].tt=p[i].ct-p[i].at;
        p[i].wt=p[i].tt-p[i].bt;
        totaltat+=p[i].tt;
        totalwt+=p[i].wt;
    }
}
void main()
{
    printf("Enter the Number of Process : ");int n;scanf("%d",&n);
    process p[n];
    printf("Enter Arrival and Bursty Time of trhe Process\n");
    for(int i=0;i<n;i++)
    {
        printf("Process P%d--------->",i+1);
        p[i].id=i+1;
        scanf("%d%d",&p[i].at,&p[i].bt);
    }
    sort(p,n);
    FCFS(p,n);
    printf("ID\t\tAT\t\tBT\t\tWT\t\tTT\t\tCT\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i].id,p[i].at,p[i].bt,p[i].wt,p[i].tt,p[i].ct);
    }
    printf("Average TAT = %f\n",totaltat/n);
     printf("Average WT = %f\n",totalwt/n);
}

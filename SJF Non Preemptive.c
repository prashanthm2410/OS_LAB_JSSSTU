#include<stdio.h>
#include<stdlib.h>
typedef struct process
{
    int id,at,bt,ct,tat,wt,iscompl;
}Process;
void main()
{
    int completed=0,curtime=0,minindex,minBT;
    printf("Enter the Number of Process :");
    int n;scanf("%d",&n);
    Process p[n];
    printf("Enter The Arrival and Burst Time\n");
    for(int i=0;i<n;i++)
    {
        p[i].id=i+1;
        p[i].iscompl=0;
        printf("P%d----------->",i+1);
        scanf("%d%d",&p[i].at,&p[i].bt);
    }
    float totaltat=0,totalwt=0;
    while(completed!=n)
    {
        minindex=-1;
        minBT=9999;
        for(int i=0;i<n;i++)
        {
            if(p[i].at<=curtime && p[i].iscompl==0)
            {
                if(p[i].bt<minBT || (p[i].bt==minBT && p[i].at<p[minindex].at))
                {
                    minBT=p[i].bt;
                    minindex=i;
                }
            }
        }
        if(minindex==-1)
        curtime++;
        else
        {
            curtime+=p[minindex].bt;
            p[minindex].ct=curtime;
            p[minindex].tat=p[minindex].ct-p[minindex].at;
            p[minindex].wt=p[minindex].tat-p[minindex].ct;
            p[minindex].iscompl=1;
            totaltat+=p[minindex].tat;
            totalwt+=p[minindex].wt;
            completed++;
            printf("|P%d (%d) %d",p[minindex].id,p[minindex].bt,p[minindex].ct);

        }
    }
    printf("|\n");
    float avg_TAT = (float)totaltat/n;
    float avg_WT = (float)totalwt/n;
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\t\n");
    for(int i=0; i<n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }
    printf("\nAverage TAT = %.2f\nAverage WT = %.2f\n", avg_TAT, avg_WT);

}

#include<stdio.h>
#include<stdlib.h>
typedef struct process
{
int id,at,bt,ct,wt,tat;
}pro;
void main()
{
printf("Enter the Number of Process : ");int n;scanf("%d",&n);
printf("Enter the Arrival and Burst Time\n");
int tempbt[n],totaltat,totalwt;
pro p[n];
for(int i=0;i<n;i++)
{
printf("P%d--------->",i+1);
p[i].id=i+1;
scanf("%d%d",&p[i].at,&p[i].bt);
tempbt[i]=p[i].bt;
}
int completed=0,curtime=0,minindex,minbt;
while(completed!=n)
{
	minindex=-1;
	minbt=9999;
	for(int i=0;i<n;i++)
	{
	if(p[i].bt>0 && p[i].at<=curtime)
	{
	if(p[i].bt<minbt ||(p[i].bt==minbt && p[i].at<=curtime))
	{
	minindex=i;
	minbt=p[i].bt;
	}
	}
	}
curtime++;
if(minindex!=-1)
{
p[minindex].bt--;
printf("|P%d(1)%d",p[minindex].id,curtime);
if(p[minindex].bt==0)
{
p[minindex].ct=curtime;
p[minindex].tat=p[minindex].ct-p[minindex].at;
p[minindex].wt=p[minindex].tat-tempbt[minindex];
totaltat+= p[minindex].tat;
totalwt+= p[minindex].wt;
completed++;
}
}
}
    printf("|\n");
    float avgtat = (float)totaltat/n;
    float avgwt = (float)totalwt/n;
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0; i<n; i++) 
	{
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].at, tempbt[i], p[i].ct, p[i].tat, p[i].wt);
    }
    printf("\nAverage TAT = %.2f\nAverage WT = %.2f\n", avgtat, avgwt);
}

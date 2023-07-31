#include<stdio.h>
#include<stdlib.h>

struct process
{
    int pid, at, bt, ct, wt, tat, completed, btr, visited;
};

typedef struct process process;

void sort(process *p, int n)
{
    process temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j].at > p[j + 1].at)
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

int f = 0, r = -1, totaltat=0, totalwt=0, q[100];

void main()
{
    printf("Enter the Number of Process and Time Quantum: ");
    int n, tq, completed = 0;
    scanf("%d%d", &n, &tq);

    process *p = (process *)calloc(n, sizeof(process));

    printf("Enter the Arrival Time and Burst Time\n");
    for (int i = 0; i < n; i++)
    {
        p[i].pid = i + 1;
        printf("Process P%d------>", i + 1);
        scanf("%d%d", &p[i].at, &p[i].bt);
        p[i].completed = 0;
        p[i].visited = 0;
        p[i].btr = p[i].bt;
    }

    sort(p, n);
    q[++r] = 0;
    p[0].visited = 1;
    int curtime = p[0].at;

    while (completed != n)
    {
        int id = q[f++];
        if (p[id].btr > tq)
        {
            p[id].btr -= tq;
            curtime += tq;
            printf("|P%d %d", p[id].pid, curtime);
        }
        else
        {
            curtime += p[id].btr;
            printf("|P%d %d", p[id].pid, curtime);

            p[id].ct = curtime;
            p[id].tat = p[id].ct - p[id].at;
            p[id].wt = p[id].tat - p[id].bt;
            completed++;
            p[id].btr = 0;
            totaltat += p[id].tat;
            totalwt += p[id].wt;
        }

        for (int i = 1; i < n; i++)
        {
            if (p[i].at <= curtime && !p[i].visited)
            {
                q[++r] = i;
                p[i].visited = 1;
            }
        }

        if (p[id].btr > 0)
        {
            q[++r] = id;
        }

        while (f > r && completed < n)
        {
            curtime++;
            printf("|IDLE %d", curtime);

            for (int i = 1; i < n; i++)
            {
                if (p[i].at <= curtime && !p[i].visited)
                {
                    q[++r] = i;
                    p[i].visited = 1;
                }
            }
        }
    }

    printf("\n\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }

    float avgtat, avgwt;
    avgtat = (float)totaltat / n;
    avgwt = (float)totalwt / n;

    printf("\nAverage TAT = %f\nAverage WT = %f\n", avgtat, avgwt);
}

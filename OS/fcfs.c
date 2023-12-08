
#include <stdio.h>

struct process
{
	int id,bt,tat,wt;
}p[50];

void main()
{
	int n,i,j;
	float avgtat=0,avgwt=0;
	printf("Enter number of processes: ");
	scanf("%d",&n);
	p[0].wt=0;
	for(i=0;i<n;i++)
	{
		printf("Enter process id: ");
		scanf("%d",&p[i].id);
		printf("Enter burst time: ");
		scanf("%d",&p[i].bt);
		p[i].tat=p[i].bt+p[i].wt;
		p[i+1].wt=p[i].tat;
		avgtat+=p[i].tat;
		avgwt+=p[i].wt;
	}
	avgtat=avgtat/n;
	avgwt=avgwt/n;
	printf("\nID\tBT\tTAT\tWT\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\t%d\n",p[i].id,p[i].bt,p[i].tat,p[i].wt);
	}
	printf("\nAverage turn around time= %0.2f\n",avgtat);
	printf("Average waiting time= %0.2f",avgwt);
	printf("\n\n|");
	for(i=1;i<n;i++)
	{
		for (j=0;j<(p[i].wt-p[i-1].wt);j++)
		{
			printf("-");
		}
		printf("|");
	}
	for (j=0;j<(p[i-1].tat-p[i-1].wt);j++)
	{
		printf("-");
	}
	printf("|");
	printf("\n|");
	for(i=1;i<n;i++)
	{
		for (j=0;j<(p[i].wt-p[i-1].wt)-1;j++)
		{
			printf(" ");
		}
		printf("%d|",p[i-1].id);
	}
	for (j=0;j<(p[i-1].tat-p[i-1].wt)-1;j++)
	{
		printf(" ");
	}
	printf("%d|",p[i-1].id);
	printf("\n|");
	for(i=1;i<n;i++)
	{
		for (j=0;j<(p[i].wt-p[i-1].wt);j++)
		{
			printf("-");
		}
		printf("|");
	}
	for (j=0;j<(p[i-1].tat-p[i-1].wt);j++)
	{
		printf("-");
	}
	printf("|\n0");
	for(i=1;i<n;i++)
	{
		if (p[i-2].tat>9)
		{
			for (j=0;j<(p[i].wt-p[i-1].wt)-1;j++)
			{
				printf(" ");
			}
		}
		else
		{
			for (j=0;j<(p[i].wt-p[i-1].wt);j++)
			{
				printf(" ");
			}
		}
		printf("%d",p[i-1].tat);
	}
	if(p[i-2].tat>9)
	{
		for (j=0;j<(p[i-1].tat-p[i-1].wt)-1;j++)
		{
			printf(" ");
		}
	}
	else
	{
		for (j=0;j<(p[i-1].tat-p[i-1].wt);j++)
		{
			printf(" ");
		}
	}
	printf("%d",p[i-1].tat);
}


*******************************************************************
>>OUTPUT

Enter number of processes: 5
Enter process id: 1
Enter burst time: 4
Enter process id: 2
Enter burst time: 3
Enter process id: 3
Enter burst time: 6
Enter process id: 4
Enter burst time: 2
Enter process id: 5
Enter burst time: 3

ID	BT	TAT	WT
1	4	4	0
2	3	7	4
3	6	13	7
4	2	15	13
5	3	18	15

Average turn around time= 11.40
Average waiting time= 7.80

|----|---|------|--|---|
|   1|  2|     3| 4|  5|
|----|---|------|--|---|
0    4   7      13 15  18


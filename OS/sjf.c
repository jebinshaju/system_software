
#include <stdio.h>

struct process{
	int id,bt,tat,wt;
}p[50],temp;

void main()
{
	int n,i,j;
	float avgtat=0,avgwt=0;
	printf("Enter number of processes: ");
	scanf("%d",&n);
	printf("\nEnter details of processes\n");
	for(i=0;i<n;i++)
	{
		printf("Enter process id: ");
		scanf("%d",&p[i].id);
		printf("Enter burst time: ");
		scanf("%d",&p[i].bt);
	}
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(p[i].bt>p[j].bt)
			{
				temp=p[i];
				p[i]=p[j];
				p[j]=temp;
			}
		}
	}
	p[0].wt=0;
	for(i=0;i<n;i++)
	{
		p[i].tat=p[i].bt+p[i].wt;
		avgtat+=p[i].tat;
		p[i+1].wt=p[i].tat;
		avgwt+=p[i].wt;
	}
	printf("\nPid\tBT\tTAT\tWT\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\t%d\n",p[i].id,p[i].bt,p[i].tat,p[i].wt);
	}
	avgtat=avgtat/n;
	avgwt=avgwt/n;
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

Enter details of processes
Enter process id: 1
Enter burst time: 7
Enter process id: 2
Enter burst time: 4
Enter process id: 3
Enter burst time: 3
Enter process id: 4
Enter burst time: 9
Enter process id: 5
Enter burst time: 6

Pid	BT	TAT	WT
3	3	3	0
2	4	7	3
5	6	13	7
1	7	20	13
4	9	29	20

Average turn around time= 14.40
Average waiting time= 8.60

|---|----|------|-------|---------|
|  3|   2|     5|      1|        4|
|---|----|------|-------|---------|
0   3    7      13      20        29

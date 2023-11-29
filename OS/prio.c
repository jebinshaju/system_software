NAME:TEENA VITHAYATHIL												
CLASS:CSE B												
SEMESTER:S5												
ROLL NUMBER:58	
DATE: 22/08/23

		    PRIORITY SCHEDULING
*******************************************************************
>>PROGRAM 

#include <stdio.h>

struct process{
	int id,bt,priority,tat,wt;
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
		printf("Enter priority: ");
		scanf("%d",&p[i].priority);
	}
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(p[i].priority>p[j].priority)
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
	printf("\nPid\tBT\tPriority\tTAT\tWT\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\t\t%d\t%d\n",p[i].id,p[i].bt,p[i].priority,p[i].tat,p[i].wt);
	}
	avgtat=avgtat/n;
	avgwt=avgwt/n;
	printf("\nAverage turn around time= %0.2f\n",avgtat);
	printf("Average waiting time= %0.2f",avgwt);
	printf("\n\n|");
	for(i=1;i<n;i++)
	{
		for (j=0;j<p[i].wt;j++)
		{
			printf("-");
		}
		printf("|");
	}
	for (j=0;j<p[i-1].tat;j++)
	{
		printf("-");
	}
	printf("|");
	printf("\n|");
	for(i=0;i<n;i++)
	{
		for(j=0;j<p[i].tat-1;j++)
		{
			printf(" ");
		}
		printf("%d|",p[i].id);
	} 
	printf("\n|");
	for(i=1;i<n;i++)
	{
		for (j=0;j<p[i].wt;j++)
		{
			printf("-");
		}
		printf("|");
	}
	for (j=0;j<p[i-1].tat;j++)
	{
		printf("-");
	}
	printf("|\n0");
	for(i=1;i<n;i++)
	{
		if (p[i-1].tat>9)
		{
			for (j=0;j<p[i].wt-1;j++)
			{
				printf(" ");
			}
		}
		else
		{
			for (j=0;j<p[i].wt;j++)
			{
				printf(" ");
			}
		}
		printf("%d",p[i-1].tat);
	}
	if(p[i-1].tat>9)
	{
		for (j=0;j<p[i-1].tat-1;j++)
		{
			printf(" ");
		}
	}
	else
	{
		for (j=0;j<p[i-1].tat-1;j++)
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
Enter burst time: 5
Enter priority: 3
Enter process id: 2
Enter burst time: 6
Enter priority: 2
Enter process id: 3
Enter burst time: 4
Enter priority: 5
Enter process id: 4
Enter burst time: 2
Enter priority: 6
Enter process id: 5
Enter burst time: 3
Enter priority: 1

Pid	BT	Priority	TAT	WT
5	3	1		3	0
2	6	2		9	3
1	5	3		14	9
3	4	5		18	14
4	2	6		20	18

Average turn around time= 12.80
Average waiting time= 8.80

|---|---------|--------------|------------------|--------------------|
|  5|        2|             1|                 3|                   4|
|---|---------|--------------|------------------|--------------------|
0   3         9             14                 18                   20





#include <stdio.h>

struct process{
	int id,bt,wt,tat,BT;	
}p[50];

void main()
{
	int ts,n,i,x=0,y=0,wt=0,tat=0,id[50],B[50],z=0,j;
	float avgtat=0,avgwt=0;
	printf("Enter time quantum: ");
	scanf("%d",&ts);
	printf("Enter number of process: ");
	scanf("%d",&n);
	printf("Enter process details\n");
	for (i=0;i<n;i++)
	{
		printf("Enter process id: ");
		scanf("%d",&p[i].id);
		printf("Enter burst time: ");
		scanf("%d",&p[i].bt);	
		p[i].BT=p[i].bt;
	} 
	i=0;
	while(1)
	{
		if (p[i].BT!=0)
		{
			if (p[i].BT>=ts)
			{
				x=x+ts;
				p[i].BT=p[i].BT-ts;
			}
			else
			{
				x=x+p[i].BT;
				p[i].BT=0;
			}
			id[z]=p[i].id;
			B[z]=x;
			z++;
			if (p[i].BT==0)
			{
				p[i].tat=x;
				y++;
			}
		}
		if (y==n)
		{
			break;
		}
		if (i==n-1)
		{
			i=0;
		}
		else
		{
			i++;
		}
	}
	for (i=0;i<n;i++)
	{
		p[i].wt=p[i].tat-p[i].bt;
	}
	printf("\nID\tBT\tTAT\tWT\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\t%d\n",p[i].id,p[i].bt,p[i].tat,p[i].wt);
		avgwt=avgwt+p[i].wt;
		avgtat=avgtat+p[i].tat;
	}
	avgtat=avgtat/n;
	avgwt=avgwt/n;
	printf("\nAverage turn around time= %0.2f\n",avgtat);
	printf("Average waiting time= %0.2f\n",avgwt);
	printf("\n|");
	for(i=0;i<z;i++)
	{
		if(i!=0)
		{
			for(j=0;j<=(B[i]-B[i-1]);j++)
			{
				printf("-");
			}
		}
		else
		{
			for(j=0;j<=B[i];j++)
			{
				printf("-");
			}
		}
		printf("|");
	}
	printf("\n|");
	for(i=0;i<z;i++)
	{
		if(i!=0)
		{
			for(j=0;j<(B[i]-B[i-1]);j++)
			{
				printf(" ");
			}
		}
		else
		{
			for(j=0;j<B[i];j++)
			{
				printf(" ");
			}
		}
		printf("%d|",id[i]);
	}
	printf("\n|");
	for(i=0;i<z;i++)
	{
		if(i!=0)
		{
			for(j=0;j<=(B[i]-B[i-1]);j++)
			{
				printf("-");
			}
		}
		else
		{
			for(j=0;j<=B[i];j++)
			{
				printf("-");
			}
		}
		printf("|");
	}
	printf("\n0");
	for(i=0;i<z;i++)
	{
		if(i!=0)
		{
			for(j=0;j<(B[i]-B[i-1]);j++)
			{
				printf(" ");
			}
		}
		else
		{
			for(j=0;j<B[i];j++)
			{
				printf(" ");
			}
		}
		if(B[i]>9 && B[i-1]>9)
		{
			printf("%d",B[i]);
		}
		else
		{
			printf(" %d",B[i]);
		}
	}
}


*******************************************************************
>>OUTPUT

Enter time quantum: 3
Enter number of process: 5
Enter process details
Enter process id: 1
Enter burst time: 4
Enter process id: 2
Enter burst time: 3
Enter process id: 3
Enter burst time: 7
Enter process id: 4
Enter burst time: 2
Enter process id: 5
Enter burst time: 8

ID	BT	TAT	WT
1	4	15	11
2	3	6	3
3	7	22	15
4	2	11	9
5	8	24	16

Average turn around time= 15.60
Average waiting time= 10.80

|----|----|----|---|----|--|----|----|--|---|
|   1|   2|   3|  4|   5| 1|   3|   5| 3|  5|
|----|----|----|---|----|--|----|----|--|---|
0    3    6    9   11   14 15   18   21 22  24




#include <stdio.h>

struct memory{
	int id,size,alloc;
	}m[10];

struct process{
	int id,size,blockno;
	}p[10];
	
void main()
{
	int m1,n,i,j,free;
	printf("Enter number of blocks: ");
	scanf("%d",&m1);
	for (i=0;i<m1;i++)
	{
		printf("Enter size of block: ");
		scanf("%d",&m[i].size);
		m[i].id=i+1;
	}
	printf("Memory ID\tMemory size\tBlock no\n");
	for (i=0;i<m1;i++)
	{
		printf("%d\t\t%d\t\t%d\n",m[i].id,m[i].size,m[i].alloc);
	}
	printf("Enter number of processes: ");
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		p[i].id=i+1;
		printf("Enter size of process: ");
		scanf("%d",&p[i].size);
	}
	for (i=0;i<n;i++)
	{
		for (j=0;j<m1;j++)
		{
			if (m[j].alloc!=1 && m[j].size>=p[i].size)
			{
				p[i].blockno=m[j].id;
				m[j].size=m[j].size-p[i].size;
				if (m[j].size==0)
				{
					m[j].alloc=1;
				}
				break;
			}
		}
	}
	printf("\nProcess ID\tProcess size\tBlock no\tFree space\n");
	for (i=0;i<n;i++)
	{	
		free=0;
		for (j=0;j<m1;j++)
		{
			if (p[i].blockno==m[j].id)
			{
				free=m[j].size;
			}
		}
		printf("%d\t\t%d\t\t%d\t\t%d\n",p[i].id,p[i].size,p[i].blockno,free);
	}
}


*******************************************************************
>>OUTPUT

Enter number of blocks: 4
Enter size of block: 200
Enter size of block: 300
Enter size of block: 400
Enter size of block: 500
Memory ID	Memory size	Block no
1		200		0
2		300		0
3		400		0
4		500		0
Enter number of processes: 3
Enter size of process: 100
Enter size of process: 250
Enter size of process: 50

Process ID	Process size	Block no	Free space
1		100		1		50
2		250		2		50
3		50		1		50


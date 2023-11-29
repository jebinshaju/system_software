NAME:TEENA VITHAYATHIL												
CLASS:CSE B												
SEMESTER:S5												
ROLL NUMBER:58	
DATE: 22/08/23

	DISK SCHEDULING-FCFS
*******************************************************************
>>PROGRAM 

#include <stdio.h>

void main()
{
	int req_no,req[50],head_pos,i,x,res=0;
	printf("Enter no of request: ");
	scanf("%d",&req_no);
	printf("Enter requests: ");
	for(i=0;i<req_no;i++)
	{
		scanf("%d",&req[i]);
	}
	printf("Enter initial head position: ");
	scanf("%d",&head_pos);
	x=head_pos;
	for(i=0;i<req_no;i++)
	{
		res+=abs(x-req[i]);
		x=req[i];
			
	}
	printf("%d",res);
}


*******************************************************************
>>OUTPUT

Enter no of request: 8
Enter requests: 98 183 37 122 14 124 65 67
Enter initial head position: 50
Seek= 643

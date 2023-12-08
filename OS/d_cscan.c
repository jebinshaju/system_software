
#include <stdio.h>
void main()
{
	int cylinder_no,req_no,req[50],head_pos,i,x,res=0,j,temp,ind;
	printf("Enter no of cylinders: ");
	scanf("%d",&cylinder_no);
	printf("Enter no of request: ");
	scanf("%d",&req_no);
	printf("Enter requests: ");
	for(i=0;i<req_no;i++)
	{
		scanf("%d",&req[i]);
	}
	printf("Enter initial head position: ");
	scanf("%d",&head_pos);
	for(i=0;i<req_no;i++)
	{
		for(j=i+1;j<req_no;j++)
		{
			if(req[i]>req[j])
			{
				temp=req[i];
				req[i]=req[j];
				req[j]=temp;
			}
		}
	}
	for(i=0;i<req_no;i++)
	{
		if(req[i]>head_pos)
		{
			break;
		}
	}
	ind=i;
	printf("Sequence: ");
	x=head_pos;
	for (i=ind;i<req_no;i++)
	{
		printf("%d->",req[i]);
		res+=req[i]-x;
		x=req[i];
	}
	res+=cylinder_no-1-x;
	x=cylinder_no-1;
	for(i=req_no-1;i>=0;i--)
	{
		res+=x-req[i];
		x=req[i];
	}
	res+=x;
	x=0;
	for(i=0;i<ind;i++)
	{	
		printf("%d",req[i]);
		if(i!=ind-1)
		{
			printf("->");
		}
		res+=req[i]-x;
		x=req[i];
	}
	printf("\nSeek= %d",res);
}


*******************************************************************
>>OUTPUT

Enter no of cylinders: 200
Enter no of request: 8
Enter requests: 98 183 37 122 14 124 65 67
Enter initial head position: 50
Sequence: 65->67->98->122->124->183->14->37
Seek= 385


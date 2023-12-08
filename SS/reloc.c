

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main()
{
	FILE *fp1,*fp2;
	int i,j,hexaddr,a;
	char ch,line[50],addr[10];
	printf("Enter the relocation address: ");
	scanf("%x",&a);
	fp1=fopen("input.txt","r");
	do
	{
		fscanf(fp1,"%s",line);
		if(line[0]=='T')
		{
			for(i=1,j=0;i<7;i++,j++)
			addr[j]=line[i];
			addr[j]='\0';
			fp2=fopen("temp.txt","r+");
			fprintf(fp2,"%s",addr);
			rewind(fp2);
			fscanf(fp2,"%x",&hexaddr);
			fclose(fp2);
			i=9;
			hexaddr=hexaddr+a;
			while(line[i]!='\0')
			{
				printf("%x\t%c%c\n",hexaddr,line[i],line[i+1]);
				hexaddr=hexaddr+1;
				i=i+2;
			}
		}
	}
	while(!feof(fp1));
	fclose(fp1);
}


INPUT
*******************************************************************

HCOPY	001000000232
T0010000C142033483039102036420334
T00200003298300
E001000


OUTPUT
*******************************************************************

Enter the relocation address: 2000
3000	14
3001	20
3002	33
3003	48
3004	30
3005	39
3006	10
3007	20
3008	36
3009	42
300a	03
300b	34
4000	29
4001	83
4002	00


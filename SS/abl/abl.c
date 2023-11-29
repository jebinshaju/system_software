NAME:TEENA VITHAYATHIL												
CLASS:CSE B												
SEMESTER:S5												
ROLL NUMBER:58

	ABSOLUTE LOADER
*******************************************************************

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main()
{
	FILE *fp1,*fp2;
	int i,j,hexaddr;
	char ch,line[50],addr[10];
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

1000	14
1001	20
1002	33
1003	48
1004	30
1005	39
1006	10
1007	20
1008	36
1009	42
100a	03
100b	34
2000	29
2001	83
2002	00


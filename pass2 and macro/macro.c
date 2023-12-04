#include<stdio.h>
#include<string.h>

FILE *fp1,*fp2;
int EXPANDING,NT_index=-1,DT_index=-1,NT_curr,indexi;
char label[20],opcode[20],operand[20];
void PROCESSLINE();
void DEFINE();
void EXPAND();
void GETLINE();

struct NAMETAB
{
	char macro_name[20];
	int start,end;	
}NT[20];

struct DEFTAB
{
	char label[20],opcode[20],operand[20];
}DT[50];

void GETLINE()
{
	int x,y;
	if(EXPANDING==1)
	{
		++indexi;
		strcpy(label,DT[indexi].label);
		strcpy(opcode,DT[indexi].opcode);
		strcpy(operand,DT[indexi].operand);
	}
	else
	{
		fscanf(fp1,"%s%s%s",label,opcode,operand);
	}
}

void EXPAND()
{
	EXPANDING=1;
	
	indexi=NT[NT_curr].start;
	fprintf(fp2,".%s\t%s\t%s\n",label,opcode,operand);
	GETLINE();
	do
	{
		PROCESSLINE();
		GETLINE();
	}while(strcmp(opcode,"MEND")!=0);
	
	EXPANDING=0;
}

void DEFINE()
{
	strcpy(NT[++NT_index].macro_name,label);
	
	strcpy(DT[++DT_index].label,label);
	strcpy(DT[DT_index].opcode,opcode);
	strcpy(DT[DT_index].operand,operand);
	NT[NT_index].start=DT_index;
	
	do
	{
		GETLINE();
		strcpy(DT[++DT_index].label,label);
		strcpy(DT[DT_index].opcode,opcode);
		strcpy(DT[DT_index].operand,operand);
	}while(strcmp(opcode,"MEND")!=0);
	NT[NT_index].end=DT_index;
}

void PROCESSLINE()
{
	int i,flag=0;
	for(i=0;i<=NT_index;i++)
	{
		if(strcmp(NT[i].macro_name,opcode)==0)
		{
			NT_curr=i;
			flag=1;
			break;
		}
	}
	
	if(flag==1)
	{
		EXPAND();
	}
	else if(strcmp(opcode,"MACRO")==0)
	{
		DEFINE();
	}
	else
	{
		fprintf(fp2,"%s\t%s\t%s\n",label,opcode,operand);
	}
}

int main()
{
	fp1=fopen("input.txt","r");
	fp2=fopen("expanded.txt","w");
	EXPANDING=0;
	while(strcmp(opcode,"END")!=0)
	{
		GETLINE();
		PROCESSLINE();
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}



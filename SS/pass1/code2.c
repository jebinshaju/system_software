#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char label[10],opcode[10],operand[10],addr[10];
int length,i,o=0,s=0,len,value,size;
FILE *f1,*f2,*f3,*f4,*f5,*f6;

struct optab
{
	char opcode[5],hexcode[2];
}op[50];

struct symtab
{
	char label[10],addr[4];
}sym[50];

void read_optab()
{
	while (getc(f2)!=EOF)
	{
		fscanf(f2,"%s\t%s\n",op[o].opcode,op[o].hexcode);
		o++;
	}
}

void read_symtab()
{
	while (getc(f2)!=EOF)
	{
		fscanf(f3,"%s\t%s\n",sym[s].label,sym[s].addr);
		s++;
	}
}

void main()
{
	
	f1=fopen("intermediate.txt","r");
	f2=fopen("optab.txt","r");
	f3=fopen("symtab.txt","r");
	f4=fopen("length.txt","r");
	f5=fopen("assembly listing.txt","w");
	f6=fopen("object program.txt","w");
	
	read_optab();
	read_symtab();
	fscanf(f4,"%x%x",&length,&size);
	if(f1==NULL)
	{
		printf("NOT OPENED");
	}
	else
	{
		fscanf(f1,"%s%s%s%s",addr,label,opcode,operand);
		if (strcmp(opcode,"START")==0)
		{
			fprintf(f5,"%s\t%s\t%s\t%s\n",addr,label,opcode,operand);
			fprintf(f6,"H^00%s^00%s^0000%x",label,addr,length);
		}
		else
		{
			while (strcmp(opcode,"END")!=0)
			{
				fscanf(f1,"%s\t%s\t%s",label,opcode,operand);
				if(strcmp(opcode,"WORD")==0)
				{
					size=size+3;
				}
				else if(strcmp(opcode,"RESW")==0||strcmp(opcode,"RESB")==0)
				{
					fprintf(f5,"%s\t%s\t%s\t%s-\n",addr,label,opcode,operand);
				}
				else if(strcmp(opcode,"BYTE")==0)
				{
					if (operand[0]=='C')
					{
						len=strlen(operand)-3;
						size=size+len;
					}
					else
					{
						len=(strlen(operand)-3)/2;
						size=size+len;
					}	
				}	
			}
		}
	}
}

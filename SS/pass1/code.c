NAME:TEENA VITHAYATHIL												
CLASS:CSE B												
SEMESTER:S5												
ROLL NUMBER:58

	PASS ONE OF 
*******************************************************************

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char label[10],opcode[10],operand[10];
int start=0,locctr,length,flag,i,o=0,s=-1,len,value,operand1,size;
FILE *f1,*f2,*f3,*f4,*f5;
struct optab
{
	char opcode[5],hexcode[2];
}op[50];

struct symtab
{
	char label[10];
	int addr;
}sym[50];

void read_optab()
{
	while (getc(f2)!=EOF)
	{
		fscanf(f2,"%s\t%s\n",op[o].opcode,op[o].hexcode);
		o++;
	}
}

void symtab()
{
	fprintf(f3,"%s\t%x\n",sym[s].label,sym[s].addr);
}

void main()
{
	f1=fopen("input.txt","r");
	f2=fopen("optab.txt","r");
	f3=fopen("symtab.txt","w");
	f4=fopen("intermediate.txt","w");
	f5=fopen("length.txt","w");
	read_optab();
	fscanf(f1,"%s%s%x",label,opcode,&operand1);
	if (strcmp(opcode,"START")==0)
	{
		start=operand1;
		locctr=operand1;
		fprintf(f4,"\t%s\t%s\t%x\n",label,opcode,operand1);
		fscanf(f1,"%s\t%s\t%s",label,opcode,operand);
	}
	else
	{
		locctr=0;
	}
	while (strcmp(opcode,"END")!=0)
	{
		fprintf(f4,"%x\t%s\t%s\t%s\n",locctr,label,opcode,operand);
		if (strcmp(label,"-")!=0)
		{
			for(i=0;i<s;i++)
			{
				if(strcmp(sym[i].label,label)==0)
				{
					flag=1;
					printf("Duplicate symbol found");		
					exit(0);		
				}
			}
			s++;
			strcpy(sym[s].label,label);
			sym[s].addr=locctr;
			symtab();
		}
		flag=0;
		for(i=0;i<o;i++)
		{
			if(strcmp(op[i].opcode,opcode)==0)
			{
				flag=1;	
				size=size+3;
				break;		
			}
		}
		if(strcmp(opcode,"WORD")==0)
		{
			locctr=locctr+0x3;
			size=size+3;
		}
		else if(strcmp(opcode,"RESW")==0)
		{
			locctr=locctr+0x3*atoi(operand);
		}
		else if(strcmp(opcode,"BYTE")==0)
		{
			if (operand[0]=='C')
			{
				len=strlen(operand)-3;
				size=size+len;
				locctr=locctr+len;
			}
			else
			{
				len=(strlen(operand)-3)/2;
				size=size+len;
				locctr=locctr+len;
			}	
		}
		else if(strcmp(opcode,"RESB")==0)
		{
			locctr=locctr+atoi(operand);
		}
		else if(flag==1)
		{
			printf("Opcode Invalid");
			exit(0);
		}
		else
		{
			locctr=locctr+0x3;
			size=size+3;
		}
		fscanf(f1,"%s\t%s\t%s",label,opcode,operand);
	}
	fprintf(f4,"\t%s\t%s\t%s\n",label,opcode,operand);
	fprintf(f5,"%x\t%x",locctr-start,size);
}


INPUT
*******************************************************************

INPUT FILE
**********
COPY	START	2000
FIRST	LDX	FIVE
-	STA	ALPHA
-	LDCH	CHARZ
-	STCH	C1
ALPHA	RESW	3
FIVE	WORD	5
CHARZ	BYTE	C'Zded'
CHARX	BYTE	X'1234'
C1	RESB	2
-	END	FIRST

OPTAB
*****
LDA	00
STA	0C
LDCH	50
STCH	54


OUTPUT
*******************************************************************

SYMTAB
******
FIRST	2000
ALPHA	200c
FIVE	2015
CHARZ	2018
CHARX	201c
C1	201e

LENGTH
******
20	15

INTERMEDIATE FILE
*****************
	COPY	START	2000
2000	FIRST	LDX	FIVE
2003	-	STA	ALPHA
2006	-	LDCH	CHARZ
2009	-	STCH	C1
200c	ALPHA	RESW	3
2015	FIVE	WORD	5
2018	CHARZ	BYTE	C'Zded'
201c	CHARX	BYTE	X'1234'
201e	C1	RESB	2
	-	END	FIRST
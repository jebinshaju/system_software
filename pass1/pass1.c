#include<stdio.h>
#include<string.h>
#include<stdlib.h>


char opcode[10],operand[10],label[10];
int locctr,start,len,s=-1,o=-1,i,j=0,flag,size=0,opd;
FILE *fp1,*fp2,*fp3,*fp4,*fp5;


struct SYMTAB
{
    char label[10];
    int addr;       
}symt[30];

struct OPTAB
{
    char opcode[10];
    char hexcode[10];
}opt[30];

void read_optab()
{
    while(1)
    {
            o++;
            fscanf(fp2,"%s%s",opt[o].opcode,opt[o].hexcode); 
            if(getc(fp2)==EOF)       
				break;                    
    }                  
}


int main()
{
	
	fp1=fopen("/home/user/monkey/pass1/input.txt","r");
	fp2=fopen("/home/user/monkey/pass1/optab.txt","r");
	fp3=fopen("/home/user/monkey/pass1/symtab.txt","w");
	fp4=fopen("/home/user/monkey/pass1/inter.txt","w");
	fp5=fopen("/home/user/monkey/pass1/size.txt","w");
	read_optab();  
	
	fscanf(fp1,"%s%s%x",label,opcode,&opd);
	if(strcmp(opcode,"START")==0)
	{
		start=opd;
		locctr=start;
		fprintf(fp4,"\t%s\t%s\t%x\n",label,opcode,opd);
		fscanf(fp1,"%s%s%s",label,opcode,operand);	
	}
	else
	{
		locctr=0;
	}

	while(strcmp(opcode,"END")!=0)
	{
		fprintf(fp4,"%x\t%s\t%s\t%s\n",locctr,label,opcode,operand); 
		if(strcmp(label,"-")!=0)   
		{
		  	for(i=0;i<=s;i++)
        	{
        		if(strcmp(symt[i].label,label)==0)  
                {
                    printf("Error");
                    exit(0);                                
                }           
            }
            s++;
            strcpy(symt[s].label,label); 
            symt[s].addr=locctr;  
          }
         flag=0;
		for(i=0;i<=o;i++)
		{
			if(strcmp(opcode,opt[i].opcode)==0) 
			{
				locctr+=0x3;
				size=size+3;
			
				flag=1;
				break;
			}
		}
		if(flag==0)
    	{
        	if(strcmp(opcode,"WORD")==0)       
        	{
        		locctr+=0x3;
        		
				size=size+3;
			}	
    		else if(strcmp(opcode,"RESW")==0)
    		{
    		   
    			locctr+=(0x3*(atoi(operand)));
    		}
    		else if(strcmp(opcode,"RESB")==0) 
    		{
    		  printf("%x ok",locctr);
    			locctr=locctr+(atoi(operand));
    			printf("%x ok",locctr);
    		}
    		else if(strcmp(opcode,"BYTE")==0)   
    		{
    			len=strlen(operand);
    			if(operand[0]=='C' || operand[0]=='c')
    			{
    				len=len-3;
    				
    			}
    			else
    			{
    			
    				len=(len-3)/2;
    			}
    			
    			locctr+=len;
				size=size+len;
				
				
			}
        }
        fscanf(fp1,"%s%s%s",label,opcode,operand); 
	}
	fprintf(fp4,"\t%s\t%s\t%s\n",label,opcode,operand);	
    for(i=0;i<=s;i++)
	{
        fprintf(fp3,"%s\t%d\n",symt[i].label,symt[i].addr); 
		    }
	fprintf(fp5,"%x\n%d",locctr-start,size);
	printf("%x loct",locctr);
	printf("%x start",start);
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);
    fclose(fp5);

}


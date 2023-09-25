DATA SEGMENT 
MSG1 DB 0AH,0DH,"ENTER THE STRING: $"
MSG2 DB 0AH,0DH,"THE SORTED STRING IS: $"
CHR1 DB 10D DUP(?)
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE,DS:DATA

START: 	MOV AX,DATA
	 	  	MOV DS,AX
	
			MOV AH,09H
			LEA DX,MSG1
			INT 21H
			
		
			
			LEA SI,CHR1
			MOV CL,00H
	
L2:		MOV AH,01H
	 		INT 21H
			 
			 CMP AL,0DH
			 JZ L1
			 MOV[SI],AL
			 INC SI
			 INC CL
			 JMP L2
			 
L1:		 MOV BH,CL
			MOV CH,BH

			 
L3:		 LEA SI,CHR1
			 MOV CL,BH
			
L4:  		MOV AL,[SI]
			MOV BL,[SI+1]
			
			CMP AL,BL
			JC L5
			
			XCHG AL,BL
			MOV [SI],AL
			MOV [SI+1],BL
			
L5:		INC SI
			DEC CL
			JNZ L4
			DEC CH
			
			JNZ L3
			INC BH
			
			
L6: 		
				
			 LEA DX,MSG2
			 MOV AH,09H
			 INT 21H
			 
			 INC BH
			 LEA SI,CHR1
L7:
			MOV AH,02H
			 MOV DL,[SI]
			 INT 21H
			 INC SI
			 DEC BH
			 JNZ L7
			 MOV AH,4CH
			 INT 21H			
			

CODE ENDS
END START


































			 

			 


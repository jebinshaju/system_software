DATA SEGMENT
MSG1 DB 0AH,0DH,"Enter the string: $"
MSG2 DB 0AH,0DH,"The entered string is: $"
CHR DB 10D DUP(?)
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE,DS:DATA

START: MOV AX,DATA
       MOV DS,AX
       
       MOV AH,09H
       LEA DX,MSG1
       INT 21H
       
       MOV CL,00H	
       LEA SI,CHR	
   L2: MOV AH,01H
       INT 21H		
       CMP AL,0DH
       JZ L1
       MOV [SI],AL
       INC SI
       INC CL
       JMP L2
       
   L1: MOV AH,09H
       LEA DX,MSG2
       INT 21H

   L3: MOV AH,02H
       MOV DL,[SI]
       INT 21H
       DEC SI
       DEC CL
       JNZ L3
       
       MOV AH,02H
       MOV DL,[SI]
       INT 21H
       
       MOV AH,4CH
       INT 21H
CODE ENDS
END START      

 

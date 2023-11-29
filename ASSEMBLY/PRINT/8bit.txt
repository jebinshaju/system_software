NAME:TEENA VITHAYATHIL												
CLASS:CSE B												
SEMESTER:S5												
ROLL NUMBER:58

	ADDITION OF TWO 8 BIT NUMBERS
*******************************************************************

DATA SEGMENT
MSG1 DB 0AH,0DH,"Enter first number: $"
MSG2 DB 0AH,0DH,"Enter second number: $"
MSG3 DB 0AH,0DH,"Sum: $"
MSG4 DB 0AH,0DH,"Carry: $"
A DB 00H
B DB 00H
SUM DB 00H
CARRY DB 00H
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE,DS:DATA
START: MOV AX,DATA
       MOV DS,AX
       
       MOV AH,09H
       LEA DX,MSG1
       INT 21H
       CALL P1
       MOV A,AL
       
       MOV AH,09H
       LEA DX,MSG2
       INT 21H
       CALL P1
       MOV B,AL
       
       MOV AL,A
       MOV BL,B
       ADD AL,BL
       JNC L3
       INC CARRY
       
   L3: MOV SUM,AL
       LEA SI,SUM
       MOV AH,09H
       LEA DX,MSG3
       INT 21H
       CALL P2
       
       LEA SI,CARRY
       MOV AH,09H
       LEA DX,MSG4
       INT 21H
       CALL P2
       
       MOV AH,4CH
       INT 21H
       
    P1 PROC
       MOV AH,01H
       INT 21H
       SUB AL,30H
       CMP AL,09H
       JLE L1
       SUB AL,07H
   
   L1: MOV CL,04H
       ROL AL,CL
       MOV CH,AL
       MOV AH,01H
       INT 21H
       SUB AL,30H
       CMP AL,09H
       JLE L2
       SUB AL,07H
     
   L2: ADD AL,CH
       RET 
       P1 ENDP   
       
    P2 PROC  
       MOV AL,[SI]
       AND AL,0F0H
       MOV CL,04H
       ROL AL,CL
       ADD AL,30H
       CMP AL,39H
       JLE L4
       ADD AL,07H
       
   L4: MOV AH,02H
       MOV DL,AL
       INT 21H
       MOV AL,[SI]
       AND AL,0FH
       ADD AL,30H
       CMP AL,39H
       JLE L5
       ADD AL,07H
       
   L5: MOV AH,02H
       MOV DL,AL
       INT 21H
       RET
       P2 ENDP    
       
CODE ENDS
END START 

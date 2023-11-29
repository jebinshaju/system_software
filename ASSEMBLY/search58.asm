DATA SEGMENT
MSG1 DB 0AH,0DH,"Enter first number: $"
MSG2 DB 0AH,0DH,"Enter second number: $"
MSG3 DB 0AH,0DH,"Enter third number: $"
MSG4 DB 0AH,0DH,"Enter forth number: $"
MSG5 DB 0AH,0DH,"Enter fifth number: $"
MSG6 DB 0AH,0DH,"Enter number to be searched for: $"
MSG7 DB 0AH,0DH,"Number found$"
MSG8 DB 0AH,0DH,"Number not found$"
A DW 00H
B DW 00H
F DW 00H
D DW 00H
E DW 00H
S DW 00H
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE,DS:DATA
START: MOV AX,DATA
       MOV DS,AX
       
       MOV AH,09H
       LEA DX,MSG1
       INT 21H
       LEA SI,A
       INC SI
       CALL P1
       MOV [SI],AL
       DEC SI
       CALL P1
       MOV [SI],AL
       
       MOV AH,09H
       LEA DX,MSG2
       INT 21H
       LEA SI,B
       INC SI
       CALL P1
       MOV [SI],AL
       DEC SI
       CALL P1
       MOV [SI],AL 
       
       MOV AH,09H
       LEA DX,MSG3
       INT 21H
       LEA SI,F
       INC SI
       CALL P1
       MOV [SI],AL
       DEC SI
       CALL P1
       MOV [SI],AL 
       
       MOV AH,09H
       LEA DX,MSG4
       INT 21H
       LEA SI,D
       INC SI
       CALL P1
       MOV [SI],AL
       DEC SI
       CALL P1
       MOV [SI],AL 
       
       MOV AH,09H
       LEA DX,MSG5
       INT 21H
       LEA SI,E
       INC SI
       CALL P1
       MOV [SI],AL
       DEC SI
       CALL P1
       MOV [SI],AL 
       
       MOV AH,09H
       LEA DX,MSG6
       INT 21H
       LEA SI,S
       INC SI
       CALL P1
       MOV [SI],AL
       DEC SI
       CALL P1
       MOV [SI],AL 
       
       MOV AX,S
       MOV BX,A
       CMP AX,BX
       JE L3
       MOV AX,S
       MOV BX,B
       CMP AX,BX
       JE L3
       MOV AX,S
       MOV BX,F
       CMP AX,BX
       JE L3
       MOV AX,S
       MOV BX,D
       CMP AX,BX
       JE L3
       MOV AX,S
       MOV BX,E
       CMP AX,BX
       JE L3
       MOV AH,09H
       LEA DX,MSG8
       INT 21H
       
    L3:MOV AH,09H
       LEA DX,MSG7
       INT 21H
       
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
       
CODE ENDS
END START 

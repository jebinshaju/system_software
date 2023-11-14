#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct SYMTAB {
    char label[10];
    int addr;
};

struct OPTAB {
    char opcode[10];
    char hexcode[10];
};

FILE *fp1, *fp2, *fp3, *fp4, *fp5;
char opcode[10], operand[10], label[10], t1[20], t2[20], t3[10];
int locctr, start, len, s = -1, o = -1, i, j = 0, flag, size = 0, opd;

struct SYMTAB ST[30];
struct OPTAB OT[30];

void read_OPTAB() {
    while (1) {
        o++;
        fscanf(fp2, "%s%s", OT[o].opcode, OT[o].hexcode);
        if (getc(fp2) == EOF)
            break;
    }
}

int search_SYMTAB(char symbol[]) {
    for (int i = 0; i <= s; i++) {
        if (strcmp(ST[i].label, symbol) == 0)
            return ST[i].addr;
    }
    return -1;
}

void pass2() {
    char objcode[10], operandAddr[10], temp[10];
    int address, operandAddress, len;

    // Open intermediate and optab files
    fp4 = fopen("E:\\intermed.txt", "r");
    fp2 = fopen("E:\\optab.txt", "r");
    fp5 = fopen("E:\\objectprog.txt", "w");

    // Read first line from intermediate file
    fscanf(fp4, "%x%s%s%s", &address, label, opcode, operand);

    // Write Header record to object program
    fprintf(fp5, "H^%s^%06X^%06X\n", label, start, size);

    // Initialize first Text record
    fprintf(fp5, "T^%06X^", address);

    // While OPCODE != 'END'
    while (strcmp(opcode, "END") != 0) {
        if (opcode[0] != '.') {  // Not a comment line
            // Search OPTAB for OPCODE
            int found = 0;
            for (i = 0; i <= o; i++) {
                if (strcmp(opcode, OT[i].opcode) == 0) {
                    found = 1;
                    break;
                }
            }

            if (found) {
                if (operand[0] != '-') {  // Symbol in OPERAND field
                    // Search SYMTAB for operand
                    operandAddress = search_SYMTAB(operand);
                    if (operandAddress != -1) {
                        sprintf(operandAddr, "%X", operandAddress);
                    } else {
                        // Set error flag
                        printf("Error: Symbol not found in SYMTAB\n");
                        exit(0);
                    }
                } else {
                    // Set 0 as operand address
                    strcpy(operandAddr, "0000");
                }

                // Assemble the object code instruction
                sprintf(objcode, "%s%s", OT[i].hexcode, operandAddr);
            } else if (strcmp(opcode, "BYTE") == 0 || strcmp(opcode, "WORD") == 0) {
                // Convert constant to object code
                if (opcode[0] == 'B') {
                    // Handle BYTE constant
                    len = strlen(operand) - 3;
                    sprintf(objcode, "%.*s", len, operand + 2);
                } else {
                    // Handle WORD constant
                    sscanf(operand, "%d", &operandAddress);
                    sprintf(objcode, "%06X", operandAddress);
                }
            }

            // If object code will not fit into the current Text record
            if (strlen(temp) + strlen(objcode) > 60) {
                // Write Text record to object program
                fprintf(fp5, "%02X%s\n", strlen(temp) / 2, temp);
                // Initialize new Text record
                fprintf(fp5, "T^%06X^", address);
                strcpy(temp, "");
            }

            // Add object code to Text record
            strcat(temp, objcode);
        }

        // Read next input line
        fscanf(fp4, "%x%s%s%s", &address, label, opcode, operand);
    }

    // Write last Text record to object program
    fprintf(fp5, "%02X%s\n", strlen(temp) / 2, temp);

    // Write End record to object program
    fprintf(fp5, "E^%06X\n", start);

    // Close files
    fclose(fp4);
    fclose(fp2);
    fclose(fp5);
}

int main() {
    fp1 = fopen("E:\\input.txt", "r");
    fp2 = fopen("E:\\optab.txt", "r");
    fp3 = fopen("E:\\symtab.txt", "w");
    fp4 = fopen("E:\\intermed.txt", "w");
    fp5 = fopen("E:\\length.txt", "w");

    read_OPTAB();  // read OPTAB

    // Read the first line
    fscanf(fp1, "%s%s%x", label, opcode, &opd);
    if (strcmp(opcode, "START") == 0) {
        start = opd;
        locctr = start;
        fprintf(fp4, "\t%s\t%s\t%x\n", label, opcode, opd);
        fscanf(fp1, "%s%s%s", label, opcode, operand);  // read the next line
    } else
        locctr = 0;

    // do until END
    while (strcmp(opcode, "END") != 0) {
        fprintf(fp4, "%x\t%s\t%s\t%s\n", locctr, label, opcode, operand);

        if (strcmp(label, "-") != 0) {  // if label present
            for (i = 0; i <= s; i++) {
                if (strcmp(ST[i].label, label) == 0) {  // if SYMTAB contains the present label
                    printf("Error\n");
                    exit(0);
                }
            }
            s++;
            strcpy(ST[s].label, label);
            ST[s].addr = locctr;  // if SYMTAB does not contain the present label
        }

        // Search OPTAB for opcode
        flag = 0;
        for (i = 0; i <= o; i++) {
            if (strcmp(opcode, OT[i].opcode) == 0) {  // if opcode is in OPTAB
                locctr += 0x3;
                size = size + 3;
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            if (strcmp(opcode, "WORD") == 0) {  // if opcode = "WORD"
                locctr += 0x3;
                size = size + 3;
            } else if (strcmp(opcode, "RESW") == 0)  // if opcode = "RESW"
                locctr += (0x3 * (atoi(operand)));
            else if (strcmp(opcode, "RESB") == 0)  // if opcode = "RESB"
                locctr += (atoi(operand));
            else if (strcmp(opcode, "BYTE") == 0) {  // if opcode = "BYTE"
                len = strlen(operand);
                if (operand[0] == 'C' || operand[0] == 'c')
                    len = len - 3;
                else
                    len = (len - 3) / 2;
                locctr += len;
                size = size + len;
            }
        }

        fscanf(fp1, "%s%s%s", label, opcode, operand);  // read the next line
    }

    fprintf(fp4, "\t%s\t%s\t%s\n", label, opcode, operand);  // Write last line into intermediate file

    // write the contents of ST to symboltab.txt
    for (i = 0; i <= s; i++) {
        fprintf(fp3, "%s\t%x", ST[i].label, ST[i].addr);
    }

    fprintf(fp5, "%x\n%x", locctr - start, size);

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);
    fclose(fp5);

    // Call pass2
    pass2();

    return 0;
}

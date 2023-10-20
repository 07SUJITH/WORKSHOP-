#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct SYMTAb
{
    char symbol[30];
    char address[30];
} s[100];

int scount = 0;

int hexToDecimal(char hex[]){
    int len, i, temp;
    int dec = 0;
    len = strlen(hex);
    for (i = 0; i < len; i++){
        switch (hex[i]){
		    case '0':		temp = 0; break;
		    case '1':		temp = 1; break;
		    case '2':		temp = 2; break;
		    case '3':		temp = 3; break;
		    case '4':		temp = 4; break;
		    case '5':		temp = 5; break;
		    case '6':		temp = 6; break;
		    case '7':		temp = 7; break;
		    case '8':		temp = 8; break;
		    case '9':		temp = 9; break;
		    case 'A':
		    case 'a':		temp = 10; break;
		    case 'B':
		    case 'b':		temp = 11; break;
		    case 'C':
		    case 'c':		temp = 12; break;
		    case 'D':
		    case 'd':		temp = 13; break;
		    case 'E':
		    case 'e':		temp = 14; break;
		    case 'F':
		    case 'f':		temp = 15; break;
        }
        dec = dec + temp * pow(16, len - i - 1);
    }
    return dec;
}

void onepass(){
    char label[30], opcode[30], operand[30], address[30];
    char loc[30];
    int flag, j;
    int startaddress, locctr = 0, i;
    FILE *fp1, *fp2,*fp3,*fp4;
    fp1 = fopen("source.txt", "r");
    fp2 = fopen("intermediate.txt", "w");
    fscanf(fp1, "%s%s%s", label, opcode, operand);
    while (!feof(fp1)){
        if (strcmp(opcode, "START") == 0){
            startaddress = hexToDecimal(operand);
            locctr = hexToDecimal(operand);
            fprintf(fp2, "%x\t\t%s\t\t%s\t\t%s\n", locctr, label, opcode, operand);
            fscanf(fp1, "%s%s%s", label, opcode, operand);
        }
        if (strcmp(label, "**") != 0){
            strcpy(s[scount].symbol, label);
            sprintf(address, "%x", locctr);
            strcpy(s[scount++].address, address);
        }
        fprintf(fp2, "%x\t\t%s\t\t%s\t\t%s\n", locctr, label, opcode, operand);
        if (strcmp(opcode, "WORD") == 0)		 	locctr += 3;
        else if (strcmp(opcode, "RESW") == 0)	 	locctr += atoi(operand) * 3;
        else if (strcmp(opcode, "RESB") == 0)	  	locctr += atoi(operand);
        else if (strcmp(opcode, "BYTE") == 0) 		locctr += strlen(operand);
        else	if (strcmp(opcode,"END") !=0)			locctr += 3;
        fscanf(fp1, "%s%s%s", label, opcode, operand);
    }
    fclose(fp2);
    fclose(fp1);
    
    // output 1
    printf("symbol table\n\n");
    fp4 =fopen("symtab.txt","w");
    for (i = 0; i < scount; i++){   
    	printf("%s\t%s\n", s[i].symbol, s[i].address);
    	fprintf(fp4,"%s\t%s\n",s[i].symbol,s[i].address);
    }
    fclose(fp4);
    
    // output 2
    printf("\nintermediate code of assembler \n\n");
    fp2 = fopen("intermediate.txt", "r");
    char str = fgetc(fp2);
    while (str != EOF) {
        printf("%c", str);
        str = fgetc(fp2);
    }
    fclose(fp2);
    
    //output 3
    fp3 = fopen("length.txt","w");
    int length = locctr - startaddress;
    printf("\nlength of Program : %x\n",length);
    fprintf(fp3, "%x",length);
    fclose(fp3);
}

void main(){
    onepass();
}
/*
gcc pass1.c -lm
./a.out

symbol table

FIRST	1000
ALPHA	1009
BETA	100c
GAMMA	100f

intermediate code of assembler 

1000		COPY		START		1000
1000		FIRST		LDA		ALPHA
1003		**		MUL		BETA
1006		**		STA		GAMMA
1009		ALPHA		WORD		2
100c		BETA		WORD		4
100f		GAMMA		RESW		1
1012		**		END		1000

length of Program : 12

limitations
-----------
(opcode checking in optab is not added)
(length of constant calculating is not done in proper way)
*/

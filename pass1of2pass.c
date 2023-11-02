#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include<stdbool.h>

void display();  
void onepass();   
int hexToDecimal( char *);  

int  main(){
    onepass();
    return 0;
}

void onepass(){
    char label[30], opcode[30], operand[30];
    bool validOpcode;
    char code[10],mnemonic[10];
    int startAddress, locctr = 0, i;
    FILE *fp1,*fp2,*fp3,*fp4,*fp5;
    fp1 = fopen("input.txt", "r");
    fp2 =fopen("optab.txt","r");
    fp3 =fopen("symtab.txt","w");
    fp4 = fopen("intermediate.txt", "w");
    fp5 = fopen("length.txt","w");
    fscanf(fp1, "%s%s%s", label, opcode, operand);
 
    if (strcmp(opcode, "START") == 0){
            startAddress = hexToDecimal(operand);
            locctr = startAddress;
            fprintf(fp4, "%x\t\t%s\t\t%s\t\t%s\n", locctr, label, opcode, operand);
            fscanf(fp1, "%s%s%s", label, opcode, operand);
    }else locctr = 0;

    while (strcmp(opcode,"END") !=  0){
        fprintf(fp4, "%x\t\t%s\t\t%s\t\t%s\n", locctr, label, opcode, operand);
        if (strcmp(label, "**") != 0){ 
            fprintf(fp3,"%s\t%x\n",label,locctr);
        }
        fscanf(fp2, "%s\t%s", code, mnemonic);
        validOpcode =false;
        while (strcmp(code, "END") != 0) {
            if (strcmp(opcode, code) == 0) {                
                locctr += 3;
                validOpcode = true;
                break;
            }
            fscanf(fp2, "%s\t%s", code, mnemonic);
        }
        if(!validOpcode){
            if (strcmp(opcode, "WORD") == 0)
        		 	locctr += 3;
            else if (strcmp(opcode, "RESW") == 0)
        	 	locctr += atoi(operand) * 3;
            else if (strcmp(opcode, "RESB") == 0)
        	  	locctr += atoi(operand);
            else if (strcmp(opcode, "BYTE") == 0){
                int len = strlen(operand);
                len -=3;
                if(operand[0] == 'C' || operand[0] == 'c')
                    locctr += len;
                else    
                    locctr += ceil(len/2.0);
            }
            else{
                printf("\ninvalid opcode %s  !!!",opcode);
                exit(1);
            }    
        }
        fscanf(fp1, "%s%s%s", label, opcode, operand); 
    }
    fprintf(fp4, "%x\t\t%s\t\t%s\t\t%s\n", locctr, label, opcode, operand);
    int programLength = locctr - startAddress;
    fprintf(fp5, "%x",programLength);
    fclose(fp1);    
    fclose(fp2);    
    fclose(fp3);
    fclose(fp4);
    fclose(fp5);
    display();
}

int hexToDecimal(char hex[]){
    int len, i, temp;
    int dec = 0;
    len = strlen(hex);
    for (i = 0; i < len; i++){
        if(hex[i] >= '0' && hex[i] <= '9')
        	temp = hex[i] - '0';
        else 
        	temp = hex[i]  - '0' - 7 ;
        dec = dec + temp * pow(16, len - i - 1);
    }
    return dec;
}
void display(){
    FILE *fp;
    printf("SYMBOL TABLE\n\n");
    fp = fopen("symtab.txt","r");
    char ch = fgetc(fp);
    while(ch != EOF){
        printf("%c",ch);
        ch = fgetc(fp);
    }    
    fclose(fp);

    printf("\nINTERMEDIATE FILE \n\n");
    fp = fopen("intermediate.txt", "r");
    ch = fgetc(fp);
    while (ch != EOF) {
        printf("%c", ch);
        ch = fgetc(fp);
    }
    fclose(fp);
    fp = fopen("length.txt","r");
    char length[5] ;
    fscanf(fp,"%s",length);
    printf("\nPROGRAM LENGTH : %s bytes \n\n",length);
    fclose(fp);
}

/*
SYMBOL TABLE

FIRST   1000
ALPHA   1009
BETA    100c
GAMMA   100f

INTERMEDIATE FILE

1000            COPY            START           1000
1000            FIRST           LDA             ALPHA
1003            **              MUL             BETA
1006            **              STA             GAMMA
1009            ALPHA           WORD            2
100c            BETA            WORD            4
100f            GAMMA           RESW            1
1012            **              END             1000

PROGRAM LENGTH : 12 bytes
*/

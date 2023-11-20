 //pass2 of two pass assembler
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXRECORD 10

void assemblyListing(FILE *fp,char *locctr,char *label,
char *opcode,char *operand,char *objectCode){
    fprintf(fp,"%s\t%s\t%s\t%s\t%s\n",locctr,label,opcode,operand,objectCode);
}
void textRecordWriting(FILE *fp,int *textlen,char *text){
    char inter[3];
    sprintf(inter, "%02x", ((*textlen)*3));
    text[9] = inter[0]; text[10] = inter[1];
    fprintf(fp, "%s", text);
    (*textlen) = 0;
}
void textRecordInitializer(char* locctr,char *text,int *count){
    int startAddress = strtol(locctr,NULL,16);
    sprintf(text,"T^%06x^",startAddress);
    *count = 11;
    for (int i = 11; i < sizeof(text); i++)
        text[i] = '\0';
}
void display(char *fileName){
    FILE *fp = fopen(fileName,"r");
    char ch = fgetc(fp);
    while(ch != EOF){
        printf("%c",ch);
        ch = fgetc(fp);
    }    
    fclose(fp);
}

int main(){

    FILE *fp1,*fp2,*fp3,*fp4,*fp5,*fp6;
    char label[10],opcode[10],operand[10],symbol[20],value[10],locctr[10];
    char symbol1[10],value1[10], text[81], inter[3];
    char byteConstant[7],length[3];
    int  count,textlen,byteLastIndex;
    int startDecimal ;

    fp1 = fopen("C:\\Users\\User\\OneDrive\\Desktop\\pass2\\intermediate.txt","r");
    fp2 = fopen("C:\\Users\\User\\OneDrive\\Desktop\\pass2\\length.txt" ,"r");
    fp5 = fopen("objectProgram.txt","w");
    fp6 = fopen("assemblyListing.txt","w");

    if (fp1 == NULL || fp2==NULL) {
        printf("\nError in opening file\n");
        return 1;
    }
    fscanf(fp2,"%s",length);
    int lengthInDecimal = strtol(length ,NULL,16);
    fscanf(fp1,"%s%s%s%s",locctr,label,opcode,operand);
    if(!strcmp(opcode,"START")){
        startDecimal = strtol(locctr,NULL,16);
        fprintf(fp5,"H^%s^%06x^%06x\n",label,startDecimal,lengthInDecimal);
        assemblyListing(fp6,locctr,label,opcode,operand,"**");
        textRecordInitializer(locctr,text,&count);
    }
    while(!feof(fp1)){
        fscanf(fp1,"%s%s%s%s",locctr,label,opcode,operand);  
        if(!strcmp(opcode,"END")){
            textRecordWriting(fp5,&textlen,text);
            fprintf(fp5,"\nE^%06x",startDecimal);
            assemblyListing(fp6,locctr,label,opcode,operand,"**");
            break;
        }

        if(textlen>= MAXRECORD ){
            textRecordWriting(fp5,&textlen,text);
            if(!strcmp(opcode,"RESW") || !strcmp(opcode,"RESB")){
                assemblyListing(fp6,locctr,label,opcode,operand,"**");
                continue;
            }
            textRecordInitializer(locctr,text,&count);
        }
        if(!strcmp(opcode,"RESW") || !strcmp(opcode,"RESB")){
            assemblyListing(fp6,locctr,label,opcode,operand,"**");
            continue;
        }
        else if(!strcmp(opcode,"WORD")){
            sprintf(text+count,"^%06x",atoi(operand));
            assemblyListing(fp6,locctr,label,opcode,operand,text+count+1);
            count += 7; textlen++;
        }
        else if(!strcmp(opcode,"BYTE")){
            sprintf(text+count, "%s", "^");
            count++;
            byteLastIndex = strlen(operand)-2;
            char *formatSpecifier = (operand[0] == 'X') ? "%c" : "%x";
            int j =0;
            for(int i=2; i<= byteLastIndex; i++){
                sprintf(text+count,"%c",operand[i]);
                sprintf(byteConstant+j,formatSpecifier,operand[i]);
                count++;j++;
            }
            byteConstant[j]='\0';
            assemblyListing(fp6,locctr,label,opcode,operand,byteConstant);
            textlen++;
        }
        else{
            fp3 = fopen("C:\\Users\\User\\OneDrive\\Desktop\\pass2\\optab.txt","r");
            while(!feof(fp3)){
                fscanf(fp3,"%s\t%s\n",symbol,value);
                if(!strcmp(symbol,opcode)){
                    fp4 = fopen("C:\\Users\\User\\OneDrive\\Desktop\\pass2\\symtab.txt","r");
                    while (!feof(fp4)){
                        fscanf(fp4,"%s\t%s\n",symbol1,value1);
                        if(strcmp(symbol1,operand)==0){
                            sprintf(text+count,"^%s%s",value,value1);
                            assemblyListing(fp6,locctr,label,opcode,operand,text+count+1);
                            count += strlen(value) + strlen(value1) + 1;
                            textlen++;                            
                            break;
                        }
                    }
                    fclose(fp4);
                    break;
                }
            }
            fclose(fp3);
        }
    }
    fclose(fp1);    fclose(fp2);
    fclose(fp5);    fclose(fp6);
    printf("\nObject code successfully written to the file\n");
    printf("\nAssembly Listing\n\n");
    display("assemblyListing.txt");
    printf("\nObject Program\n\n");
    display("objectProgram.txt");
    return 0;
}*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void textRecordWriting(FILE *fp,int textlen,char *text){
    char inter[3];
    sprintf(inter, "%02x", (textlen*3));
    text[9] = inter[0]; text[10] = inter[1];
    fprintf(fp, "%s", text);
}
void display(char *fileName){
    FILE *fp = fopen(fileName,"r");
    char ch = fgetc(fp);
    while(ch != EOF){
        printf("%c",ch);
        ch = fgetc(fp);
    }    
    fclose(fp);
}
void passTwo(){
    FILE *fp1,*fp2,*fp3,*fp4,*fp5,*fp6;
    char locctr[10],label[10],opcode[10],operand[10]; 
    char symbol[10],address[10] ,mnemonic[10],machineCode[10]; 
    char text[100],pgLengthH[3];
    int textlen = 0,count; 
    fp1 = fopen("intermediate.txt","r");
    fp2 = fopen("length.txt" ,"r");
    fp3 = fopen("optab.txt","r");
    fp4 = fopen("symtab.txt","r");
    fp5 = fopen("objectProgram.txt","w");
    fp6 = fopen("assemblyListing.txt","w");
    fscanf(fp2,"%s",pgLengthH);
    fscanf(fp1,"%s%s%s%s",locctr,label,opcode,operand);
    int pgLengthD = strtol(pgLengthH ,NULL,16); 
    int stAddressD = strtol(locctr,NULL,16);
    if(!strcmp(opcode,"START")){
        fprintf(fp5,"H^%s^%06x^%06x\n",label,stAddressD,pgLengthD);
        fprintf(fp6,"%s\t%s\t%s\t%s\t%s\n",locctr,label,opcode,operand,"**");
        sprintf(text,"T^%06x^",stAddressD);
        count = 11;
    }
    while(!feof(fp1)){
        fscanf(fp1,"%s%s%s%s",locctr,label,opcode,operand);  
        if(!strcmp(opcode,"END")){
            textRecordWriting(fp5,textlen,text);
            fprintf(fp5,"\nE^%06x",stAddressD);
            fprintf(fp6,"%s\t%s\t%s\t%s\t%s\n",locctr,label,opcode,operand,"**");
            break;
        }
        if(!strcmp(opcode,"RESW") || !strcmp(opcode,"RESB"))
            fprintf(fp6,"%s\t%s\t%s\t%s\t%s\n",locctr,label,opcode,operand,"**");
        else if(!strcmp(opcode,"WORD")){
            sprintf(text+count,"^%06x",atoi(operand));
            fprintf(fp6,"%s\t%s\t%s\t%s\t%s\n",locctr,label,opcode,operand,text+count+1);
            count += 7; textlen++;
        }
        else if (!strcmp(opcode, "BYTE")) {
            sprintf(text + count++, "%s", "^");
            char *formatSpecifier = (operand[0] == 'X') ? "%c" : "%x";
            int increment = (operand[0] == 'X') ? 1 : 2;
            int byteStart = count;
            for (int i = 2; i < strlen(operand) - 1; i++, count += increment)
                sprintf(text + count, formatSpecifier, operand[i]);
            fprintf(fp6, "%s\t%s\t%s\t%s\t%s\n", locctr, label, opcode, operand, text + byteStart);
            textlen++;
        }
        else{
            rewind(fp3);
            while(!feof(fp3)){
                fscanf(fp3,"%s%s", mnemonic,machineCode);
                if(!strcmp(mnemonic,opcode)){
                    rewind(fp4);
                    while (!feof(fp4)){
                        fscanf(fp4,"%s\t%s\n",symbol,address);
                        if(!strcmp(symbol,operand)){
                            sprintf(text+count,"^%s%s",machineCode,address);
                            fprintf(fp6,"%s\t%s\t%s\t%s\t%s\n",locctr,label,opcode,operand,text+count+1);
                            count +=7; textlen++; break;
                        }
                    } break;
                }
            }
        }
    }
    fclose(fp1);fclose(fp2);fclose(fp3);fclose(fp4);fclose(fp5);fclose(fp6);
}
int main(){
    passTwo();
    printf("Assembly Listing\n"); display("assemblyListing.txt");
    printf("\nObject Program\n");   display("objectProgram.txt");
}
/*
input
-----------------------------------------------------------
intermediate.txt
2000		SAMPLE	START	2000
2000		**		LDA		FIVE
2003		**		ADD		CONST
2006		**		STA		ALPHA
2009		FIVE	WORD	5
200c		CONST	RESW	1
200f		ALPHA	RESW	2
2015		EOF		BYTE	C'EOF'
2018		HEXF1	BYTE	X'F1'
2019		**		END		2000

length.txt 
19

symtab.txt
FIVE	2009
CONST	200c
ALPHA	200f
EOF	    2015
HEXF1	2018

optab.txt
LDA 00
STA 0C
ADD 18

output
---------------------------------------
Assembly Listing
2000    SAMPLE  START   2000    **
2000    **      LDA     FIVE    002009
2003    **      ADD     CONST   18200c
2006    **      STA     ALPHA   0C200f
2009    FIVE    WORD    5       000005
200c    CONST   RESW    1       **
200f    ALPHA   RESW    2       **
2015    EOF     BYTE    C'EOF'  454f46
2018    HEXF1   BYTE    X'F1'   F1
2019    **      END     2000    **

Object Program
H^SAMPLE^002000^000019
T^002000^12^002009^18200c^0C200f^000005^454f46^F1
E^002000
*/

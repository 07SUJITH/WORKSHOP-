 //pass2 of two pass assembler

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
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
    FILE *fp1,*fp2,*fp3,*fp4,*fp5;
    char label[10],opcode[10],operand[10],symbol[20],value[10],symbol1[20],value1[10],locctr[10];
    char text[68], inter[3];
    int length=0,start=0,i, count, textlen;
    fp1 = fopen("intermediate.txt","r");
    fp2 = fopen("length.txt","r");
    fp5 = fopen("objectcode.txt","w");
    fscanf(fp2,"%d",&length);
    fscanf(fp1,"%s%s%s%s",locctr,label,opcode,operand);
    if(strcmp(opcode,"START") == 0)
    {
        start = atoi(operand);
        fprintf(fp5,"H^%s^%06d^%06d\n",label,start,length);
        sprintf(text+count,"T^%06d^",start);
        count += 11;
        
    }
    while(!feof(fp1))
    {
        fscanf(fp1,"%s%s%s%s\n",locctr,label,opcode,operand);
        printf("%s%s%s%s\n",locctr,label,opcode,operand);
        if(strcmp(opcode,"END")==0)
        {
        	  sprintf(inter, "%d", (textlen*3));
        	  text[9] = inter[0]; text[10] = inter[1];
        	  fprintf(fp5, "%s", text);
            fprintf(fp5,"\nE^%06d",start);
            break;
        }
        else if((strcmp(opcode,"RESW")==0)||(strcmp(opcode,"RESB")==0))
        {
            continue;
        }
        else if(strcmp(opcode,"WORD")==0)
        {
            sprintf(text+count,"^%06d",atoi(operand));
            count += 7; textlen += 1;
        }
        else if(strcmp(opcode,"BYTE")==0)
        {
            sprintf(text+count, "%s", "^");
            count += 1;
            if(operand[0]=='X')
            {
                for(i=2;i<(strlen(operand)-1);i++)
                {
                    sprintf(text+count,"%c",operand[i]);
                    count += 1;
                }
            }
            else if(operand[0]=='C')
            {
                for(i=2;i<(strlen(operand)-1);i++)
                {
                    sprintf(text+count,"%X",operand[i]);
                    count += 1;
                }
            }
            textlen += 1;
        }
        else
        {
            fp3 = fopen("optab.txt","r");
            while(!feof(fp3))
            {
                fscanf(fp3,"%s\t%s\n",symbol,value);
                if(strcmp(symbol,opcode)==0)
                {
                    fp4 = fopen("symtab.txt","r");
                    while (!feof(fp4))
                    {
                        fscanf(fp4,"%s\t%s\n",symbol1,value1);
                        if(strcmp(symbol1,operand)==0)
                        {
                            sprintf(text+count,"^%s%s",value,value1);
                            count += strlen(value) + strlen(value1);
                            textlen += 1;
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
    printf("\nOBJECT CODE SUCESSFULLY WRITTEN TO THE FILE\n");
    fclose(fp1);
    fclose(fp2);
    fclose(fp5);
}



#include <stdio.h>
#include <ctype.h>
#include <string.h>

int m = 0, i, j, flag = 0;
char c, str[50] = " ", str1[50] = " ";
char mac[10][10];

int main()
{
    FILE *fpm = fopen("macro.txt", "r");
    FILE *fpi = fopen("minput.txt", "r");
    FILE *fpo = fopen("moutput.txt", "w");

    while (!feof(fpm))
    {
        fgets(str, 50, fpm);
        char *s1 = strtok(str, " ");
        char *s2 = strtok(NULL, " ");
        if (strcmp(s1, "MACRO") == 0)
        {
            strcpy(mac[m], s2);
            m++;
        }
    }

    fgets(str, 50, fpi);
    while (!feof(fpi))
    {
        flag = 0;
        strcpy(str1, str);

        for (i = 0; i < m; i++)
        {
            if (strcmp(str1, mac[i]) == 0)
            {
                rewind(fpm);
                while (!feof(fpm))
                {
                    fgets(str, 50, fpm);
                    char *s2 = strtok(str, " ");
                    char *s3 = strtok(NULL, " ");
                    if (strcmp(s2, "MACRO") == 0 && strcmp(s3, str1) == 0)
                    {
                        fgets(str, 50, fpm);
                        char s4[5];
                        strncpy(s4, str, 4);
                        s4[4] = '\0';

                        while (strcmp(s4, "MEND") != 0)
                        {
                            fprintf(fpo, "%s", str);
                            printf("%s", str);
                            fgets(str, 50, fpm);
                            strncpy(s4, str, 4);
                            s4[4] = '\0';
                        }
                    }
                }
                flag = 1;
                break;
            }
        }

        if (flag == 0)
        {
            fprintf(fpo, "%s", str);
            printf("%s", str);
        }
        fgets(str, 50, fpi);
    }

    fclose(fpm);
    fclose(fpi);
    fclose(fpo);

    return 0;
}
/*
macro.txt

MACRO ADD1
MOV A,B
ADD C
MEND
MACRO SUB1
STORE C
MEND

 

 

minput.txt

MOV B,10
MOV C,20
ADD1
MUL C
SUB1
END
  */

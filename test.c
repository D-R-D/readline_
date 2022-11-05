#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *readLine(char *prom);

void main(void)
{
    for(;;)
    {
        char *buffer = readLine("> ");
        printf("result : %s\n",buffer);
        if(strcmp(buffer,"break") == 0)
        {
            break;
        }
    }
}

char *readLine(char *prom)
{
    printf("%s" , prom);
    int ressize = 0;
    char *word[1];
    char *result = (char*)calloc(1,10);
    char *temp = (char*)calloc(1,10);

    for(;;)
    {
        if(fgets(word,sizeof(word),stdin) != NULL)
        {
            ressize = (strlen(result) + strlen(word)) * sizeof(char);
            temp = (char*)realloc(result , ressize);
            strcat(temp,word);
            result = (char*)realloc(temp,ressize);

            if(result != temp)
            {
                printf("free!!\n");
                printf("%s\n",temp);

                free(temp);
            }

            printf("fs : %s\n",temp);

            size_t length = strlen(result);
            if(result[length - 1] == '\n') 
            {
                result[--length] = '\0';
                return result;
            }
        }
    }
    return "none";
}
//                    f
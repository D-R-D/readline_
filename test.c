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
    char *result = (char*)calloc(1,sizeof(char));
    char *temp = (char*)calloc(1,sizeof(char));

    for(;;)
    {
        if(fgets(word,sizeof(word[0]),stdin) != NULL)
        {
            ressize = (strlen(result) + strlen(word)) * sizeof(char);

            for(;;){
                temp = (char*)realloc(result , ressize);
                if(temp != NULL){
                    break;
                }
            }

            strcat(temp,word);

            for(;;){
                result = (char*)realloc(temp,ressize);
                if(result != NULL){
                    break;
                }
            }

            size_t length = strlen(result);
            if(result[length - 1] == '\n') 
            {
                result[--length] = '\0';
                return result;
            }
        }
    }
    return NULL;
}
//                    f                    f                    f                    f                    f
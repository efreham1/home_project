#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *print(void *argument)
{
    printf("%s\n", (char *) argument);
}

int main(void)
{
    pthread_t thread_id;

    char *string = calloc(11, 1);
    char *string1 = "abcdef";
    char *string2 = "fedcba";
    for (size_t i = 0; i < 7; i++)
    {
        string[i] = string1[i];
    }
    

    pthread_create(&thread_id, NULL, print, string);

    for (size_t i = 0; i < 7; i++)
    {
        string[i] = string2[i];
    }

    printf("Hello!\n");
    printf("Hello!\n");
    printf("Hello!\n");

    pthread_join(thread_id, NULL);
}
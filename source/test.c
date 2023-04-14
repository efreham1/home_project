#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *address()
{

    return __builtin_frame_address(0);
}

int main(void)
{
    //void *start = address();
    int i = 3;
    int j = 5;
    int k;
    int l;
    int m;
    int n;
    int o;
    int p;
    void *ptr = malloc(8);
    printf("%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n", NULL, &i, &j, &k, &l, &m, &n, &o, &p, &ptr, NULL);
}
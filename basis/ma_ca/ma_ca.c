#include <stdio.h>
#include <stdlib.h>
int main(void){
    int i;
    int *a = malloc(5*sizeof(int));
    int *b = calloc(5,sizeof(int));
    for(i=0;i<5;i++){
        printf("%d,%d\n",*(a+i),*(b+i));
    }
    free(a);
    free(b);
    return 0;
}
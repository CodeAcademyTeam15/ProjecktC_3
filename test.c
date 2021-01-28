#include <stdio.h>
#include <ctype.h>

int main(void){

    char c;
    printf("add something");
    scanf("%c", &c);
    if(isalpha(c)){
        printf("test yes\n");
    } else {
        printf("test no\n");
    }

    return 0;
}
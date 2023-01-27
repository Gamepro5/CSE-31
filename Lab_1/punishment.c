#include <stdio.h>
#include <stdlib.h>
int main( int argc, char *argv[] )  {

    int a, b;
    printf("Enter the number of repetitions for the punishment phrase: ");
    scanf("%d", &a);
    fflush(stdout);
    if (a==0) {
        return 0;
    }
    while (a < 1) {
        a = 0;
        printf("You entered an invalid value for the number of repetitions! Try again: ");
        scanf("%d", &a);
        fflush(stdout);
    };
    printf("Enter the number of repetitions for the punishment phrase: ");
    scanf("%d", &b);
    fflush(stdout);
    while (b < 1 || b > a) {
        b = 0;
        printf("You entered an invalid value for the number of repetitions! Try again: ");
        scanf("%d", &b);
        fflush(stdout);
    };
    for (int i=0; i<a; i++) {
        if (i == b-1) {
            printf("Coding in C is fun end interesting!\n");
        } else {
            printf("Coding in C is fun and interesting!\n");
        };
    };
    return 0; 
} 
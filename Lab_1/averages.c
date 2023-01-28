#include <stdio.h>
#include <stdlib.h>
int main( int argc, char *argv[] )  {

    int input_index=1;
    float inpt, inputsum;

    printf("Enter the 1st number: ");
    scanf("%f", &inpt);
    fflush(stdout);
    if (inpt != 0) {
        inputsum += inpt;
        input_index += 1;
    }
    while (inpt != 0) {
        inpt = 0;
        if (input_index == 2) {
            printf("Enter the 2nd number: ");
        } else if (input_index == 3) {
            printf("Enter the 3rd number: ");
        } else {
            printf("Enter the %ith number: ", input_index);
        }
        scanf("%f", &inpt);
        fflush(stdout);
        if (inpt != 0) {
            inputsum += inpt;
            input_index += 1;
        };
    };
    input_index -= 1;
    if (inputsum == 0) {
        printf("There is no average to compute.\n");
    } else {
        float result = (inputsum / (float) input_index);
        if ((int)inputsum % 2 == 0) { //is even
            printf("Average of inputs whose digits sum up to an even number: %i\n", (int)result);
        } else { // is odd
            printf("Average of inputs whose digits sum up to an odd number: %f\n", (float)result);
        }
    }
    return 0; 
} 
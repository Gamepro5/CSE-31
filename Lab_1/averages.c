#include <stdio.h>
#include <stdlib.h>
int main( int argc, char *argv[] )  {

    int input_index=1;
    float inpt, oddinputsum, eveninputsum, oddinputcount, eveninputcount;

    printf("Enter the 1st number: ");
    scanf("%f", &inpt);
    fflush(stdout);
    if (inpt != 0) {
            int tempsum = 0;
            int remaining_input = inpt;
            while (remaining_input != 0) {
                int temp = remaining_input % 10;
                remaining_input = (remaining_input - temp)/10;
                tempsum += temp;
            }
            printf("%i\n",tempsum);
            if (tempsum % 2 == 0) {
                eveninputsum += inpt;
                eveninputcount += 1;
            } else {
                oddinputsum += inpt;
                oddinputcount += 1;
            }
            input_index += 1;
        };
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
            int tempsum = 0;
            int remaining_input = inpt;
            while (remaining_input != 0) {
                int temp = remaining_input % 10;
                remaining_input = (remaining_input - temp)/10;
                tempsum += temp;
            }
            printf("%i\n",tempsum);
            if (tempsum % 2 == 0) {
                eveninputsum += inpt;
                eveninputcount += 1;
            } else {
                oddinputsum += inpt;
                oddinputcount += 1;
            }
            input_index += 1;
        };
    };
    input_index -= 1;
    if (eveninputsum == 0 && oddinputsum == 0) {
        printf("There is no average to compute.\n");
    } else {
        if (eveninputsum != 0) {
            float result = (eveninputsum / (float) eveninputcount);
            printf("Average of inputs whose digits sum up to an even number: %f\n", result);
        }
        if (oddinputsum != 0) {
            float result = (oddinputsum / (float) oddinputcount);
            printf("Average of inputs whose digits sum up to an odd number: %f\n", result);
        }
       
    }
    
    return 0; 
} 
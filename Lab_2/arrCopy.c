#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int size; // Variable to record size of original array arr
int evenCount = 0, oddCount = 0; // Variables to record sizes of new arrays arr_even and arr_odd
int *arr; // Dynamically allocated original array with #elements = size
int *arr_even;  // Dynamically allocated array with #elements = #even elements in arr (evenCount)
int *arr_odd;   // Dynamically allocated array with #elements = #odd elements in arr (oddCount)
char *str1 = "Original array's contents: ";
char *str2 = "Contents of new array containing even elements from original: ";
char *str3 = "Contents of new array containing odd elements from original: ";

// DO NOT change the definition of the printArr function when it comes to 
// adding/removing/modifying the function parameters, or changing its return 
// type. 
void printArr(int *a, int size, char *prompt){
    printf(prompt);
    for (int i=0;i<size;i++) {
        //printf("%lu",sizeof(*a/sizeof(int)));
        printf("%i ", *(a+i));
    }
    if (size == 0) {
        printf("empty");
    }
    printf("\n");
	// Your code here
}

// DO NOT change the definition of the arrCopy function when it comes to 
// adding/removing/modifying the function parameters, or changing its return 
// type. 
void arrCopy(){
	// Your code here
    int oddfilled,evenfilled = 0;
    for (int i=0;i<size;i++) {
        //printf("%i\n", *(arr+i));
        if (*(arr+i) % 2 == 0) {
            *(arr_even+evenfilled) = *(arr+i);
            evenfilled++;
        } else {
            *(arr_odd+oddfilled) = *(arr+i);
            oddfilled++;
        }
    }
}

int main(){
    int i;
    printf("Enter the size of array you wish to create: ");
    scanf("%d", &size);

    // Dynamically allocate memory for arr (of appropriate size)
    arr = (int*) malloc(size*sizeof(int));
    // Your code here

    // Ask user to input content of arr and compute evenCount and oddCount
    fflush(stdin);
    for (int i=0;i<size;i++) {
        printf("Enter array element #%i: ", i+1);
        int inpt;
        scanf("%d", &inpt);
        fflush(stdin);
        if (inpt % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }
        
        *(arr+i) = inpt;
    }
    printf("\n");
	// Your code here

    // Dynamically allocate memory for arr_even and arr_odd (of appropriate size)
    arr_even = (int*) malloc(evenCount*sizeof(int));
    arr_odd = (int*) malloc(oddCount*sizeof(int));
    
    // Your code here    
	
/*************** YOU MUST NOT MAKE CHANGES BEYOND THIS LINE! ***********/
	
	// Print original array
    printArr(arr, size, str1);

	/// Copy even elements of arr into arr_even and odd elements into arr_odd
    arrCopy();

    // Print new array containing even elements from arr
    printArr(arr_even, evenCount, str2);

    // Print new array containing odd elements from arr
    printArr(arr_odd, oddCount, str3);

    printf("\n");

    return 0;
}
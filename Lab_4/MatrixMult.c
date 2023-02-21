
#include <stdio.h>
#include <stdlib.h>

int** matMult(int **a, int **b, int size) {
	// (4) Implement your matrix multiplication here. You will need to create a new matrix to store the product.
	int **matC = (int**)malloc(size * sizeof(int*));

	for (int i=0;i<size;i++) {
		int* temp = (int*) malloc (size * sizeof(int));
		*(matC+i) = temp;
		for (int j=0;j<size;j++) {
			*( *(matC + i) + j) = *( *(a + i) + j) * *( *(b + i) + j);
		}
	}
	return matC;
}

void printArray(int ** array, int size) {
    // (5) Implement your printArr here:
	printf("%i%s%i%s\n\n", size, "x", size, " 2D Array:");
	for (int i=0;i<size;i++) {
		//printf("%s%i%s\n", "Array #", i, " initialized. Elements are:");
		for (int j=0;j<size;j++) {
			printf("%i%s", *( *(array + i) + j), " ");
		}
		printf("\n");
	}
	printf("\n\n");
}

int main() {
	int n = 5;
	int **matA, **matB, **matC;
	// (1) Define 2 (n x n) arrays (matrices). 
	matA = (int**)malloc(n * sizeof(int*));

	for (int i=0;i<n;i++) {
		int* temp = (int*) malloc (n * sizeof(int));
		*(matA+i) = temp;
		//printf("%s%i%s\n", "Array #", i, " initialized. Elements are:");
		for (int j=0;j<n;j++) {
			*( *(matA + i) + j) = 0;
			//printf("%i%s%i\n", j, ": ", *( *(matA + i) + j));
		}
	}
	matB = (int**)malloc(n * sizeof(int*));

	for (int i=0;i<n;i++) {
		int* temp = (int*) malloc (n * sizeof(int));
		*(matB+i) = temp;
		//printf("%s%i%s\n", "Array #", i, " initialized. Elements are:");
		for (int j=0;j<n;j++) {
			*( *(matB + i) + j) = 0;
			//printf("%i%s%i\n", j, ": ", *( *(matB + i) + j));
		}
	}


	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			if (i==j) {
				*( *(matA + i) + j) = i+1;
				*( *(matB + i) + j) = i+1;
			}
		}
	}
	// (3) Call printArray to print out the 2 arrays here.
	printf("Matrix A:\n");
	printArray(matA, n);
	printf("Matrix B:\n");
	printArray(matB, n);
	
	// (5) Call matMult to multiply the 2 arrays here.
	matC = matMult(matA,matB,n);
	
	// (6) Call printArray to print out resulting array here.
	printf("Matrix C:\n");
	printArray(matC, n);

    return 0;
}
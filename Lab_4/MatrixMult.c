
#include <stdio.h>
#include <stdlib.h>

int** matMult(int **a, int **b, int size) {
	// (4) Implement your matrix multiplication here. You will need to create a new matrix to store the product.
	int **matC = (int**)malloc(size * sizeof(int*));

	for (int i=0;i<size;i++) {
		int* temp = (int*) malloc (size * sizeof(int));
		*(matC+i) = temp;
		for (int j=0;j<size;j++) {
			for (int k=0;k<size;k++) { //i and j is a constant in this for loop. we only want to go from increment k and replace the j index with k for the first matrix, and replace the i index with k for the second matrix. otherwise we would be going horizontally and we would be starting at the i or j index which isn't zero.
				*( *(matC + i) + j) += *( *(a + i) + k)   *   *( *(b + k) + j);
			}
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
	int n = 3;
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
			*( *(matA + i) + j) = i+1;
			*( *(matB + i) + j) = i+1;
			//if (i==j) {
			//	*( *(matA + i) + j) = i+1;
			//	*( *(matB + i) + j) = i+1;
			//}
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
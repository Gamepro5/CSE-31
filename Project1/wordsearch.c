#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Declarations of the two functions you will implement
// Feel free to declare any helper functions or global variables
void printPuzzle(char** arr);
void searchPuzzle(char** arr, char* word);
int bSize;
int** returnMatrix;

// Main function, DO NOT MODIFY 	
int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <puzzle file name>\n", argv[0]);
        return 2;
    }
    int i, j;
    FILE *fptr;

    // Open file for reading puzzle
    fptr = fopen(argv[1], "r");
    if (fptr == NULL) {
        printf("Cannot Open Puzzle File!\n");
        return 0;
    }

    // Read the size of the puzzle block
    fscanf(fptr, "%d\n", &bSize);
    
    // Allocate space for the puzzle block and the word to be searched
    char **block = (char**)malloc(bSize * sizeof(char*));
    char *word = (char*)malloc(20 * sizeof(char));

    // Read puzzle block into 2D arrays
    for(i = 0; i < bSize; i++) {
        *(block + i) = (char*)malloc(bSize * sizeof(char));
        for (j = 0; j < bSize - 1; ++j) {
            fscanf(fptr, "%c ", *(block + i) + j);            
        }
        fscanf(fptr, "%c \n", *(block + i) + j);
    }
    fclose(fptr);

    // Print out original puzzle grid
    printf("\nPrinting puzzle before search:\n");
    printPuzzle(block);

    printf("Enter the word to search: ");
    scanf("%s", word);
    /*
    // Print out original puzzle grid
    printf("\nPrinting puzzle before search:\n");
    printPuzzle(block);
    */
    // Call searchPuzzle to the word in the puzzle
    searchPuzzle(block, word);
    
    return 0;
};

void printPuzzle(char** arr) {
	// This function will print out the complete puzzle grid (arr). 
    // It must produce the output in the SAME format as the samples 
    // in the instructions.
    // Your implementation here...
    printf("%i%s%i%s\n\n", bSize, "x", bSize, " puzzle:");
	for (int i=0;i<bSize;i++) {
		for (int j=0;j<bSize;j++) {
			printf("%c%s", *( *(arr + i) + j), " ");
		}
		printf("\n");
	}
	printf("\n\n");

};

void printMatrix(int** arr) {
	// This function will print out the complete puzzle grid (arr). 
    // It must produce the output in the SAME format as the samples 
    // in the instructions.
    // Your implementation here...
    printf("%i%s%i%s\n\n", bSize, "x", bSize, " puzzle:");
	for (int i=0;i<bSize;i++) {
		for (int j=0;j<bSize;j++) {
			printf("%i%s", *( *(arr + i) + j), " ");
		}
		printf("\n");
	}
	printf("\n\n");

};

void resetReturnMatrix() {
    returnMatrix = (int**)malloc(bSize * sizeof(int*));
    for (int i=0;i<bSize;i++) {
		int* temp = (int*) malloc (bSize * sizeof(int));
		*(returnMatrix+i) = temp;
		for (int j=0;j<bSize;j++) {
			*( *(returnMatrix + i) + j) = 0;
		}
	}
}

struct coordinate {
    int x;
    int y;
};

char getIndex(char** arr, int x, int y) {
    return *(*(arr + y) + x);
};
char getLetter(char* word, int index) {
    return (toupper(*(word+index)));
};

int findAdjacentWord(char** arr, char* word, int currentLetterIndex, struct coordinate _pivot, int* wordfound) {
                struct coordinate pivot = _pivot;
                printMatrix(returnMatrix);
                printf("currentLetterIndex: %i\n", currentLetterIndex);
                printf("strlen word: %li\n", strlen(word));
                if (currentLetterIndex >= strlen(word)) {
                    *wordfound = 1;
                    return 1;
                } else {
                    if ((pivot.x-1 >= 0) && (pivot.y+1 < bSize) && getLetter(word, currentLetterIndex) == getIndex(arr, pivot.x-1, pivot.y+1)) { //top left
                        pivot.x = pivot.x-1;
                        pivot.y = pivot.y+1;
                        *(*(returnMatrix + pivot.y) + pivot.x) = currentLetterIndex+1;
                        findAdjacentWord(arr, word, currentLetterIndex+1, pivot, wordfound);
                    } else if ((pivot.x-1 >= 0) && getLetter(word, currentLetterIndex) == getIndex(arr, pivot.x-1, pivot.y)) { //left
                        pivot.x = pivot.x-1;
                        *(*(returnMatrix + pivot.y) + pivot.x) = currentLetterIndex+1;
                        findAdjacentWord(arr, word, currentLetterIndex+1, pivot,wordfound);

                    } else if ((pivot.x-1 >= 0) && (pivot.y-1 >= 0) && getLetter(word, currentLetterIndex) == getIndex(arr, pivot.x-1, pivot.y-1)) { //bottom left
                        pivot.x = pivot.x-1;
                        pivot.y = pivot.y-1;
                        *(*(returnMatrix + pivot.y) + pivot.x) = currentLetterIndex+1;
                        findAdjacentWord(arr, word, currentLetterIndex+1, pivot,wordfound);

                    } else if ((pivot.y-1 >= 0) && getLetter(word, currentLetterIndex) == getIndex(arr, pivot.x, pivot.y-1)) { //bottom
                        pivot.y = pivot.y-1;
                        *(*(returnMatrix + pivot.y) + pivot.x) = currentLetterIndex+1;
                        findAdjacentWord(arr, word, currentLetterIndex+1, pivot,wordfound);

                    } else if ((pivot.x+1 < bSize) && (pivot.y-1 >= 0) && getLetter(word, currentLetterIndex) == getIndex(arr, pivot.x+1, pivot.y-1)) { //bottom right
                        pivot.x = pivot.x+1;
                        pivot.y = pivot.y-1;
                        *(*(returnMatrix + pivot.y) + pivot.x) = currentLetterIndex+1;
                        findAdjacentWord(arr, word, currentLetterIndex+1, pivot,wordfound);

                    } else if ((pivot.x+1 < bSize) && getLetter(word, currentLetterIndex) == getIndex(arr, pivot.x+1, pivot.y)) { //right
                        pivot.x = pivot.x+1;
                        *(*(returnMatrix + pivot.y) + pivot.x) = currentLetterIndex+1;
                        findAdjacentWord(arr, word, currentLetterIndex+1, pivot,wordfound);

                    } else if ((pivot.x+1 < bSize) && (pivot.y+1 < bSize) && getLetter(word, currentLetterIndex) == getIndex(arr, pivot.x+1, pivot.y+1)) { //top right
                        pivot.x = pivot.x+1;
                        pivot.y = pivot.y+1;
                        *(*(returnMatrix + pivot.y) + pivot.x) = currentLetterIndex+1;
                        findAdjacentWord(arr, word, currentLetterIndex+1, pivot,wordfound);

                    } else if ((pivot.y+1 < bSize) && getLetter(word, currentLetterIndex) == getIndex(arr, pivot.x, pivot.y+1)) { //top
                        pivot.y = pivot.y+1;
                        *(*(returnMatrix + pivot.y) + pivot.x) = currentLetterIndex+1;
                        findAdjacentWord(arr, word, currentLetterIndex+1, pivot,wordfound);
                    } else {
                        resetReturnMatrix();
                        *wordfound = 0;
                    }
                }
}


void searchPuzzle(char** arr, char* word) {
    resetReturnMatrix();
    // This function checks if arr contains the search word. If the 
    // word appears in arr, it will print out a message and the path 
    // as shown in the sample runs. If not found, it will print a 
    // different message as shown in the sample runs.
    // Your implementation here...
    int wordFoundBool = 0;
    for (int i=0;i<bSize;i++) {
		for (int j=0;j<bSize;j++) {
			if (*( *(arr + i) + j) == toupper(*(word+0))) { //we found a potential start to our word trace.
                struct coordinate pivot;
                pivot.x = j;
                pivot.y = i;

                int currentLetterIndex = 1;
                *(*(returnMatrix + pivot.y) + pivot.x) = 1;
                findAdjacentWord(arr, word, currentLetterIndex, pivot, &wordFoundBool);
                if (wordFoundBool == 1) {
                    printMatrix(returnMatrix);
                    return;
                }


                // TODO: DISCUSS WHY MY METHOD CANNOT FIND THE WORD "MLZELOA" in word search one.


            }
            
		}
		printf("\n");
        
	}
    if (wordFoundBool) {
        printMatrix(returnMatrix);
    } else {
        printf("Word not found!");
    }
}

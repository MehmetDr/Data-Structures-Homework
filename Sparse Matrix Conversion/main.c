#include <stdlib.h>
#include <stdio.h>

void convertToSparse(int matrix[4][5], int r, int c) {
    int size = 0;
    int i,j;
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            if (matrix[i][j] != 0) size++;

    int sparseMatrix[size + 1][3];
    sparseMatrix[0][0] = r;
    sparseMatrix[0][1] = c;
    sparseMatrix[0][2] = size;

    int k = 1;
    
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            if (matrix[i][j] != 0) {
                sparseMatrix[k][0] = i;
                sparseMatrix[k][1] = j;
                sparseMatrix[k][2] = matrix[i][j];
                k++;
            }
        }
    }

    printf("Sparse Matrix (Triplet Form):\nRow\tCol\tValue\n");
    for (i = 0; i <= size; i++) {
        printf("%d\t%d\t%d\n", sparseMatrix[i][0], sparseMatrix[i][1], sparseMatrix[i][2]);
    }
}

int main() {
    int mat[4][5] = {{0, 0, 3, 0, 4}, {0, 0, 5, 7, 0}, {0, 0, 0, 0, 0}, {0, 2, 6, 0, 0}};
    convertToSparse(mat, 4, 5);
    return 0;
}

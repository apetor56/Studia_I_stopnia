#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[]) {
    if(argc != 2) {
        printf("Wrong number of arguments\nEnter martix size (one number)\n");
        exit(1);
    }

    int N = atoi(argv[1]);
    printf("%d\n\n", N);

    int **matrix = (int**)(malloc(N * sizeof(int*)));
    for(int i = 0; i < N; i++)
        matrix[i] = (int*)(malloc(N * sizeof(int)));

    for(int i = 0; i < N; i++)
        printf("1 ");
    printf("\n\n");

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(i == j)
                matrix[i][j] = 4;

            else if(i != 0 && i == j + 1)
                matrix[i][j] = 1;

            else if(j != 0 && i + 1 == j)
                matrix[i][j] = 1;

            else if(i >= 4 && i == j + 4)
                matrix[i][j] = 1;

            else if(j >= 4 && i + 4== j)
                matrix[i][j] = 1;
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < N; i++)
        free(matrix[i]);

    free(matrix);
}
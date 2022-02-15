#include <stdio.h>

int main() {
    int N = 510;
    double x, y[3];

    printf("%d\n\n", N);

    for(int i = 0; i < 510; i++) {
        for(int j = i; j < 512; j++) {
            scanf("%lf %lf", &x, &y[j % 3]);
        }
        printf("%lf ", y[0] - 2 * y[1] + y[2]);
    }
    printf("\n");

    int **matrix = (int**)(malloc(N * sizeof(int*)));
    for(int i = 0; i < N; i++)
        matrix[i] = (int*)(malloc(N * sizeof(int)));
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(i == j)
                matrix[i][j] = 4;

            else if(i != 0 && i == j + 1)
                matrix[i][j] = 1;

            else if(j != 0 && i + 1 == j)
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
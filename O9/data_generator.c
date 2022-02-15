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

    double x = -7.0/8;
    double h = 0.25;
    double *f = (double*)malloc((N + 2) * sizeof(double));
    for(int i = 0; i < N + 2; i++) {
        f[i] = 1.0 / (1 + 5 * x * x);
        x += h;
    }

    double vector_value = 0.0;
    for(int i = 1; i < N + 1; i++) {
        vector_value = (6 / (h * h)) * (f[i - 1] - 2 * f[i] + f[i + 1]);
        printf("%.15lf ", vector_value);
    }
    printf("\n\n");

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
    free(f);
}
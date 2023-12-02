#include <stdio.h>
#include <math.h>
#include "operations.h"

Vector e1, e2;

double first_eigenvalue(Matrix A) {
    Vector y = init_vector();
    gsl_vector_set(y, 0, 1);

    Vector z;

    for(int i = 0; i < 10000; i++) {
        z = copy_vector(matrix_vector_product(A, y));
        y = copy_vector(z);
        scale(y, (double)1 / norm(z));
    }

    e1 = copy_vector(y);
    return norm(z);
}

double second_eigenvalue(Matrix A) {
    Vector y = init_vector();
    Vector e = copy_vector(e1);

    gsl_vector_set(y, 0, 1);

    Vector z;
    Vector tmp;

    for(int i = 0; i < 10000; i++) {
        z = copy_vector(matrix_vector_product(A, y));
    
        tmp = copy_vector(e);
        scale(tmp, dot_product(e, z));
        z = sub(z, tmp);

        y = copy_vector(z);
        scale(y, (double)1 / norm(z));
    }

    e2 = copy_vector(y);
    return norm(z);
}

int main() {
    N = 6;
    Matrix A = init_matrix();
    int a, b;
    char o;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            scanf("%d %c %d", &a, &o, &b);
            gsl_matrix_set(A, i, j, (double)a / b);
        }
    }

    double eigen1 = first_eigenvalue(A);
    double eigen2 = second_eigenvalue(A);
    printf("%lf\n", eigen1);
    printf("%lf\n\n", eigen2);

    print_vector(e1);
    printf("\n");
    print_vector(e2);

    // Matrix A1 = copy_matrix(A);
    // for(int i = 0; i < N; i++)
    //     gsl_matrix_set(A1, i, i, gsl_matrix_get(A1, i, i) - eigen1);
    
    // FILE *file1 = fopen("input1.txt", "w");
    // fprintf(file1, "%d\n\n", N);

    // for(int i = 0; i < N; i++)
    //     fprintf(file1, "0 ");
    // fprintf(file1, "\n\n");

    // for(int i = 0; i < N; i++) {
    //     for(int j = 0; j < N; j++) {
    //         fprintf(file1, "%lf ", gsl_matrix_get(A1, i, j));
    //     }
    //     fprintf(file1, "\n");
    // }
    

    // Matrix A2 = copy_matrix(A);
    // for(int i = 0; i < N; i++)
    //     gsl_matrix_set(A2, i, i, gsl_matrix_get(A2, i, i) - eigen2);

    // FILE *file2 = fopen("input2.txt", "w");
    // fprintf(file2, "%d\n\n", N);

    // for(int i = 0; i < N; i++)
    //     fprintf(file2, "0 ");
    // fprintf(file2, "\n\n");

    // for(int i = 0; i < N; i++) {
    //     for(int j = 0; j < N; j++) {
    //         fprintf(file2, "%lf ", gsl_matrix_get(A2, i, j));
    //     }
    //     fprintf(file2, "\n");
    // }
}
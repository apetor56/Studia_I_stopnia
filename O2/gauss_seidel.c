#include "operations.h"

Vector gauss_seidel(Matrix A, Vector b) {
    const int K = 100;
    Vector x;
    Vector x_prev = init_vector();

    for(int k = 0; k < K; k++) {
        x = init_vector();
        for(int i = 0; i < N; i++) {
            double sum1 = 0;
            double sum2 = 0;

            for(int j = 0; j < i; j++)
                sum1 += gsl_matrix_get(A, i, j) * gsl_vector_get(x, j);
            
            for(int j = i + 1; j < N; j++) 
                sum2 += gsl_matrix_get(A, i, j) * gsl_vector_get(x_prev, j);
            
            double result = (gsl_vector_get(b, i) - sum1 - sum2) / gsl_matrix_get(A, i, i);
            gsl_vector_set(x, i, result);
        }
        x_prev = copy_vector(x);
    }

    return x;
}

int main(int argc, const char *argv[]) {
    scanf("%d", &N);
       
    Vector b = init_vector();
    load_vector(b);

    Matrix A = init_matrix();
    load_matrix(A);

    Vector result = gauss_seidel(A, b);
    print_vector(result);
}
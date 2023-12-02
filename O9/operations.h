#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <gsl/gsl_block.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_blas.h>
#include <math.h>

typedef gsl_block * Block ;
typedef gsl_vector * Vector;
typedef gsl_matrix * Matrix;
int N;

Vector init_vector() {
    return gsl_vector_calloc(N);
}

void load_vector(Vector x) {
    gsl_vector_fscanf(stdin, x);
}

void print_vector(Vector x) {
    gsl_vector_fprintf(stdout, x, "%.15lf");
}

Matrix init_matrix() {
    return gsl_matrix_calloc(N, N);
}

void load_matrix(Matrix A) {
    gsl_matrix_fscanf(stdin, A);
}

void print_matrix(Matrix A) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf("%lf ", gsl_matrix_get(A, i, j));
        }
        printf("\n");
    }
}

double dot_product(Vector a, Vector b) {
    double result;
    gsl_blas_ddot(a, b, &result);

    return result; 
}

double norm(Vector a) {
    double result;
    gsl_blas_ddot(a, a, &result);
    result = sqrt(result);

    return result;
}

Vector copy_vector(Vector a) {
    Vector result = init_vector();
    gsl_vector_memcpy(result, a);

    return result;
}

Vector matrix_vector_product(Matrix A, Vector x) {
    Vector result = init_vector();
    gsl_blas_dgemv(CblasNoTrans, 1.0, A, x, 0.0, result);

    return result;
}

void scale(Vector A, double a) {
    gsl_vector_scale(A, a);
}

Vector add(Vector a, Vector b) {
    gsl_vector_add(a, b);
    return a;
}

Vector sub(Vector a, Vector b) {
    gsl_vector_sub(a, b);
    return a;
}

#endif // OPERATIONS_H
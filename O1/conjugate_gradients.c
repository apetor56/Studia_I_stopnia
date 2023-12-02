#include "operations.h"

Vector conjugate_gradients(Matrix A, Vector b) {
    Vector x = init_vector();
    Vector Ax = init_vector();
    Ax = matrix_vector_product(A, x);
    
    Vector r = copy_vector(b);
    r = sub(r, Ax);
    
    Vector p = copy_vector(r);

    double alpha = 0.0;
    double beta = 0.0;
    double epsilon = 1e-10;
  
    double r_norm = norm(r);
    while(r_norm > epsilon) {
        double dot_product_rr = dot_product(r, r);

        Vector Ap = init_vector();
        Ap = matrix_vector_product(A, p);
        double dot_product_pAp = dot_product(p, Ap);
        alpha = dot_product_rr / dot_product_pAp;

        Vector r2 = copy_vector(r);
        scale(Ap, alpha);
        r2 = sub(r2, Ap);

        double dot_product_r2r2 = dot_product(r2, r2);
        beta = dot_product_r2r2 / dot_product_rr;

        Vector tmp1 = copy_vector(p);
        Vector tmp2 = copy_vector(p);
        scale(tmp1, alpha);
        scale(tmp2, beta);

        Vector p2 = copy_vector(r2);
        p2 = add(p2, tmp2);
        x = add(x, tmp1);

        p = copy_vector(p2);
        r = copy_vector(r2);
        r_norm = norm(r);
    }

    return x;
}

int main(int argc, const char *argv[]) {
    scanf("%d", &N);

    Vector b = init_vector();
    load_vector(b);
    
    Matrix A = init_matrix();
    load_matrix(A);

    Vector result = conjugate_gradients(A, b);
    print_vector(result);
}
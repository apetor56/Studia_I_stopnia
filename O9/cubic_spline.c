#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int N;
double *_x;
double *_f;
double *_eps;

double A(int j, double x) {
    return (_x[j + 1] - x) / (_x[j + 1] - _x[j]); 
}

double B(int j, double x) {
    return (x - _x[j]) / (_x[j + 1] - _x[j]);
}

double C(int j, double x) {
    double A3 = pow(A(j, x), 3);
    double x2 = pow(_x[j + 1] - _x[j], 2);

    return (1.0 / 6) * (A3 - A(j, x)) * x2;
}

double D(int j, double x) {
    double B3 = pow(B(j, x), 3);
    double x2 = pow(_x[j + 1] - _x[j], 2);

    return (1.0 / 6) * (B3 - B(j, x)) * x2;
}

void y() {
    double outcome = 0.0;

    for(int j = 0; j < N - 1; j++) {
        for(double X = _x[j]; X < _x[j + 1]; X += 0.00001) {
            outcome = A(j, X) * _f[j] + B(j, X) * _f[j + 1] + C(j, X) * _eps[j] + D(j, X) * _eps[j + 1];  
            printf("%.5lf %.15lf\n", X, outcome);
        }
    }
}

int main() {
    scanf("%d", &N);

    _x = (double*)malloc(N * sizeof(double));
    _f = (double*)malloc(N * sizeof(double));

    double h = 0.25;
    double beg = -7.0 / 8;

    for(int i = 0; i < N; i++) {
        _x[i] = beg;
        _f[i] = 1.0 / (1 + 5 * _x[i] * _x[i]);
        beg += h;
    }

    printf("\n");
    _eps = (double*)malloc(N * sizeof(double));
    for(int i = 0; i < N; i++) {
        scanf("%lf", _eps + i);
    }

    y();

    free(_x);
    free(_f);
    free(_eps);
}
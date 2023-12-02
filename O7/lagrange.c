#include <stdio.h>
#include <stdlib.h>

int n;
double *x;      // knots
double *f;      // values of function 
double *a;      // factors

double lj(int j, double _x) {
    double result = 1.0;

    for(int i = 0; i < n; i++) {
        if(i == j)
            continue;
        
        result *= (_x - x[i]) / (x[j] - x[i]);
    }
    return result;
}

double fj(int j, int k) {
    if(k == 0)
        return f[j];
    
    return (fj(j, k - 1) - a[k - 1]) / x[j];
}

double sinc_function(double x) {
    double result = 0.0;
    for(int j = 0; j < n; j++) {
        result += lj(j, x) * f[j];
    }

    return result;
}

void factors() {
    for(int k = 0; k < n; k++)
        for(int j = 0; j < n; j++) {
            a[k] += lj(j, 0) * fj(j, k); 
        }
}

int main() {
    scanf("%d", &n);

    x = (double *)malloc(n * sizeof(double));
    f = (double *)malloc(n * sizeof(double));
    a = (double *)malloc(n * sizeof(double));

    for(int i = 0; i < n; i++)
        scanf("%lf%lf", &x[i], &f[i]);

    FILE *plot = fopen("lagrange_plot.txt", "w");
    double _x = -1.0;
    while(_x <= 1.0) {
        fprintf(plot, "%lf %lf\n", _x, sinc_function(_x));
        _x += 0.001;
    }

    factors();
    FILE *factor = fopen("lagrange_factors.txt", "w");
    for(int i = n - 1; i >= 0; i--)
        fprintf(factor, "%.4lf\n", a[i]);

    free(x);
    free(f);
    free(a);
    fclose(plot);
    fclose(factor);
}
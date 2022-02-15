#include <stdio.h>
#include <stdlib.h>

double fun(double x) {
    return 1.0 / (1 + 5 * x * x);
}
int main(int argc, const char *argv[]) {
    if(argc != 2) {
        printf("Wrong number of arguments\nEnter martix size (one number)\n");
        exit(1);
    }

    int N = atoi(argv[1]);
    printf("%d\n\n", N);
 
    double beg = -7.0 / 8;
    double h = 0.25;

    for(int i = 0; i < N; i++) {
        printf("%lf %lf\n", beg, fun(beg));
        beg += h;
    }
}
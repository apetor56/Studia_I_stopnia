#include <stdio.h>
#include <float.h>

int main() {
    printf("max double\n%lf\n\n", DBL_MAX);

    double d = 2 * DBL_MAX;
    // if(!(d >= -DBL_MAX && d <= DBL_MAX)) {
    //     printf("liczba poza zakresem!\n");
    //     return -1;
    // }
    
    printf("max double * 2\n%lf\n\n", 2 * DBL_MAX);
    printf("max float\n%lf\n\n", FLT_MAX);
    printf("max float * 2\n%lf\n\n", 2 * FLT_MAX);
}
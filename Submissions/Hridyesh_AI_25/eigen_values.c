#include <stdio.h>
#include <math.h>
double determinant(double a, double b, double c, double d) {
    return a * d - b * c;
}
void EigenValues(double a, double b, double c, double d, double* lambda1, double* lambda2) {
    double trace = a + d;
    double det = determinant(a, b, c, d);
    double discriminant = sqrt(trace * trace - 4 * det);

    *lambda1 = (trace + discriminant) / 2;
    *lambda2 = (trace - discriminant) / 2;
}
void findEigenVector(double a, double b, double c, double d, double lambda, double* x, double* y) {
    if (b != 0) {
        *x = 1;
        *y = (lambda - a) / b;
    } else if (c != 0) {
        *x = (lambda - d) / c;
        *y = 1;
    } else {
        *x = 1;
        *y = 0;
    }
}

int main() {
    double a, b, c, d;
    printf("Enter the elements of the 2x2 matrix (a, b, c, d):\n");
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);

    double lambda1, lambda2;
    findEigenValues(a, b, c, d, &lambda1, &lambda2);

    printf("Eigenvalues: \n");
    printf("Lambda 1: %lf\n", lambda1);
    printf("Lambda 2: %lf\n", lambda2);

    double x1, y1, x2, y2;
    findEigenVector(a, b, c, d, lambda1, &x1, &y1);
    findEigenVector(a, b, c, d, lambda2, &x2, &y2);

    printf("Eigenvector corresponding to Lambda 1: [%lf, %lf]\n", x1, y1);
    printf("Eigenvector corresponding to Lambda 2: [%lf, %lf]\n", x2, y2);

    return 0;
}

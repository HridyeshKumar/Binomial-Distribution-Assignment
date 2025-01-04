#include <stdio.h>
#include <math.h>
#define DIM 3
// sum w = u + v
void vectorSum(double u[], double v[], double w[])
{
  for (int i = 0; i < DIM; i++)
  {
    w[i] = u[i] + v[i];
  }
}
// dot product u . v
double dotProduct(double u[], double v[])
{
  double dot = 0;
  for (int i = 0; i < DIM; i++)
  {
    dot += u[i] * v[i];
  }
  return dot;
}
// cross product u x v (only for 3D vectors)
void crossProduct(double u[], double v[], double cross[])
{
  cross[0] = u[1] * v[2] - u[2] * v[1];
  cross[1] = u[2] * v[0] - u[0] * v[2];
  cross[2] = u[0] * v[1] - u[1] * v[0];
}
// magnitude of a vector
double magnitude(double vec[])
{
  double mag = 0;
  for (int i = 0; i < DIM; i++)
  {
    mag += vec[i] * vec[i];
  }
  return sqrt(mag);
}
int main()
{
  double u[DIM], v[DIM], w[DIM], cross[DIM];
  double dot, magU, magV;
  printf("Enter the components of vector u (dimension %d):\n", DIM);
  for (int i = 0; i < DIM; i++)
  {
    scanf("%lf", &u[i]);
  }
  printf("Enter the components of vector v (dimension %d):\n", DIM);
  for (int i = 0; i < DIM; i++)
  {
    scanf("%lf", &v[i]);
  }
  vectorSum(u, v, w);
  dot = dotProduct(u, v);
  if (DIM == 3)
  {
    crossProduct(u, v, cross);
  }
  magU = magnitude(u);
  magV = magnitude(v);
  printf("\nResults:\n");
  printf("Sum of u and v (w = u + v):\n");
  for (int i = 0; i < DIM; i++)
  {
    printf("w[%d] = %0.2lf\n", i, w[i]);
  }
  printf("\nDot product u . v = %0.2lf\n", dot);
  if (DIM == 3)
  {
    printf("\nCross product u x v:\n");
    for (int i = 0; i < DIM; i++)
    {
      printf("cross[%d] = %0.2lf\n", i, cross[i]);
    }
  }
  printf("\nMagnitude of vector u = %0.2lf\n", magU);
  printf("Magnitude of vector v = %0.2lf\n", magV);
  return 0;
}

#include <stdio.h>
#define N 3
// Function to perform the Gauss-Jordan elimination
void gaussJordan(double a[N][N + 1])
{
  int i, j, k;
  double ratio;
  for (i = 0; i < N; i++)
  {
    // Making the diagonal element 1
    for (j = 0; j < N; j++)
    {
      if (i != j)
      {
        ratio = a[j][i] / a[i][i];
        for (k = 0; k < N + 1; k++)
        {
          a[j][k] -= ratio * a[i][k];
        }
      }
    }
  }
  for (i = 0; i < N; i++)
  {
    a[i][N] /= a[i][i];
  }
  printf("\nSolution:\n");
  for (i = 0; i < N; i++)
  {
    printf("x%d = %0.2lf\n", i + 1, a[i][N]);
  }
}
int main()
{
  double a[N][N + 1];
  int i, j;
  printf("Enter the coefficients of the system:\n");
  for (i = 0; i < N; i++)
  {
    for (j = 0; j < N + 1; j++)
    {
      scanf("%lf", &a[i][j]);
    }
  }
  gaussJordan(a);
  return 0;
}

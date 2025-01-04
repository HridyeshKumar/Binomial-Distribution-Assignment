#include <stdio.h>
#define N 3
int computeTrace(int matrix[N][N])
{
  int trace = 0;
  for (int i = 0; i < N; i++)
  {
    trace += matrix[i][i];
  }
  return trace;
}
int main()
{
  int matrix[N][N];
  printf("Enter the elements of the %dx%d matrix:\n", N, N);
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      scanf("%d", &matrix[i][j]);
    }
  }
  int trace = computeTrace(matrix);
  printf("The trace of the matrix is: %d\n", trace);
  return 0;
}

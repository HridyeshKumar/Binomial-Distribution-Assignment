#include <stdio.h>
double calculateMean(double data[], int n)
{
  double sum = 0.0;
  for (int i = 0; i < n; ++i)
  {
    sum += data[i];
  }
  return sum / n;
}
int main()
{
  int n;
  printf("Enter the number of elements: ");
  scanf("%d", &n);
  double data[n];
  printf("Enter the elements: ");
  for (int i = 0; i < n; ++i)
  {
    scanf("%lf", &data[i]);
  }
  printf("Mean = %.6lf\n", calculateMean(data, n));
  return 0;
}

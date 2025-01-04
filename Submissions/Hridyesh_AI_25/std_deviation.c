#include <stdio.h>
#include <math.h>
double calculateSD(double data[], int n)
{
  double sum = 0.0, mean, standardDeviation = 0.0;
  for (int i = 0; i < n; ++i)
  {
    sum += data[i];
  }
  mean = sum / n;
  for (int i = 0; i < n; ++i)
  {
    standardDeviation += pow(data[i] - mean, 2);
  }
  return sqrt(standardDeviation / n);
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
  printf("Standard Deviation = %.6lf\n", calculateSD(data, n));
  return 0;
}

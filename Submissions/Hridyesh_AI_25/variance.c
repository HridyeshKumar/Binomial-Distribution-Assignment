#include <stdio.h>
#include <math.h>
double calculate_mean(double data[], int n)
{
  double sum = 0.0;
  for (int i = 0; i < n; i++)
  {
    sum += data[i];
  }
  return sum / n;
}
double calculate_variance(double data[], int n)
{
  double mean = calculate_mean(data, n);
  double variance = 0.0;
  for (int i = 0; i < n; i++)
  {
    variance += pow(data[i] - mean, 2);
  }
  return variance / n;
}
int main()
{
  int n;
  printf("Enter the number of elements: ");
  scanf("%d", &n);
  double data[n];
  printf("Enter the elements:\n");
  for (int i = 0; i < n; i++)
  {
    scanf("%lf", &data[i]);
  }
  double variance = calculate_variance(data, n);
  printf("Variance = %.3f\n", variance);
  return 0;
}

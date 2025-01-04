#include <stdio.h>
double bayes_theorem(double p_b_given_a, double p_a, double p_b)
{
  return (p_b_given_a * p_a) / p_b;
}
int main()
{
  double p_b_given_a = 0.8; // P(B|A)
  double p_a = 0.4;         // P(A)
  double p_b = 0.5;         // P(B)
  // Calculate P(A|B) using Bayes' Theorem
  double p_a_given_b = bayes_theorem(p_b_given_a, p_a, p_b);
  printf("P(A|B) = %.3f\n", p_a_given_b);
  return 0;
}

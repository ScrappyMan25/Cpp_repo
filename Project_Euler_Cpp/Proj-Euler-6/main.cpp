/*
The sum of the squares of the first ten natural numbers is, 385

The square of the sum of the first ten natural numbers is, 3025

Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/

/*
Logic:
First sum of n natural numbers can be given by:
n(n+1)/2
Similarly Sum of square of n natural numbers is given by:
sum sq = (2n + 1)(n + 1)n/6

Source: https://brilliant.org/wiki/sum-of-n-n2-or-n3/
*/

#include <iostream>

int main() {
  int n = 100;
  long sum = n*(n+1)/2;
  long sq_sum = sum * sum;
  long sum_sq = (2*n + 1)*(n + 1)*n/6;

  std::cout << sq_sum - sum_sq << std::endl;
}
/*
Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:

1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...

By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.
*/

#include <iostream>

int main() {
  int limit = 4000000;
  int a = 1;
  int b = 1;
  int t = a+b;
  int sum = 0;

  while(t < limit){
    sum += t;
    a = t+b;
    b = t + a;
    t = a + b;
  }//Logic: Every 3rd Digit in the sequense is Even.
  
  std::cout<< sum << std::endl;
}
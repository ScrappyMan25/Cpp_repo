/*
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
*/

#include <iostream>

bool isPrime(long);

int main() {
  long n = 600851475143;
  long factor = 2;
  long lastFactor = factor;

//Since 2 is the only even prime number we will eliminate it and then we can increment our factors by 2 starting at 1.
  if(n % factor == 0){
    while(n % factor == 0){
      n /= factor;
    }
  }
  factor = 3;

  while(n>1){
    if(n % factor == 0){
      while(n % factor == 0)
        n /= factor;
    }
    factor += 2;
  }
  factor -= 2; // extre + 2 from while

  std::cout << factor << std::endl;
  
  return 0;
}
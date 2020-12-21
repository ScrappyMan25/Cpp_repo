/*
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?

Logic - Brute force - Simple optimisation - 2 is only even prime no.
*/

#include <iostream>

bool isPrime(long a);

int main() {
  int count = 1;
  int lim = 101;
  long p_number = 1;

  while(count != lim){
    p_number += 2;
    if(isPrime(p_number)){
      count++;
      std::cout << "Index: " << count << "\tPrime No: " << p_number << std::endl;
    }
  }

  std::cout << "10001's Prime Number is : " << p_number << std::endl;

  return 0;
}


bool isPrime(long a){
  if(a < 2){
    return false;
  }
  if (a == 2){
    return true;
  }
  //after checking for a factor x - the numbre cannot be x times itself hence he should be able to divide limit by x and add one (int floors)
  for(int x = 2; x < (a/x) + 1; x++){
    if(a%x == 0){
      return false;
    }
  }
  return true;
}
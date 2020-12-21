/*
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.
*/
#include <iostream>

long lim = 2000000;
bool isPrime(long a);

int main() {
  long sum = 0;
  
  for(long i = lim; i > 1; i--){
    if(isPrime(i)){
      sum += i;
    }
  }

  std::cout << "Sum of all prime numbers till 2000000 is " << sum << std::endl;
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
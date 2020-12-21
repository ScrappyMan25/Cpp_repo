/*
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

//Logic
/*
First i multiple all the prime numbers between the limits (1-20)

Then i check divisibility between all numbers between 1-20. And e3verytime some number is non divisable. i multiply the number with the lowest PRIME factor and check again. 
*/

#include <iostream>

bool isPrime(int a);
long largestNumber(long n); // Multiples Lowest Prime Factor for non divisable number b/wn 1- Limit
int limit = 20;

int main() {

  //test IsPrime
  /*
  for(int i = 0; i<= 10; i++){
    std::cout << "isPrime(" << i << ") : " << isPrime(i) << std::endl;
  }
  */
  long num = 2;
  long last = 2;
  
  //First multiple all prime no.s <= 20 || Limit
  for(int i = 1; i <= limit; i+=2){
    if(isPrime(i) == true){
      num *= i;
    }
  }

  //Test with each Number and multiply Lowest Factor
  while(num != last){
    last = num;
    num = largestNumber(num);
  }

  std::cout << num << std::endl;

  return 0;
}

bool isPrime(int a){
  if(a == 0 || a == 1){
    return false;
  }
  if (a == 2){
    return true;
  }
  for(int x = 2; x < a; x++){
    if(a%x == 0){
      return false;
    }
  }
  return true;
}

long largestNumber(long n){
  for(int a = 1; a<=limit; a++){
    if(n%a != 0){
      for(int b = 1; b<a; b++){
        if(isPrime(b) && a%b == 0){
          n *=b;
          return n;
        }
      }
    }
  }
  return n;
}
/*
*PE 1 
*
*If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
*
*Find the sum of all the multiples of 3 or 5 below 1000.
*/

#include <iostream>
#include <math.h>

int projE1();
int sumOf_divisible_till(int ,int);

int main() {
  
  int limit = 999;
  int op = sumOf_divisible_till(5, limit) + sumOf_divisible_till(3, limit) - sumOf_divisible_till(15, limit);//Sum of numbers divisible by 5 + divisible by 3 - divisible by 5 and 3; 
  std::cout << op << std::endl;

 return 0;
}

//first itteration
int projE1(){
  int sum = 0;
  int limit = 1000;

  for(int i = 0; i < limit; ++i){
    if(i%3 == 0 || i%5 ==0)
      sum += i;
  }
  return sum;
}

//second itteration
int sumOf_divisible_till(int a, int lim){
  int n; // sum = 0;
  n = floor(lim/a);

  //https://projecteuler.net/overview=001
  
  return a * (n*(n+1)) * 0.5; // Infinite series 
}
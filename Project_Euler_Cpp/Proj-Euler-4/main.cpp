/*
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include <iostream>

long reverse(long n); //Function to reverse any number
bool isPalindrome(long n); //Function returning if number is a palindrome.

int main() {
  //test reverse
  std::cout << "Reverse of 1002 : " << reverse(1002) << std::endl;
  
  //test isPalindrome
  std::cout << "isPalindrome 1002 : " << isPalindrome(1002) << std::endl;
  std::cout << "isPalindrome 1001 : " << isPalindrome(1001) << std::endl;

  long largestPal = 0;
  long a = 999;
  long b = 999;
  long limit = 100;

  while(a >= limit){
    b = a;
    while(b >= limit){
      if(isPalindrome( a*b ) == 1 && (a*b > largestPal)){
        largestPal = a*b;
      }
      b--;
    }
    a--;
  } 

  std::cout << "Largest Palindrome: " << largestPal << std::endl; 

  return 0;
}

//Function to reverse any number
long reverse(long n){
  long reversed = 0;
  while(n > 0){
    reversed = 10*reversed + n % 10;
    n /= 10;
  }
  return reversed;
}

bool isPalindrome(long n){
  return (n == reverse(n));
}
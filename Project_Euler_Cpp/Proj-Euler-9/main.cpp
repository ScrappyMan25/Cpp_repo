/*
A Pythagorean triplet is a set of three natural numbers, a < b < c, for which, a2 + b2 = c2

For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
*/

/*
To do : 
Find more efficient algo
Make 3 nested 4 to 2 first.
*/

#include <iostream>
#include <cmath>

int lim = 1000;
long find_triplet_product();

int main() {
  //probbably not ideal but i did it anyway. 
  
  std::cout << find_triplet_product() << std::endl;

  return 0;
}

long find_triplet_product(){
  for(int a = 1; a<lim; a++){
    for(int b = a+1; b<lim; b++){
      for(int c = b+1; c<lim; c++){
        if(pow(a,2) + pow(b,2) == pow(c,2)){
          if(a+b+c == lim){
            //std::cout << a*b*c << std::endl;
            return a*b*c;
          }
        }
      }
    }
  }
  return 0;
}
/* 
 * A solution with time complexity = O(1) by using some mathematical properties of Fibo numbers
 * More info: https://en.wikipedia.org/wiki/Fibonacci_number
 * */

#include <stdio.h> 
#include <math.h> 
#include <iostream>
#include <string>

const double phi = (1 + sqrt(5)) / 2;

int  getFibo(int n) {
    return floor((pow(phi, n) - pow(-phi, -n)) / (2 * phi - 1));
}

int main ()
{
  int input;
  
  std::cout << "Have an input:";
  std::cin >> input;
  
  /* Get the largest term value which is less than input*/ 
  int n = floor(log(input * sqrt(5) + 1/2) / log(phi));
  if (getFibo(n) > input) {
      n = n - 1;
  }
  
  /*A treament when n is not divisible by 3*/
  int addition = 0; 
  if (n % 3 == 2) {
      n = n + 1;
  }
  
  if (n % 3 == 1) {
      addition = getFibo(n);
      n = n - 1;
  }
  
  /* When n is divisible by 3, the sum of odd values is equal to the sum of even values and equal to F(n+2)/2 */
  int result = getFibo(n + 2) / 2 + addition - 1;
    
  std::cout << "The sum of odd fibo values less than "<< input << " is : "<< result << std::endl;
  
  return 0;
}

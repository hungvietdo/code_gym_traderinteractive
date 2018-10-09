#include <iostream>
#include <string>
#include <math.h>       /* pow */

int main()
{
    int result = 0;
    for (int i = 2; i < 6*pow(9,5); i++) { 
        
        int sumOfPowers = 0; 
        int number = i; 
        
        while (number > 0) {
            int d = number % 10;
            number = number / 10;

            sumOfPowers = sumOfPowers + pow(d, 5);
        }
    
        if (sumOfPowers == i) {
            result += i;
        }
    }

    std::cout << result;
}


#include <iostream>
#include <math.h>       /* pow */
using namespace std;

bool check_palindrome(long n);

int main()
{
    int num;
    cout << "Enter number of digits: ";
    cin >> num;

    long first_number = pow(10,num) - 1;
    long second_number = first_number/9;

    long maxj=second_number;

    long largest_palindrome = 0;
    long i,j;

    for (i=first_number; i>second_number;i--)
        for (j=i;j>maxj;j--) {
            if (check_palindrome(i*j)) {
                if (i*j > largest_palindrome) {
                    maxj=j;
                    largest_palindrome = i*j;
                    cout << largest_palindrome << " : is the current max palindrome with ";
                    cout << "(i,j) are " << i << " and " << j << endl;
                }
            }
        }

    return 0;
}

bool check_palindrome(long num) {
    long n = num;
    long rev = 0;
    long digit;
    do
     {
         digit = num % 10;
         rev = (rev * 10) + digit;
         num = num / 10;
     } while (num != 0);
    
    return n == rev;
}
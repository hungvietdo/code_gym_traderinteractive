#include <iostream>
using namespace std;

bool check_palindrome(int n);

int main()
{
    int number = 99999;
    int maxj=11111;

    int max = 0;
    int i,j;
    
    for (i=99999; i>11111;i--)
        for (j=i;j>maxj;j--) {
            
            if (check_palindrome(i*j)) {
                if (i*j > max) {
                    maxj=j;
                    max = i*j;
                    cout << max << " : is the current max palindrome with ";
                    cout << "(i,j) are " << i << " and " << j << endl;
                }
            }
        }

    return 0;
}

bool check_palindrome(int num) {
    int n = num;
    int rev = 0;
    int digit;
    do
     {
         digit = num % 10;
         rev = (rev * 10) + digit;
         num = num / 10;
     } while (num != 0);
    
    return n == rev;
}
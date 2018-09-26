#include <iostream>       // std::cout
#include <bitset>         // std::bitset
#include <math.h>         

std::bitset<10000000> list;
int size = 10000000;
  
bool isLeftTruncatable(long x) {
    do { 
        if(list[x]) return false; 
        x = x % (long) pow(10, (long) log10(x));
    } while (x>0);

    return true;
}
bool isRightTruncatable(long x) {
    do {
        if(list[x]) return false;
        x = x / 10;
    } while (x > 0);

    return true;
}

int main ()
{
    list.set(1,1); // 1 is not a prime number
    
    // List of primes
    for(long i=2; i<size/2+2; i++) {
        for(long j=2; i*j<size; j++) {
            list.set(j*i, 1);
        }
    }

    long long sum=0;
    int count=0;
    long i = 10;
    int stopCount = 11;

    do {
        i++;
        if(!isLeftTruncatable(i)) continue;
        if(!isRightTruncatable(i)) continue;

        sum+=i;
        count++;
    } while (count < stopCount);
    
    std::cout << sum;
    return 0;
}

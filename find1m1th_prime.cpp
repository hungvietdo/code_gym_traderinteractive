//Sandbox link: http://cpp.sh/6w6er
#include <vector>
#include <boost/dynamic_bitset.hpp>
#include <cmath>
#include <limits>
#include <iostream>

//https://en.wikipedia.org/wiki/Sieve_of_Sundaram
boost::dynamic_bitset<> sieve_of_sundaram(long n)
{
    const long m = n/2 ;
    boost::dynamic_bitset<> sieve(m);
    sieve.flip(); //set all the bits to true

    for( long i = 1; i < m; ++i)
    {
        const long l = (m-i)/(2*i + 1);
        for( long j = i; j <= l; ++j) {
            sieve[i + j + 2*i*j] = false;
        }
    }

    return sieve;
}

int nth_prime_number( long n )
{
    int number = 2 ;
    double ubound = n * std::log(n) * 1.5;
    auto sieve = sieve_of_sundaram(ubound);
    long pos = 1 ;
    for( long i = 1; n > 1 ; ++i) {
        if(sieve[i]) {
            pos = i; 
            --n;
        }
    }
    number = pos * 2 + 1;
    return number ;
}

int main()
{
    std::cout << nth_prime_number(1000001) << '\n' ;
}
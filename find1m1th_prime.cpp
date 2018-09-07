/*
    Sandbox link: http://cpp.sh/6w6er
    https://en.wikipedia.org/wiki/Sieve_of_Sundaram
*/

#include <boost/dynamic_bitset.hpp>
#include <cmath>
#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

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

/*
    Prime:  3, 5, 7, 9, 11, 13, 17, 19, 23, 29, 31
    Pos:    1, 2, 3, 4,  5,  6,  7,  8,  9, 10, 11
*/

TEST (primeNum, primeNum) {
    ASSERT_THAT (17, nth_prime_number(7));
    ASSERT_THAT (29, nth_prime_number(10));
    ASSERT_THAT (31, nth_prime_number(11));
    ASSERT_THAT (15485867, nth_prime_number(1000001)); //result
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
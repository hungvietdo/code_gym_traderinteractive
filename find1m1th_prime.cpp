/*
    Sandbox link: http://cpp.sh/6ggs3
    https://en.wikipedia.org/wiki/Sieve_of_Sundaram

    Any composite odd integers (non-prime) can be written as q = (2i + 1)(2j + 1)
    => q = 2(i + j + 2ij) + 1

    Thus, sieve_of_sundaram is a list of numbers from 1..n excluding any numbers in the form of [i + j + 2ij]
    Example: 11101101101001100 has positions at 4, 7, 10, 12, 13, 16, 17 marked as zero since they are equal i + j + 2ij
*/

#include <boost/dynamic_bitset.hpp>
#include <cmath>
#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

boost::dynamic_bitset<> sieve_of_sundaram(long upperbound)
{
    const long m = upperbound/2 ;
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

int nth_prime_number(long n)
{
    // https://math.stackexchange.com/questions/1270814/bounds-for-n-th-prime
    double upperbound = n * (log(n) + log(log(n)));

    auto sieve = sieve_of_sundaram(upperbound);

    long pos = 0;
    long num_count = 0;
    while (num_count < n - 1) {
        pos++;
        if(sieve[pos]) {
            num_count++;
        }
    }
    return (pos * 2) + 1;
}

/*
    Prime:      3, 5, 7, 9, 11, 13, 17, 19, 23, 29, 31
    Position:   1, 2, 3, 4,  5,  6,  7,  8,  9, 10, 11
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
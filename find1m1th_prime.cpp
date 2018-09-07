#include <vector>
#include <boost/dynamic_bitset.hpp>
#include <cmath>
#include <limits>
#include <iostream>

boost::dynamic_bitset<> sieve_of_sundaram(long N )
{
    const long M = N / 2 ;
    boost::dynamic_bitset<> sieve(M) ;
    sieve.flip() ;

    for( long i = 1 ; i < M ; ++i )
    {
        const long L = (M-i) / ( 2*i + 1 ) ;
        for( long j = i ; j <= L ; ++j ) sieve[ i + j + 2*i*j ] = false ;
    }

    return sieve ;
}

int nth_prime_number( long n )
{
    int number = 2 ;
    if( n > 1 )
    {
        double ubound = std::max( 100.0, n * std::log(n) * 1.5 ) ;
        auto sieve = sieve_of_sundaram(ubound) ;
        long pos = 1 ;
        for( long i = pos ; n > 1 ; ++i ) if( sieve[i] ) { pos = i ; --n ; }
        number = pos * 2 + 1 ;
    }

    return number ;
}

int main()
{
    std::cout << nth_prime_number(1000001) << '\n' ;
}
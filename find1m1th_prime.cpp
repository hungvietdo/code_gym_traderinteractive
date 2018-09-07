#include <vector>
#include <boost/dynamic_bitset.hpp>
#include <cmath>
#include <limits>
#include <cmath>
#include <iostream>

boost::dynamic_bitset<> sieve_of_sundaram( std::size_t N )
{
    const std::size_t M = N / 2 ;
    boost::dynamic_bitset<> sieve(M) ;
    sieve.flip() ;

    for( std::size_t i = 1 ; i < M ; ++i )
    {
        const std::size_t L = (M-i) / ( 2*i + 1 ) ;
        for( std::size_t j = i ; j <= L ; ++j ) sieve[ i + j + 2*i*j ] = false ;
    }

    return sieve ;
}

int nth_prime_number( std::size_t n )
{
    int number = 2 ;
    if( n > 1 )
    {
        // the nth prime number is approximately equal to n * log(n)
        double ubound = std::max( 100.0, n * std::log(n) * 1.5 ) ;
        assert( ubound < std::numeric_limits<std::size_t>::max() ) ;
        auto sieve = sieve_of_sundaram(ubound) ;
        std::size_t pos = 1 ;
        for( std::size_t i = pos ; n > 1 ; ++i ) if( sieve[i] ) { pos = i ; --n ; }
        assert( pos < std::numeric_limits<int>::max() / 2 ) ;
        number = pos * 2 + 1 ;
    }

    return number ;
}

int main()
{
    for( std::size_t n = 100 ; n < 1500000 ; n *= 10 )
        std::cout << n+1 << ": " << nth_prime_number(n+1) << '\n' ;
}
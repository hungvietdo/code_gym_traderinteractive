#include <math.h>
#include <iostream>

int main()
{
	long n = 778118621513;
	
	for (int i = 3; i <= sqrt(n); i += 2) {
		while (n % i == 0) {
    			n = n / i;
    		}
	}
	
	std::cout << "The largest prime factor of the number 778118621513 is:" << n << "\n";

	return 0;
}


#include <math.h> 
#include <iostream>

const double phi = (1 + sqrt(5))/2;

double getTermByDigits(long Digits) {
    return ceil((Digits + log10(5)/2)/log10(phi));
}

int main ()
{
    std::cout << getTermByDigits(9999);
    return 0;
}

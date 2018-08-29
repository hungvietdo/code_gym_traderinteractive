#include "gtest/gtest.h"
#include<math.h>
using namespace std;

long long calculation(int input);
int relativePrime;

TEST(test, simpleTests) { 
    EXPECT_EQ (2520, calculation (10));
    EXPECT_EQ (2 * 2 * 3 * 5, calculation (5));
    EXPECT_EQ (2 * 2 * 2 * 3 * 3 * 5 * 7, calculation (9));
}

TEST(test, complexTest) {
    std::string str = std::to_string(calculation(25));
    const char * c = str.c_str();
    EXPECT_STREQ (c, "26771144400");
}
 
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

long long calculation(int input) {
    long long result = 1;
    
    for (int i = 1; i <= input; i++){
       if (result % i == 0) continue;
       relativePrime = i;
       while (relativePrime * i <= input) relativePrime *= i;
       result = result * relativePrime;
    }
 
    return result;
}

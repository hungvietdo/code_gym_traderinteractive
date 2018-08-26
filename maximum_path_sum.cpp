//An interesting practice with google unit test
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include<math.h>
#include <fstream>
using::testing::_;
using namespace std;

std::vector<int> inputVector, resultVector;

int lastPosition = 0;

int getRow(int position);
int getLeftBelow(int position);
int getRightBelow(int position);
void readNumbersFromTextFile(string fileName);
void calculateResult();

TEST (generaTest, generaTest) {
    ASSERT_THAT (1, getRow(1));
    ASSERT_THAT (3, getRow(5));
    ASSERT_THAT (4, getRow(7));
    ASSERT_THAT (4, getRow(10));
    ASSERT_THAT (5, getRow(11));

    ASSERT_THAT (11, getLeftBelow(7));
    ASSERT_THAT (12, getRightBelow(7));
    ASSERT_THAT (14, getLeftBelow(10));
    ASSERT_THAT (15, getRightBelow(10));
}

TEST (fistTest, fistTest) {
    ASSERT_THAT (inputVector[1], 98);
    ASSERT_THAT (inputVector[2], 39);
    ASSERT_THAT (inputVector[10], 94);
    ASSERT_THAT (94, resultVector[10]);
    ASSERT_THAT (48, resultVector[7]);
    ASSERT_THAT (163, resultVector[6]);
    ASSERT_THAT (293, resultVector[1]); //result
}

TEST (secondTest, secondTest) {
    ASSERT_THAT (96, inputVector[120]);
    ASSERT_THAT (93, inputVector[1]);
    ASSERT_THAT (lastPosition, 120);
    ASSERT_THAT (0, resultVector[200]);
    ASSERT_THAT (0, resultVector[121]);
    ASSERT_THAT (1067, resultVector[1]); //result
}

TEST (thirdTest, thirdTest) {
    ASSERT_THAT (10, inputVector[1]);
    ASSERT_THAT (82, inputVector[5050]);
    ASSERT_THAT (7109, resultVector[1]); //result
}

int main(int argc, char **argv) {
    readNumbersFromTextFile("numbers.txt");
    calculateResult();

    ::testing::InitGoogleTest(&argc, argv);

    //::testing::GTEST_FLAG(filter) = "generalTest*";
    //::testing::GTEST_FLAG(filter) = "firstTest*";
    //::testing::GTEST_FLAG(filter) = "secondTest*";
    ::testing::GTEST_FLAG(filter) = "thirdTest*";
    return RUN_ALL_TESTS();
}

void calculateResult() {
    int leftPos, rightPos;
    for (int i = lastPosition; i>0; i--) {
        leftPos = getLeftBelow(i);
        rightPos = getRightBelow(i);
        if (inputVector[i] + resultVector[leftPos] > inputVector[i] + resultVector[rightPos]) {
            resultVector[i] = inputVector[i] + resultVector[leftPos];
        } else {
            resultVector[i] = inputVector[i] + resultVector[rightPos];
        }
    }
}

int getRow(int position) {
    int n = 1;
    while ((n*(n+1)/2)<position) n++;
    return n;
}

int getLeftBelow(int position) {
    int n = getRow(position);
    return position + n;
}

int getRightBelow(int position) {
    int n = getRow(position);
    return position + n + 1;
}

void readNumbersFromTextFile(string fileName) {
    ifstream inputFile(fileName);
    
    inputVector.push_back(0);
    resultVector.push_back(0);

    if (inputFile) {        
        int value;
        // read the elements in the file into a vector  
        while ( inputFile >> value ) {
            inputVector.push_back(value);
            resultVector.push_back(0);
            lastPosition++;
        }
    }
    inputFile.close();
}

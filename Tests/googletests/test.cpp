#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;


TEST(TypeCastTest, IntToLong){

    // Ensuring you always get different random numbers.
    srand((unsigned) time(0));
    int randomNumber;
    // Running 10,000 tests
    for(int i = 0; i < 10000; i++){
        randomNumber = rand();
        EXPECT_EQ(randomNumber,(long)randomNumber);
    }

}

TEST(TypeCastTest, DoubleToFloatSquare){
    //Ensuring you always get different random numbers.
    srand((unsigned int) time(0));
    float a = 1000.0; // Does not work for a = 10,000.

    // Running 10,000 tests.
    for (int i=0;i<10000;i++){
        float randomFloat = (float(rand())/float((RAND_MAX)) * a);
        // Defining the error term
         double error = (double)abs(randomFloat*randomFloat - ((double)randomFloat *(double)randomFloat));
        // Setting error margin 0.1
        EXPECT_LE(error, 0.1);
    }
}

TEST(VectorTest, EqualityOfNullVectors){
    // Checking equality of Null Vectors.
    vector <int> v1,v2;
    EXPECT_EQ(v1,v2);
}

TEST(VectorTest, EqaulityOfVectors){
    vector <long> vector1,vector2,vector3;
    long temp;
    srand((unsigned int) time(0));
    // Populating vectors with 10,000 'long' type random numbers.
    for(int i = 0; i<10000;i++){
        temp = rand();
        vector1.push_back(temp);
        vector2.push_back(temp);
    }
    vector3 = vector1;
    EXPECT_EQ(vector1,vector2);
    EXPECT_EQ(vector2,vector3);
    EXPECT_EQ(vector3,vector1);
}

int main(int argc, char** argv){

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

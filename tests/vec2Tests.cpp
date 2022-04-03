#include "gtest/gtest.h"
#include "vec2.h"

TEST(vec2Tests, default_constructor)
{
    //Arrange
    vec2 testVec;

    //Act

    //Assert
    EXPECT_EQ(testVec.x, 0);
    EXPECT_EQ(testVec.y, 0);
}

TEST(vec2Tests, constructor)
{
    //Arrange
    vec2 testVec(5, 3);

    //Act

    //Assert
    EXPECT_EQ(testVec.x, 5);
    EXPECT_EQ(testVec.y, 3);
}

TEST(vec2Tests, change_values)
{
    //Arrange
    vec2 testVec(5, 3);

    //Act
    testVec.x = 6;
    testVec.y = 15;

    //Assert
    EXPECT_EQ(testVec.x, 6);
    EXPECT_EQ(testVec.y, 15);
}

TEST(vec2Tests, eq_operator)
{
    //Arrange
    vec2 testVec1(5, 3);
    vec2 testVec2(5, 3);

    //Act
    testVec1 = testVec2;

    //Assert
    EXPECT_EQ(testVec1.x, 5);
    EXPECT_EQ(testVec1.y, 3);
}

TEST(vec2Tests, comp_operator)
{
    //Arrange
    vec2 testVec1(5, 3);
    vec2 testVec2(5, 3);
    vec2 testVec3(8, 9);

    //Act

    //Assert
    EXPECT_TRUE(testVec1 == testVec2);
    EXPECT_FALSE(testVec1 == testVec3);
    EXPECT_FALSE(testVec2 == testVec3);
}

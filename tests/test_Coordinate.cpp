#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include//Coordinate.h"

//Check that coordinate constructor works
TEST(CoordinateTest, RegularTest) {
    Coordinate c(5, 7);
    EXPECT_EQ(c.getRow(),5);
    EXPECT_EQ(c.getCol(), 7);
}
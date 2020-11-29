#include "pch.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(TestCaseName, FailingTest)
{
    EXPECT_NE(1, 1);
    EXPECT_TRUE(false);
}
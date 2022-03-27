#include "gtest/gtest.h"

int main(int argc, char* argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(main, check_test)
{
  EXPECT_EQ(1, 1);
  EXPECT_NE('a', 'b');
  EXPECT_TRUE(true);
  EXPECT_FALSE(false);
  EXPECT_LT(500, 500.1);
  EXPECT_LE(144, 144);
  EXPECT_GT(4, 3);
  EXPECT_GE(11, 11);

  ASSERT_EQ(3.2, 3.2);
  ASSERT_NE(true, false);
  bool b1 = true;
  ASSERT_TRUE(b1);
  bool b2 = false;
  ASSERT_FALSE(b2);
}

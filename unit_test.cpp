#include "gtest/gtest.h"
#include "factory.hpp"
//////////////////////////kjsdjksdhjsdjkldbsbcbcvcbcbkjcvbj,ncv
//#include "op_test.hpp"
//#include "add_test.hpp"
//#include "mult_test.hpp"
//#include "rand_test.hpp"
//#include "sub_test.hpp"
//#include "div_test.hpp"
//#include "pow_test.hpp"
//#include "mix_test.hpp"
//#include "VectorContainer_test.hpp"
//#include "ListContainer_test.hpp"
//#include "SelectionSort_test.hpp"
//#include "BubbleSort_test.hpp"
#include "factory_test.hpp"
//TEST(OpTest, eight){
  // Op* op1 = new Op (8);
  // EXPECT_EQ(op1->stringify, "8");
  // EXPECT_EQ(op1->evaluate, 8);
//}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

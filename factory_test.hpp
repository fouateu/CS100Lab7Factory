#ifndef _FACTORY_TEST_HPP
#define _FACTORY_TEST_HPP

using namespace std;

#include "base.hpp"
#include "op.hpp"
#include "add.hpp"
#include "Sub.hpp"
#include "mult.hpp"
#include <iostream>
#include "Pow.hpp"
#include "Div.hpp"
#include "factory.hpp"

TEST(FactoryTest, SimpleAdd) {
    char* test_val[4]; test_val[0] = "./calculator"; test_val[1] = "3"; test_val[2] = "+" ; test_val[3] = "2";
    Factory* f = new Factory();
    Base* test = f->parse(test_val, 4);
    string resultS = test->stringify();
    double resultE = test->evaluate();
    EXPECT_EQ("3 + 2", resultS);
    EXPECT_EQ(5, resultE);
}

TEST(FactoryTest, SimpleDiv) {
    char* test_val[4]; test_val[0] = "./calculator"; test_val[1] = "20"; test_val[2] = "/" ; test_val[3] = "5";
    Factory* f = new Factory();
    Base* test = f->parse(test_val, 4);
    string resultS = test->stringify();
    double resultE = test->evaluate();
    EXPECT_EQ("20 / 5", resultS);
    EXPECT_EQ(4, resultE);
}

TEST(FactoryTest, SimpleAddAndSub) {
    char* test_val[6]; test_val[0] = "./calculator"; test_val[1] = "3"; test_val[2] = "+" ; test_val[3] = "2"; test_val[4] = "-"; test_val[5] = "5";
    Factory* f = new Factory();
    Base* test = f->parse(test_val, 6);
    string resultS = test->stringify();
    double resultE = test->evaluate();
    EXPECT_EQ("3 + 2 - 5", resultS);
    EXPECT_EQ(0, resultE);
}


TEST(FactoryTest, MultOfDecimal){
  char* test_val[4]; test_val[0] = "./calculator"; test_val[1] = "3.5"; test_val[2] = "\*" ; test_val[3] = "2";
  Factory* f = new Factory();
  Base* test = f->parse(test_val, 4);
  string resultS = test->stringify();
  double resultE = test->evaluate();
  EXPECT_EQ("3.5 * 2", resultS);
  EXPECT_EQ(7, resultE);
}

TEST(FactoryTest, SubOfMultipleDigitNumber){
  char* test_val[4]; test_val[0] = "./calculator"; test_val[1] = "1000"; test_val[2] = "-" ; test_val[3] = "250.25";
  Factory* f = new Factory();
  Base* test = f->parse(test_val, 4);
  string resultS = test->stringify();
  double resultE = test->evaluate();
  EXPECT_EQ("1000 - 250.25", resultS);
  EXPECT_EQ(749.75, resultE);
}

TEST(FactoryTest, PowOfZero){
  char* test_val[4]; test_val[0] = "./calculator"; test_val[1] = "0"; test_val[2] = "\**" ; test_val[3] = "3";
  Factory* f = new Factory();
  Base* test = f->parse(test_val, 4);
  string resultS = test->stringify();
  double resultE = test->evaluate();
  EXPECT_EQ("0 ** 3", resultS);
  EXPECT_EQ(0, resultE);
}

TEST(FactoryTest, SingleNumber){
  char* test_val[2]; test_val[0] = "./calculator"; test_val[1] = "5";
  Factory* f = new Factory();
  Base* test = f->parse(test_val, 2);
  string resultS = test->stringify();
  double resultE = test->evaluate();
  EXPECT_EQ("5", resultS);
  EXPECT_EQ(5, resultE);
}

TEST(FactoryTest, JunkInput){
  char* test_val[2]; test_val[0] = "./calculator"; test_val[1] = "asfdsadfsda";
  Factory* f = new Factory();
  Base* test = f->parse(test_val, 2);
  ASSERT_TRUE(test == nullptr);
  cout << "Invalid Input" << endl;
}


#endif

#include <iostream>
using namespace std;
#include <vector>
#include <list>


#include "Div.hpp"
#include "Pow.hpp"
#include "Sub.hpp"
#include "add.hpp"
#include "base.hpp"
#include "mult.hpp"
#include "op.hpp"
#include "rand.hpp"
#include "factory.hpp"



int main (int argv, char** argc){
  Factory* f = new Factory();

  Base* output = f->parse(argc, argv);

  if (output == nullptr){
    cout << "got nullptr!" << endl;
  }
  // for(int i = 1; i < argv; i++) {
  //       cout << argc[i] << endl;
  //   }

 else{
 cout << "My string is: " << output->stringify() << endl;
 cout << "My number is: " << output->evaluate() << endl;
}



return 0;
}

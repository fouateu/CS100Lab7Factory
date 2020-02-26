#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

#include "base.hpp"
#include <queue>
#include <stack>
#include <iostream>
#include <cstring>
#include <string>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "Div.hpp"
#include "Pow.hpp"
#include "Sub.hpp"
#include "add.hpp"
#include "base.hpp"
#include "mult.hpp"
#include "op.hpp"
#include "rand.hpp"


using namespace std;


class base;

class Factory {
    public:
      Factory(){ };
      Base* parse(char** input, int length){
        queue<char*> q;
        stack<char*> s;
        string a;
        for (int i = 1; i < length; ++i){
           a = static_cast<string>(input[i]);
          if (isdigit(a.at(0))){
            q.push(input[i]);
          }
          else if (a == "+" || a == "-" || a == "*" || a == "/" || a == "**"){
            while(!s.empty()){
              q.push(s.top());
              s.pop();
            }
            s.push(input[i]);
          }
          else{
            cout << "Invalid input" << endl;
            return nullptr;
          }
        }
        while(!s.empty()){
          q.push(s.top());
          s.pop();
        }
        queue<Base*> q2;
        Base* temp1;
        Base* temp2;
        Base* temp3;
        double temp4;
        while(!q.empty()){
          a = static_cast<string>(q.front());
          if (a == "+"){
           temp2 = q2.front();
           q2.pop();
           temp3 = q2.front();
           q2.pop();
           temp1 = new Add(temp2, temp3);
           q2.push(temp1);
           q.pop();
          }
          else if (a == "-"){
           temp2 = q2.front();
           q2.pop();
           temp3 = q2.front();
           q2.pop();
           temp1 = new Sub(temp2, temp3);
           q2.push(temp1);
           q.pop();
          }
          else if (a == "*"){
           temp2 = q2.front();
           q2.pop();
           temp3 = q2.front();
           q2.pop();
           temp1 = new Mult(temp2, temp3);
           q2.push(temp1);
           q.pop();
          }
          else if (a == "/"){
           temp2 = q2.front();
           q2.pop();
           temp3 = q2.front();
           q2.pop();
           temp1 = new Div(temp2, temp3);
           q2.push(temp1);
           q.pop();
          }
          else if (a == "**"){
           temp2 = q2.front();
           q2.pop();
           temp3 = q2.front();
           q2.pop();
           temp1 = new Pow(temp2, temp3);
           q2.push(temp1);
           q.pop();
          }
          else{
            temp4 = stod(a);
            temp1 = new Op(temp4);
            q.pop();
            q2.push(temp1);
          }

        }
        return q2.front();
      }
};

#endif

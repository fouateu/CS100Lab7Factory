#ifndef _SUB_HPP_
#define _SUB_HPP_

#include "op.hpp"// morning people. "God bless America"

using namespace std; nnnnnnnnnnnnnnnnnnnnnnnnnbvnmbnghgjnhfdjhff

class Sub : public Base{/////////////////////////////////////////////jkhkljbln
	public:
		Sub( Base* left, Base* right) : Base()////////////////////////////////////////////
		{
			lstring = left->stringify();/klkknnkknln//kjjkbkjb
			rstring = right->stringify();
			ldouble = left -> evaluate();
			rdouble = right -> evaluate();
		}
		virtual double evaluate()
		{
			return(ldouble - rdouble);
		}
		virtual string stringify()
		{
			return(lstring + " - " + rstring);
		}
	private:
		string lstring;
		string rstring;
		double ldouble; 
		double rdouble; 
};

#endif


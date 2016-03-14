//
// utility1.h
//
// This header file contains utility  functions
//

#ifndef __UTILITY1_H__
#define __UTILITY1_H__

#include <string>
#include <iostream>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string/case_conv.hpp>


using namespace std;
using namespace boost;

// Method to clear input buffer
void clearInputBuffer();
bool isInteger(string str);
bool isDouble(string str);
bool validateID(string id);
bool validateStaffType(string type);
bool validateCommercialType(string type);
bool validateResidentialType(string type);
bool validatePropertyType(string type);

class Comma_Numpunct : public std::numpunct<char>
{
   public:
      // Overidden functions to customise behaviour of numpunct
      virtual char do_thousands_sep();
      virtual string do_grouping() const;
};


#endif

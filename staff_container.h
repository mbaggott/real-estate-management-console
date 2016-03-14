#ifndef __STAFF_CONTAINER_H__
#define __STAFF_CONTAINER_H__

#include <iostream>
#include <map>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <boost/tr1/functional.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/tokenizer.hpp>
#include <boost/foreach.hpp>
#include <boost/algorithm/string/case_conv.hpp>
#include "staff.h"
#include "comparator_empid.h"
#include "sales_staff.h"
#include "rentals_staff.h"

using namespace std;
using namespace boost;

class StaffContainer {

   private:
      vector<Staff*> staff;
      string staffFilename;

   public:
      StaffContainer(); // Default constructor
      ~StaffContainer(); // Destructor
      void addStaff(Staff *staffInstance);
      bool removeStaff(string id);
      vector<Staff*>& getAllStaff();
      void showAllStaff();
      void setStaffFilename(string filename); // Setter
      string getStaffFilename() const; // Getter
      int getStaffSize() const; // Getter
      friend ifstream& operator>>(ifstream& infile, StaffContainer& container);
      void loadStaff(string file3, ifstream &infile); // File input
      friend ofstream& operator<<(ofstream& outfile, StaffContainer& container);
      void printStaff(ofstream& outfile, StaffContainer& container);

};


#endif
